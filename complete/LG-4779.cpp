#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using std::cerr;
using std::cout;
using std::endl;
using std::isdigit;
using std::make_pair;
using std::pair;
typedef pair<int, int> pii;
char s[50000001];
int stl = 0, n;
const int M = 2000000;
const int N = 1000000;
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
    edge e[M + 1000];
    edge* head[N + 1000];
    int cnt;
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
            dis[i] = 2147483647;
        }
        std::priority_queue<pii, std::vector<pii>, std::greater<pii> > q;
        dis[s] = 0;
        q.push(make_pair(0, s));
        while (!q.empty()) {
            pii cur = q.top();
            q.pop();
            if (cur.first > dis[cur.second]) continue;
            for (edge* i = head[cur.second]; i != NULL; i = i->nxt) {
                if (dis[i->v] > cur.first + i->w) {
                    dis[i->v] = cur.first + i->w;
                    q.push(make_pair(dis[i->v], i->v));
                }
            }
        }
    }
} g;
int dis[N];
int main() {
    fread(s, 50000000, 1, stdin);
    int m, s;
    rd(n);
    rd(m);
    rd(s);
    int u, v, w;
    g.cnt = 0;
    for (int i = 0; i < m; ++i) {
        rd(u);
        rd(v);
        rd(w);
        g.addedge(u, v, w);
    }
    g.dijkstra(s, dis);
    for (int i = 1; i <= n; ++i) {
        cout << dis[i] << ' ';
    }
    return 0;
}