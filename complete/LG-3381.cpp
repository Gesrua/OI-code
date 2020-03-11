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

const int N = 5100, M = 50100;

#define travese(i, u) for (edge* i = p[u]; i; i = i->nxt)

struct edge {
    int cap, v, cost;
    edge *nxt, *rev;
} e[M * 2];

edge* p[N];

int cnt = 0;

void addedge(int u, int v, int cap, int cost, bool nxt) {
    e[cnt].rev = nxt ? &e[cnt + 1] : &e[cnt - 1];
    e[cnt].v = v, e[cnt].cap = cap, e[cnt].cost = cost;
    e[cnt].nxt = p[u], p[u] = &e[cnt];
    ++cnt;
}

bool inque[N];
ll dis[N];

int s, t;

std::queue<int> q;

struct data {
    edge* e;
    int u, cap;
} pre[N];

bool spfa() {
    // cerr << "spfa \n";
    std::memset(dis, -1, sizeof(dis));
    std::memset(inque, 0, sizeof(inque));
    q.push(s);
    dis[s] = 0;
    inque[s] = 1;
    pre[s].cap = 100000000;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        // cerr << u << ' ';
        inque[u] = 0;
        travese(i, u) {
            if (i->cap > 0 && (dis[i->v] == -1 || dis[i->v] > dis[u] + i->cost)) {
                pre[i->v].u = u;
                pre[i->v].e = i;
                pre[i->v].cap = std::min(pre[u].cap, i->cap);
                dis[i->v] = dis[u] + i->cost;
                if (i->v != t && !inque[i->v]) q.push(i->v), inque[i->v] = 1;
            }
        }
    }
    return dis[t] != -1;
}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, m;
    cin >> n >> m >> s >> t;
    rep(i, 1, m) {
        int u, v, cap, cost;
        cin >> u >> v >> cap >> cost;
        addedge(u, v, cap, cost, 1);
        addedge(v, u, 0, -cost, 0);
    }
    ll maxflow = 0, cost = 0;
    while (spfa()) {
        // cerr << "add " << pre[t].cap << endl;
        maxflow += pre[t].cap;
        cost += dis[t] * pre[t].cap;
        for (int u = t; u != s; u = pre[u].u) {
            pre[u].e->cap -= pre[t].cap;
            pre[u].e->rev->cap += pre[t].cap;
        }
    }
    cout << maxflow << ' ' << cost;
    return 0;
}
