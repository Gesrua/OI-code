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

const int N = 100100;

struct Seg {
#define ls (cur * 2)
#define rs (cur * 2 + 1)
#define cn T[cur]
#define ln T[cur * 2]
#define rn T[cur * 2 + 1]
    struct node {
        int l, r;
        int sum = 0, tag = 0;
        int len() { return r - l + 1; }
    } T[N * 4];
    void pushup(int cur) { cn.tag = 0, cn.sum = ln.sum + rn.sum; }
    void pushdown(int cur) {
        if (cn.tag == -1) ln.tag = rn.tag = -1, ln.sum = rn.sum = 0;
        if (cn.tag == 1)
            ln.tag = rn.tag = 1, ln.sum = ln.len(), rn.sum = rn.len();
        cn.tag = 0;
    }
    void build(int cur, int l, int r) {
        cn.l = l, cn.r = r;
        if (l == r) return;
        int mid = (l + r) / 2;
        build(ls, l, mid), build(rs, mid + 1, r);
    }
    int L, R;
    int _query(int cur) {
        if (L <= cn.l && cn.r <= R) return cn.sum;
        if (R < cn.l || cn.r < L) return 0;
        pushdown(cur);
        return _query(ls) + _query(rs);
    }
    void _add(int cur) {
        if (L <= cn.l && cn.r <= R) {
            cn.tag = 1;
            cn.sum = cn.len();
            return;
        }
        if (R < cn.l || cn.r < L) return;
        pushdown(cur);
        _add(ls), _add(rs);
        pushup(cur);
    }
    void _del(int cur) {
        if (L <= cn.l && cn.r <= R) {
            cn.tag = -1;
            cn.sum = 0;
            return;
        }
        if (R < cn.l || cn.r < L) return;
        pushdown(cur);
        _del(ls), _del(rs);
        pushup(cur);
    }
    void add(int l, int r) {
        L = l, R = r;
        _add(1);
    }
    void del(int l, int r) {
        L = l, R = r;
        _del(1);
    }
    int query(int l, int r) {
        L = l, R = r;
        return _query(1);
    }
} seg;

int fa[N], dep[N], son[N], siz[N], top[N], dfn[N];
std::vector<int> g[N];

void dfs1(int u) {
    siz[u] = 1;
    dep[u] = dep[fa[u]] + 1;
    for (auto v : g[u]) {
        dfs1(v);
        siz[u] += siz[v];
        if (siz[son[u]] < siz[v]) son[u] = v;
    }
}

int dfs_time = 1;

void dfs2(int u) {
    dfn[u] = dfs_time;
    ++dfs_time;
    if (son[fa[u]] == u)
        top[u] = top[fa[u]];
    else
        top[u] = u;
    if (!son[u]) return;
    dfs2(son[u]);
    for (auto v : g[u]) {
        if (v == son[u]) continue;
        dfs2(v);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n;
    cin >> n;
    rep(i, 2, n) {
        cin >> fa[i];
        fa[i]++;
        g[fa[i]].push_back(i);
    }
    dfs1(1);
    dfs2(1);
    int q;
    cin >> q;
    std::string s;
    int x;
    seg.build(1, 1, n);
    while (q--) {
        cin >> s >> x;
        ++x;
        if (s[0] == 'i') {
            int last = seg.query(1, n);
            while (x != 0) {
                seg.add(dfn[top[x]], dfn[x]);
                // cerr << top[x] << ' ' << x << ' ' << dfn[top[x]] << ' '
                //  << dfn[x] << endl;
                x = fa[top[x]];
            }
            // cerr << seg.query(1, n) << endl;
            cout << std::abs(seg.query(1, n) - last) << endl;
        } else {
            int last = seg.query(1, n);
            seg.del(dfn[x], dfn[x] + siz[x] - 1);
            // cerr << seg.query(1, n) << endl;
            cout << std::abs(seg.query(1, n) - last) << endl;
        }
    }
    return 0;
}
