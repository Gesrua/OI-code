#include <cstdio>
#include <iostream>
#include <utility>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#define rep(i, l, r) for (register int i = (l); i <= (r); ++i)
#define per(i, l, r) for (register int i = (l); i >= (r); --i)
using std::cin; using std::cout; using std::cerr; using std::endl;
using std::make_pair; using std::pair;
typedef pair< int, int > pii;

const int N = 100009, INF = 10000009;

int n, m, ask[109], ans[109], judge[INF];

struct graph{
    struct edge{
        int v, w;
        edge* nxt;
    };
    struct node{
        edge* first;
        bool solved;
        int dep, siz;
    };
    edge e[N*2]; node p[N]; int tot;
    int G, GSIZ, SIZ;
    graph(){tot = 0;}
    inline void sdep(int x, int y){ p[x].dep = y; }
    inline int qdep(int x){ return p[x].dep; }
    inline void asiz(int x, int y){ p[x].siz += y; }
    inline void ssiz(int x, int y){ p[x].siz = y; }
    inline int qsiz(int x){ return p[x].siz; }
    inline void addedge(int u, int v, int w){
        e[tot].v = v, e[tot].nxt = p[u].first, e[tot].w = w, p[u].first = &e[tot++];
        e[tot].v = u, e[tot].nxt = p[v].first, e[tot].w = w, p[v].first = &e[tot++];
    }
    inline bool is_solved(int x){ return p[x].solved; }
    inline void solved(int x){ p[x].solved = 1; }
    void dfs_g(int fa, int x){
        // cerr << fa << ' ' << x << endl;
        int max = 0;
        ssiz(x, 1);
        for (edge* i = p[x].first; i != NULL; i = i->nxt){
            if (is_solved(i->v) || i->v == fa) continue;
            // cerr << "nxt " << x << ' ' << i->v << endl;
            dfs_g(x, i->v);
            max = std::max(qsiz(i->v), max);
            asiz(x, qsiz(i->v));
        }
        max = std::max(max, SIZ-qsiz(x));
        if (max <= GSIZ){
            G = x;
            GSIZ = max;
        }
    }
    int find_g(int x, int siz){
        SIZ = siz;
        G = x;
        GSIZ = siz;
        dfs_g(x, x);
        return G;
    }
};
graph g;

void dfs1(int fa, int x){
    int dep = g.qdep(x);
    rep(i, 1, m)
        if (!ans[i] && ask[i] >= dep)
            ans[i] = judge[ask[i]-dep];
    g.ssiz(x, 1);
    for (graph::edge* i = g.p[x].first; i != NULL; i = i->nxt){
        if (g.is_solved(i->v) || i->v == fa) continue;
        g.sdep(i->v, dep + i->w);
        dfs1(x, i->v);
        g.asiz(x, g.qsiz(i->v));
    }
}

void dfs2(int fa, int x){
    judge[g.qdep(x)] = 1;
    for (graph::edge* i = g.p[x].first; i != NULL; i = i->nxt){
        if (g.is_solved(i->v) || i->v == fa) continue;
        dfs2(x, i->v);
    }
}

void dfs3(int fa, int x){
    judge[g.qdep(x)] = 0;
    for (graph::edge* i = g.p[x].first; i != NULL; i = i->nxt){
        if (g.is_solved(i->v) || i->v == fa) continue;
        dfs3(x, i->v);
    }
}

void solve(int x, int n){
    // cerr << "solving " << x << ' ' << n << endl;
    // cerr << "grav ";
    int grv = g.find_g(x, n);
    // cerr << grv << endl;
    g.sdep(grv, 0);
    judge[0] = 1;
    x = grv;
    // cerr << "dfs1" << endl;
    for (graph::edge* i = g.p[x].first; i != NULL; i = i->nxt){
        if (g.is_solved(i->v)) continue;
        g.sdep(i->v, i->w);
        dfs1(x, i->v);
        dfs2(x, i->v);
        // rep(k, 0, 10){
        //     cerr << judge[k] << ' ';
        // }
        // cerr << endl;
    }
    dfs3(x, x);
    g.solved(x);
    for (graph::edge* i = g.p[x].first; i != NULL; i = i->nxt){
        if (g.is_solved(i->v)) continue;
        solve(i->v, g.qsiz(i->v));
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n >> m;
    rep(i, 2, n){
        int u, v, w;
        cin >> u >> v >> w;
        g.addedge(u, v, w);
    }
    // rep(x, 1, n){
    //     cerr << x << ' ';
    //     for (graph::edge* i = g.p[x].first; i != NULL; i = i->nxt){
    //         cerr << i->v << ' ';
    //     }
    //     cerr << endl;
    // }
    rep(i, 1, m) cin >> ask[i];
    solve(1, n);
    rep(i, 1, m){
        if (ans[i]) cout << "AYE\n";
        else cout << "NAY\n";
    }
    return 0;
}