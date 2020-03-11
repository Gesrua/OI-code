#include <algorithm>
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
#define rep(i, l, r) for (register int i = (l); i <= (r); ++i)
#define per(i, l, r) for (register int i = (l); i >= (r); --i)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
typedef pair<int, int> pii;

const int N = 50009, K = 509;

int n, k, judge[K];
long long ans;

struct graph {
    struct edge {
        int v;
        edge* nxt;
    };
    struct node {
        edge* first;
        bool solved;
        int dep, siz;
    };
    edge e[N * 2];
    node p[N];
    int tot;
    int G, GSIZ, SIZ;
    graph() { tot = 0; }
    inline void sdep(int x, int y) { p[x].dep = y; }
    inline int qdep(int x) { return p[x].dep; }
    inline void asiz(int x, int y) { p[x].siz += y; }
    inline void ssiz(int x, int y) { p[x].siz = y; }
    inline int qsiz(int x) { return p[x].siz; }
    inline void addedge(int u, int v) {
        e[tot].v = v, e[tot].nxt = p[u].first, p[u].first = &e[tot++];
        e[tot].v = u, e[tot].nxt = p[v].first, p[v].first = &e[tot++];
    }
    inline bool is_solved(int x) { return p[x].solved; }
    inline void solved(int x) { p[x].solved = 1; }
    void dfs_g(int fa, int x) {
        // cerr << fa << ' ' << x << endl;
        int max = 0;
        ssiz(x, 1);
        for (edge* i = p[x].first; i != NULL; i = i->nxt) {
            if (is_solved(i->v) || i->v == fa) continue;
            // cerr << "nxt " << x << ' ' << i->v << endl;
            dfs_g(x, i->v);
            max = std::max(qsiz(i->v), max);
            asiz(x, qsiz(i->v));
        }
        max = std::max(max, SIZ - qsiz(x));
        if (max <= GSIZ) {
            G = x;
            GSIZ = max;
        }
    }
    int find_g(int x, int siz) {
        SIZ = siz;
        G = x;
        GSIZ = siz;
        dfs_g(x, x);
        return G;
    }
};
graph g;

void dfs1(int fa, int x) {
    int t = k - g.qdep(x);
    g.ssiz(x, 1);
    if (t >= 0 && t <= 500) ans += judge[t];
    for (graph::edge* i = g.p[x].first; i != NULL; i = i->nxt) {
        if (g.is_solved(i->v) || i->v == fa) continue;
        g.sdep(i->v, g.qdep(x) + 1);
        dfs1(x, i->v);
        g.asiz(x, g.qsiz(i->v));
    }
}

void dfs2(int fa, int x) {
    int dep = g.qdep(x);
    if (dep >= 0 && dep <= 500) judge[dep]++;
    for (graph::edge* i = g.p[x].first; i != NULL; i = i->nxt) {
        if (g.is_solved(i->v) || i->v == fa) continue;
        dfs2(x, i->v);
    }
}

void dfs3(int fa, int x) {
    int dep = g.qdep(x);
    if (dep >= 0 && dep <= 500) judge[dep]--;
    for (graph::edge* i = g.p[x].first; i != NULL; i = i->nxt) {
        if (g.is_solved(i->v) || i->v == fa) continue;
        dfs3(x, i->v);
    }
}

void solve(int x, int n) {
    judge[0] = 1;
    int grv = g.find_g(x, n);
    g.sdep(grv, 0);
    x = grv;  // forget !important
    // cerr << "grv " << grv << endl;
    for (graph::edge* i = g.p[x].first; i != NULL; i = i->nxt) {
        if (g.is_solved(i->v)) continue;
        g.sdep(i->v, 1);
        dfs1(x, i->v);
        dfs2(x, i->v);
    }
    g.solved(x);
    // cerr << "bfr ";
    dfs3(x, x);
    // cerr << "aft ";
    // std::memset(judge, 0, sizeof(judge));
    for (graph::edge* i = g.p[x].first; i != NULL; i = i->nxt) {
        if (g.is_solved(i->v)) continue;
        solve(i->v, g.qsiz(i->v));
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n >> k;
    rep(i, 2, n) {
        int u, v;
        cin >> u >> v;
        g.addedge(u, v);
    }
    solve(1, n);
    cout << ans;
    return 0;
}