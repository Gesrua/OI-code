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

const int N = 300100;

std::vector<int> g[N];

int n, m, dfn[N], dep[N], db[20][N], rev[N], siz[N], st[20][N];

struct H {
    int seq, num, ans;
} h[N];

inline int up_dep(int u, int delta) {
    if (delta <= 0) return u;
    per(i, 19, 0) if (delta >= (1 << i)) delta -= 1 << i, u = db[i][u];
    return u;
}

inline int lca(int u, int v) {
    if (dep[u] < dep[v]) std::swap(u, v);
    int delta = dep[u] - dep[v];
    u = up_dep(u, delta);
    if (u == v) return u;
    per(i, 19, 0) if (db[i][u] != db[i][v]) u = db[i][u], v = db[i][v];
    return db[0][u];
}

inline int query(int u, int delta) {
    int ret = 0;
    per(i, 19, 0) if (delta >= (1 << i)) ret += st[i][u], delta -= 1 << i,
        u = db[i][u];
    return ret;
}

int stamp = 0;

void dfs(int u) {
    siz[u] = 1;
    dfn[u] = ++stamp;
    for (auto v : g[u]) {
        if (v == db[0][u]) continue;
        dep[v] = dep[u] + 1;
        db[0][v] = u;
        dfs(v);
        siz[u] += siz[v];
    }
    for (auto v : g[u])
        if (v != db[0][u]) st[0][v] = siz[u] - siz[v];
}

inline bool cmp_dfn(const H& u, const H& v) { return dfn[u.num] < dfn[v.num]; }

int stk[N], sz = 0;

int cnt = 0;

struct Edge {
    int v;
    Edge* nxt;
} e[N];

Edge* p[N];

inline void addedge(int u, int v) {
    // cerr << "addedge " << u << ' ' << v << endl;
    e[cnt] = (Edge){v, p[u]};
    p[u] = &e[cnt++];
}

struct Node {
    int seq, dis;
} a[N];

void dfs1(int u) {
    if (rev[u]) a[u].seq = rev[u], a[u].dis = 0;
    for (auto i = p[u]; i; i = i->nxt) {
        dfs1(i->v);
        int update = a[i->v].dis + dep[i->v] - dep[u];
        if (a[i->v].seq != 0 &&
            (update < a[u].dis || a[u].seq == 0 ||
             (update == a[u].dis && h[a[u].seq].num > h[a[i->v].seq].num))) {
            a[u].dis = update;
            a[u].seq = a[i->v].seq;
        }
    }
}

void dfs2(int u) {
    for (auto i = p[u]; i; i = i->nxt) {
        int update = a[u].dis + dep[i->v] - dep[u];
        if (a[i->v].seq == 0 || update < a[i->v].dis ||
            (h[a[u].seq].num < h[a[i->v].seq].num && update == a[i->v].dis)) {
            a[i->v].dis = update;
            a[i->v].seq = a[u].seq;
        }
        dfs2(i->v);
    }
}

inline void add_ans(int u, int k) {
    // cerr << "add ans " << u << ' ' << h[a[u].seq].num << ' ' << k << endl;
    h[a[u].seq].ans += k;
}

inline void solve_edge(int u, int v) {
    int delta = dep[v] - dep[u];
    if (a[u].seq == a[v].seq) {
        add_ans(u, query(v, delta - 1));
        return;
    }
    if (delta <= 1) return;
    int k2 = delta + a[v].dis - a[u].dis;
    int k = k2 / 2;
    if (!(k2 & 1) && h[a[u].seq].num > h[a[v].seq].num) {
        k -= 1;
    }
    add_ans(u, query(up_dep(v, delta - k - 1), k));
    add_ans(v, query(v, delta - k - 1));
}

void solve(int u) {
    int add = siz[u];
    for (auto i = p[u]; i; i = i->nxt) {
        add -= siz[up_dep(i->v, dep[i->v] - dep[u] - 1)];
        solve_edge(u, i->v);
        solve(i->v);
    }
    add_ans(u, add);
}

void init() {
    cnt = 0, sz = 0;
    std::memset(p, 0, sizeof(p));
    std::memset(a, 0, sizeof(a));
    rep(i, 1, m) rev[h[i].num] = 0;
}

void print_vt(int u) {
    cerr << "node " << u << ' ' << h[a[u].seq].num << ' ' << a[u].dis << endl;
    for (auto i = p[u]; i; i = i->nxt) {
        cerr << u << " -> " << i->v << endl;
        print_vt(i->v);
    }
}

inline bool cmp_seq(const H& a, const H& b) { return a.seq < b.seq; }

int main() {
#ifndef ONLINE_JUDGE
    freopen("/tmp/input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int q;
    cin >> n;
    rep(i, 2, n) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int rt = 1;
    dep[rt] = 1;
    dfs(rt);
    // rep(k,  0, 3) rep(i, 1, n) cerr << st[k][i] << (i == n ? '\n' : ' ');

    rep(k, 1, 19) rep(i, 1, n) db[k][i] = db[k - 1][db[k - 1][i]],
                               st[k][i] =
                                   st[k - 1][db[k - 1][i]] + st[k - 1][i];
    cin >> q;
    while (q--) {
        init();
        cin >> m;
        rep(i, 1, m) cin >> h[i].num, h[i].seq = i, h[i].ans = 0,
                                      rev[h[i].num] = i;

        std::sort(h + 1, h + 1 + m, cmp_dfn);
        stk[sz++] = rt;
        if (rt != h[1].num) stk[sz++] = h[1].num;
        rep(i, 2, m) {
            int u = h[i].num;
            int asr = lca(stk[sz - 1], u);
            if (asr == stk[sz - 1])
                stk[sz++] = u;
            else {
                while (sz - 2 >= 0 && dep[stk[sz - 2]] >= dep[asr]) {
                    addedge(stk[sz - 2], stk[sz - 1]);
                    sz--;
                }
                if (asr != stk[sz - 1]) {
                    addedge(asr, stk[sz - 1]);
                    sz--;
                    stk[sz++] = asr;
                }
                stk[sz++] = u;
            }
        }
        rep(i, 0, sz - 2) addedge(stk[i], stk[i + 1]);

        std::sort(h + 1, h + 1 + m, cmp_seq);
        dfs1(rt);
        dfs2(rt);
        // print_vt(rt);
        solve(rt);
        rep(i, 1, m) cout << h[i].ans << ' ';
        cout << endl;
    }
    return 0;
}