#include <cctype>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <utility>
const int N = 10000;
const int M = 50000;
using std::cerr;
using std::cout;
using std::endl;
using std::isdigit;
using std::make_pair;
using std::max;
char s[30000001];
int stl = 0;
const int INF = 2100000000;
typedef long long LL;
typedef std::pair<int, int> pii;
int n, m, b;
int cost[N + 10];
inline void rd(int& x) {
    x = 0;
    for (; !isdigit(s[stl]); ++stl)
        ;
    for (; isdigit(s[stl]); ++stl) x = (x << 3) + (x << 1) + s[stl] - '0';
}
int cnt = 0;
struct edge {
    int v, c;
    edge* nxt;
    edge() : v(0), c(0) {}
    edge(const int _v, const int _c, edge* _nxt) : v(_v), c(_c), nxt(_nxt) {}
} e[100300];
int dis[11000];
edge* p[11000] = {};
inline void addedge(const int& u, const int& v, const int c) { e[cnt] = edge(v, c, p[u]), p[u] = &e[cnt++]; }
bool check(int s) {
    std::priority_queue<pii, std::vector<pii>, std::greater<pii> > q;
    for (int i = 1; i <= n; ++i) dis[i] = INF;
    dis[1] = 0;
    q.push(make_pair(0, 1));
    pii cur;
    while (!q.empty()) {
        cur = q.top();
        q.pop();
        // cerr << cur.first << ' ' << cur.second << endl;
        if (dis[cur.second] < cur.first) continue;
        for (edge* i = p[cur.second]; i != NULL; i = i->nxt) {
            if (cost[i->v] > s || i->c >= b || cur.first >= b || dis[i->v] <= cur.first + i->c) continue;
            dis[i->v] = cur.first + i->c;
            q.push(make_pair(dis[i->v], i->v));
        }
    }
    // cerr << dis[n] << endl;
    if (dis[n] >= b)
        return false;
    else
        return true;
}
int main() {
    fread(s, 30000000, 1, stdin);
    // cerr << "QAQ\n";
    rd(n);
    rd(m);
    rd(b);
    for (register int i = 1; i <= n; ++i) rd(cost[i]);
    int u, v, c;
    for (register int i = 0; i < m; ++i) {
        rd(u);
        rd(v);
        rd(c);
        if (u == v) continue;
        addedge(u, v, c);
        addedge(v, u, c);
    }
    // cerr << "QAQ\n";
    int l = max(cost[1], cost[n]), r = 1000000001;
    while (l < r) {
        // cerr << l << ' ' << r << endl;
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    if (l > 1000000000)
        cout << "AFK";
    else
        cout << l;
    return 0;
}