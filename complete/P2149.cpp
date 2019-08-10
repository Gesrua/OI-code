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
using std::abs;
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

const int N = 1550;

int n;

std::vector<pii> g[N];

void add(int u, int v, int w) {
    g[u].push_back(pii(v, w)), g[v].push_back(pii(u, w));
}

struct Graph {
    bool vis[N];
    int topo[N], dis[2][N], deg[N], s, t;
    std::vector<pii> ng[N];
    void nadd(int u, int v, int w) {
        ng[u].push_back(pii(v, w));
        deg[v]++;
    }
    void dij(int s, int dis[]) {
        std::priority_queue<pii, std::vector<pii>, std::greater<pii> > q;
        dis[s] = 0;
        q.push(make_pair(0, s));
        while (!q.empty()) {
            pii cur = q.top();
            q.pop();
            if (cur.first > dis[cur.second]) continue;
            for (auto i : g[cur.second]) {
                if (dis[i.first] > cur.first + i.second) {
                    dis[i.first] = cur.first + i.second;
                    q.push(make_pair(dis[i.first], i.first));
                }
            }
        }
    }
    void make() {
        vis[s] = vis[t] = 1;
        rep(u, 1, n) {
            for (auto i : g[u]) {
                if (dis[0][u] + i.second + dis[1][i.first] == dis[0][t]) {
                    nadd(u, i.first, i.second);
                    vis[i.first] = 1;
                }
            }
        }
    }
    void top() {
        std::queue<int> q;
        rep(i, 1, n) if (deg[i] == 0) q.push(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto i : ng[u]) {
                deg[i.first]--;
                if (deg[i.first] == 0) {
                    q.push(i.first);
                    topo[i.first] = topo[u] + 1;
                }
            }
        }
    }
    void run(int s, int t) {
        this->s = s;
        this->t = t;
        std::memset(dis, 0x3f, sizeof(dis));
        dij(s, dis[0]);
        dij(t, dis[1]);
        make();
        top();
    }
    void print() {
        rep(u, 1, n) {
            cerr << u << " : " << vis[u] << " : ";
            for (auto i : ng[u]) {
                cerr << i.first << ' ';
            }
            cerr << endl;
        }
    }
    int dist(int u, int v) { return abs(dis[0][t] - dis[0][u] - dis[1][v]); }
} A, B;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int m, s1, t1, s2, t2;
    cin >> n >> m >> s1 >> t1 >> s2 >> t2;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }
    A.run(s1, t1), B.run(s2, t2);
    // B.print();
    int ans = 0;
    rep(u, 1, n) {
        if (!A.vis[u] || !B.vis[u]) continue;
        rep(v, 1, n) {
            if (!A.vis[v] || !B.vis[v] || A.topo[v] == A.topo[u] ||
                B.topo[v] == B.topo[u])
                continue;
            // if (A.topo[u] >= A.topo[v] || B.topo[u] >= B.topo[v] ||
            //     A.dis[0][u] != B.dis[0][u])
            //     continue;
            ans = max(ans, A.dist(u, v));
            // if (ans < A.dis[0][t1] - A.dis[0][u] - A.dis[1][v])
            // cerr << u << ' ' << v << endl;
            // ans = std::max(ans,
            //                std::min(A.dis[0][t1] - A.dis[0][u] - A.dis[1][v],
            //                         B.dis[0][t2] - B.dis[0][u] -
            //                         B.dis[1][v]));
        }
    }
    cout << ans;
    return 0;
}