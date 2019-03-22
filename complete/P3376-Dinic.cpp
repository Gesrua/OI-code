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
using std::max;
using std::min;
using std::pair;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int ui;

const int N = 10100, M = 200200, inf = 1e9;

struct Dinic {
    struct Node;
    struct Edge {
        Node* v;
        int cap;
        Edge* rev;
        Edge* nxt;
    } edges[M];
    int cnt = 0, n, s, t;
    struct Node {
        Edge *cur, *first;
        int d;
    } g[N];
    void addedge(int u, int v, int c) {
        edges[cnt] = (Edge){&g[v], c, &edges[cnt ^ 1], g[u].first};
        g[u].first = &edges[cnt];
        edges[cnt ^ 1] = (Edge){&g[u], 0, &edges[cnt], g[v].first};
        g[v].first = &edges[cnt ^ 1];
        cnt += 2;
    }
    bool bfs() {
        std::queue<Node*> q;
        rep(i, 1, n) g[i].cur = g[i].first, g[i].d = 0;
        q.push(&g[s]);
        g[s].d = 1;  // important
        while (!q.empty()) {
            auto u = q.front();
            // cerr << (u - g) << endl;
            q.pop();
            for (auto e = u->first; e; e = e->nxt)
                if (e->v->d == 0 && e->cap > 0)
                    e->v->d = u->d + 1, q.push(e->v);
        }
        // rep(i, 1, n) { cerr << g[i].d << ' '; }
        // cerr << endl;
        return g[t].d;
    }
    int dfs(Node* u, int c) {
        if (u == &g[t] || c == 0) return c;
        int f, flow = 0;
        for (auto e = u->cur; e; e = e->nxt) {
            if (e->v->d == u->d + 1 && (f = dfs(e->v, min(c, e->cap))) > 0) {
                // cerr << (u - g) << ' ' << (e->v - g) << ' ' << e->cap << ' '
                //      << f << endl;
                e->cap -= f, c -= f;
                e->rev->cap += f, flow += f;
                if (c == 0) return flow;
            }
        }
        return flow;
    }
    int maxflow() {
        int flow = 0, f;
        while (bfs()) {
            // cerr << "bfsed" << endl;
            while ((f = dfs(&g[s], inf)) > 0) {
                flow += f;
                // cerr << "dfsed " << flow << endl;
            }
        }
        return flow;
    }
    void print() {
        rep(i, 1, n) {
            // cerr << i << ' ';
            for (auto e = g[i].first; e; e = e->nxt) {
                cerr << i << ' ' << (e->v - g) << ' ' << e->cap << endl;
                // e = e->rev;
                // cerr << i << ' ' << (e->v - g) << ' ' << e->cap << endl;
                // e = e->rev;
            }
            // cerr << endl;
        }
    }
} solver;

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int m;
    cin >> solver.n >> m >> solver.s >> solver.t;
    while (m--) {
        int u, v, c;
        cin >> u >> v >> c;
        solver.addedge(u, v, c);
    }
    // solver.print();
    cout << solver.maxflow();
    return 0;
}