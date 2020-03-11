#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int ui;

const int N = 100000;

int n, m, rt, p;

int val[N + 100], id[N + 100], rk[N + 100], fa[N + 100], siz[N + 100],
    top[N + 100], dep[N + 100], son[N + 100];

std::vector<int> g[N + 10];

void init() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n >> m >> rt >> p;
    rep(i, 1, n) cin >> val[i];
    rep(i, 2, n) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void dfs1(int cur) {
    siz[cur] = 1;
    for (auto v : g[cur]) {
        if (v == fa[cur]) continue;
        fa[v] = cur;
        dep[v] = dep[cur] + 1;
        dfs1(v);
        siz[cur] += siz[v];
        if (siz[v] > siz[son[cur]]) son[cur] = v;
    }
}

int cnt = 1;

void dfs2(int cur, int t) {
    rk[cnt] = cur;
    id[cur] = cnt++;
    top[cur] = t;
    if (!son[cur]) return;
    dfs2(son[cur], t);
    for (auto v : g[cur]) {
        if (v == fa[cur] || v == son[cur]) continue;
        dfs2(v, v);
    }
}

#define lson (cur << 1)
#define rson ((cur << 1) | 1)
#define mod(x) (x) %= p

struct Seg {
    struct node {
        int l, r;
        int s, tag;
        int dis() { return r - l + 1; }
    } T[N * 4];
    void pushup(int cur) { mod(T[cur].s = T[lson].s + T[rson].s); }
    void pushdown(int cur) {
        mod(T[lson].s += T[lson].dis() * T[cur].tag);
        mod(T[lson].tag += T[cur].tag);
        mod(T[rson].s += T[rson].dis() * T[cur].tag);
        mod(T[rson].tag += T[cur].tag);
        T[cur].tag = 0;
    }
    void build(int cur, int l, int r) {
        T[cur].l = l, T[cur].r = r;
        if (l == r) {
            T[cur].s = val[rk[l]];
            return;
        }
        int mid = (l + r) / 2;
        build(lson, l, mid);
        build(rson, mid + 1, r);
        pushup(cur);
    }
    int L, R, X;
    int query(int l, int r) {
        L = l, R = r;
        return _query(1);
    }
    int _query(int cur) {
        if (L <= T[cur].l && T[cur].r <= R) return T[cur].s;
        if (R < T[cur].l || T[cur].r < L || T[cur].l == T[cur].r) return 0;
        pushdown(cur);
        return (_query(lson) + _query(rson)) % p;
    }
    void add(int x, int l, int r) {
        X = x, L = l, R = r;
        _add(1);
    }
    void _add(int cur) {
        if (L <= T[cur].l && T[cur].r <= R) {
            mod(T[cur].tag += X);
            mod(T[cur].s += (X * T[cur].dis()) % p);
            return;
        }
        if (R < T[cur].l || T[cur].r < L || T[cur].l == T[cur].r) return;
        pushdown(cur);
        _add(lson), _add(rson);
        pushup(cur);
    }
} seg;

void build() {
    dep[rt] = 1;
    fa[rt] = 0;
    dfs1(rt);

    dfs2(rt, rt);

    seg.build(1, 1, n);
}

void solve() {
    int opt, x, y, z, ans;
    while (m--) {
        cin >> opt;
        switch (opt) {
            case 1:
                cin >> x >> y >> z;
                while (top[x] != top[y]) {
                    if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
                    seg.add(z, id[top[x]], id[x]);
                    x = fa[top[x]];
                }
                if (dep[x] > dep[y]) std::swap(x, y);
                seg.add(z, id[x], id[y]);
                break;
            case 2:
                cin >> x >> y;
                ans = 0;
                while (top[x] != top[y]) {
                    if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
                    mod(ans += seg.query(id[top[x]], id[x]));
                    x = fa[top[x]];
                }
                if (dep[x] > dep[y]) std::swap(x, y);
                mod(ans += seg.query(id[x], id[y]));
                cout << ans << endl;
                break;
            case 3:
                cin >> x >> z;
                seg.add(z, id[x], id[x] + siz[x] - 1);
                break;
            case 4:
                cin >> x;
                cout << seg.query(id[x], id[x] + siz[x] - 1) << endl;
                break;
        }
    }
}

int main() {
    init();
    build();
    solve();
    return 0;
}
