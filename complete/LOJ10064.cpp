#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <utility>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
typedef unsigned int uInt;
typedef unsigned long long ull;
#define rep(i, l, r) for (register int i = (l); i <= (r); ++i)
#define traverse(u) for (register edge* i = p[u]; i != nullptr; i = i->nxt)
const int N = 1010;
const int INF = 2100000000;
const int M = 1000010;
int cnt = 0, n, m;
uInt G[N][N];
typedef std::pair<uInt, uInt> pii;
pii dis[N];
struct edge {
    int v, w;
    edge* nxt;
    inline edge() { v = 0, w = 0, nxt = nullptr; }
} e[M];
edge* p[N];
inline void addedge(const int u, const int v, const int w) { e[cnt].v = v, e[cnt].w = w, e[cnt].nxt = p[u], p[u] = &e[cnt], ++cnt; }
int main() {
    std::ios::sync_with_stdio(false);
    int n, m, u, v, w;
    std::cin >> n >> m;
    rep(i, 1, m) {
        std::cin >> u >> v >> w;
        G[u][v] = G[v][u] = w;
        addedge(u, v, w);
        addedge(v, u, w);
    }
    std::priority_queue<pii, std::vector<pii>, std::greater<pii> > q;
    q.push(pii(0, 1));
    bool flag[N] = {};
    rep(i, 0, n) dis[i].first = INF, dis[i].second = i;
    dis[1].first = 0;
    while (!q.empty()) {
        pii cur = q.top();
        q.pop();
        if (flag[cur.second]) continue;
        flag[cur.second] = true;
        traverse(cur.second) if (dis[cur.second].first + i->w < dis[i->v].first) dis[i->v].first = dis[cur.second].first + i->w, q.push(pii(dis[i->v].first, i->v));
    }
    // rep(i, 1, n) cerr << dis[i].first << ' '; cerr << endl;
    std::sort(dis + 1, dis + 1 + n);
    // rep(i, 1, n) cerr << dis[i].first << ' '; cerr << endl;
    unsigned long long ans = 1;
    rep(i, 2, n) {
        int cnt = 0;
        for (register int j = 1; dis[j].first != dis[i].first; ++j)
            if (dis[j].first + G[dis[j].second][dis[i].second] == dis[i].first) ++cnt;

        ans *= cnt;
        ans %= 2147483647;
    }
    cout << ans;
    return 0;
}