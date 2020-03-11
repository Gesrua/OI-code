#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::isdigit;
using std::make_pair;
using std::pair;
typedef pair<int, int> pii;
const int N = 200;
const int M = 50000;
const int INF = 1000000;
char s[50000001];
int stl = 0;
inline void rd(int& x) {
    x = 0;
    for (; !isdigit(s[stl]); ++stl)
        ;
    for (; isdigit(s[stl]); ++stl) x = (x << 3) + (x << 1) + s[stl] - '0';
}
struct edge {
    int v, w;
    edge* nxt;
    edge() : v(0), w(0), nxt(NULL) {}
    edge(int _v, int _w, edge* _nxt) : v(_v), w(_w), nxt(_nxt) {}
};
struct graph {
    edge e[M];
    edge* head[N];
    int cnt, n;
    inline void addedge(const int& u, const int& v, const int w) {
        e[cnt] = edge(v, w, head[u]);
        head[u] = &e[cnt];
        ++cnt;
    }
    graph() {
        std::memset(head, NULL, sizeof(head));
        cnt = 0;
    }
    void dijkstra(int s, int dis[]) {
        for (int i = 0; i <= n; ++i) {
            dis[i] = INF;
        }
        std::priority_queue<pii, std::vector<pii>, std::greater<pii> > q;
        bool vis[N] = {};
        dis[s] = 0;
        q.push(std::make_pair(0, s));
        while (!q.empty()) {
            pii cur = q.top();
            // cerr << cur.first << ' ' << cur.second << endl;
            q.pop();
            if (vis[cur.second]) continue;
            vis[cur.second] = true;
            // cerr << cur.second << ' ';
            // if (cur.first > dis[cur.second]) continue;
            // if (vis[cur.second]) continue;
            // vis[cur.second] = true;
            for (edge* i = head[cur.second]; i != NULL; i = i->nxt) {
                if (dis[i->v] > cur.first + i->w) {
                    dis[i->v] = cur.first + i->w;
                    q.push(std::make_pair(dis[i->v], i->v));
                }
            }
        }
    }
} g;
int main() {
    fread(s, 50000000, 1, stdin);
    int n, a, b, k, v;
    rd(n);
    rd(a);
    rd(b);
    // cin >> n >> a >> b;
    g.n = n;
    for (int i = 1; i <= n; ++i) {
        // cerr << i << endl;
        rd(k);
        // cin >> k;
        if (k == 0) continue;
        --k;
        rd(v);
        // cin >> v;
        g.addedge(i, v, 0);
        while (k--) {
            rd(v);
            cin >> v;
            g.addedge(i, v, 1);
        }
    }
    // cerr << "HERE\n";
    int dis[N];
    g.dijkstra(a, dis);
    if (dis[b] == INF)
        cout << -1;
    else
        cout << dis[b];
    return 0;
}