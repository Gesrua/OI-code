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

int n, m;
int dfn[N], dep[N], id[N], siz[N], son[N], top[N], val[N], fa[N], lca[18][N];
std::vector<int> g[N];

typedef long long TYPE;

#define msg(x) cerr << x << endl;

struct Seg {
#define ls (cur * 2)
#define rs (cur * 2 + 1)
#define ln T[cur * 2]
#define rn T[cur * 2 + 1]
#define cn T[cur]
    typedef long long TYPE;
    struct node {
        int l, r;
        TYPE s, tag;
        int len() { return r - l + 1; }
    } T[N * 4];
    void pushup(int cur) {
        cn.tag = 0;
        cn.s = ln.s + rn.s;
    }
    void pushdown(int cur) {
        ln.s += cn.tag * ln.len();
        rn.s += cn.tag * rn.len();

        ln.tag += cn.tag;
        rn.tag += cn.tag;

        cn.tag = 0;
    }
    void build(int cur, int l, int r) {
        cn.l = l, cn.r = r;
        if (l == r) {
            cn.s = val[id[l]];
            return;
        }
        int mid = l + (r - l) / 2;
        build(ls, l, mid);
        build(rs, mid + 1, r);
        pushup(cur);
    }
    int L, R, X;
    TYPE _query(int cur) {
        if (L <= cn.l && cn.r <= R) return cn.s;
        if (R < cn.l || cn.r < L) return 0;
        pushdown(cur);
        return _query(ls) + _query(rs);
    }
    void _add(int cur) {
        if (L <= cn.l && cn.r <= R) {
            cn.tag += X, cn.s += X * cn.len();
            return;
        }
        if (R < cn.l || cn.r < L) return;
        pushdown(cur);
        _add(ls), _add(rs);
        pushup(cur);
    }
    TYPE query(int l, int r) {
        L = l, R = r;
        return _query(1);
    }
    void add(int l, int r, TYPE x) {
        L = l, R = r, X = x;
        _add(1);
    }
} seg;

void dfs1(int u) {
    dep[u] = dep[fa[u]] + 1;
    siz[u] = 1;
    for (auto v : g[u]) {
        dfs1(v);
        siz[u] += siz[v];
        if (siz[son[u]] < siz[v]) son[u] = v;
    }
}

int dfs_tag = 1;

void dfs2(int u) {
    top[u] = son[fa[u]] == u ? top[fa[u]] : u;
    dfn[u] = dfs_tag, id[dfs_tag] = u, dfs_tag++;
    if (!son[u]) return;
    dfs2(son[u]);
    for (auto v : g[u]) {
        if (v == son[u]) continue;
        dfs2(v);
    }
}

int jump(int u, int target_dep) {
    per(k, 17, 0) if (dep[lca[k][u]] >= target_dep) u = lca[k][u];
    return u;
}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> val[i];
    rep(i, 2, n) {
        cin >> fa[i];
        g[fa[i]].push_back(i);
    }

    int rt = 1;
    dfs1(rt);

    // cerr << "dfs1 over" << endl;

    dfs2(rt);

    // cerr << "dfs over" << endl;

    seg.build(1, 1, n);

    // cerr << "build over" << endl;

    rep(i, 1, n) lca[0][i] = fa[i];

    rep(k, 1, 17) rep(i, 1, n) lca[k][i] = lca[k - 1][lca[k - 1][i]];

    cin >> m;
    while (m--) {
        int opt, u, v, k;
        cin >> opt;
        if (opt == 1) {
            cin >> rt;
        } else if (opt == 2) {
            cin >> u >> v >> k;
            while (top[u] != top[v]) {
                if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
                seg.add(dfn[top[u]], dfn[u], k);
                u = fa[top[u]];
            }
            if (dep[u] > dep[v]) std::swap(u, v);
            seg.add(dfn[u], dfn[v], k);
        } else if (opt == 4) {
            TYPE ans = 0;
            cin >> u >> v;
            while (top[u] != top[v]) {
                if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
                ans += seg.query(dfn[top[u]], dfn[u]);
                u = fa[top[u]];
            }
            if (dep[u] > dep[v]) std::swap(u, v);
            ans += seg.query(dfn[u], dfn[v]);
            cout << ans << endl;
        } else if (opt == 3) {
            cin >> u >> k;
            if (rt == u)
                seg.add(1, n, k);
            else if (dfn[u] < dfn[rt] && dfn[rt] < dfn[u] + siz[u]) {
                seg.add(1, n, k);
                int ign = jump(rt, dep[u] + 1);
                seg.add(dfn[ign], dfn[ign] + siz[ign] - 1, -k);
            } else
                seg.add(dfn[u], dfn[u] + siz[u] - 1, k);

        } else if (opt == 5) {
            cin >> u;
            TYPE ans = 0;
            if (rt == u)
                ans = seg.query(1, n);
            else if (dfn[u] < dfn[rt] && dfn[rt] < dfn[u] + siz[u]) {
                ans += seg.query(1, n);
                int ign = jump(rt, dep[u] + 1);
                ans -= seg.query(dfn[ign], dfn[ign] + siz[ign] - 1);
            } else
                ans = seg.query(dfn[u], dfn[u] + siz[u] - 1);

            cout << ans << endl;
        }
    }
    return 0;
}
