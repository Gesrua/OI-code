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

int a[2010];

bool vis[2010];

std::vector<int> g[2010];

int deg[2010], dis[2010], ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    rep(i, 1, m) {
        int s;
        cin >> s;
        std::memset(vis, 0, sizeof(vis));
        rep(j, 1, s) cin >> a[j], vis[a[j]] = 1;

        rep(j, a[1], a[s]) {
            if (vis[j])
                g[n + i].push_back(j), deg[j]++;
            else
                g[j].push_back(n + i), deg[n + i]++;
        }
    }

    std::queue<int> q;
    rep(u, 1, n + m) if (deg[u] == 0) q.push(u), dis[u] = 1;

    ans = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            deg[v]--;
            dis[v] = std::max(dis[v], dis[u] + 1);
            if (deg[v] == 0) {
                q.push(v);
                ans = std::max(dis[v], ans);
            }
        }
    }

    // rep(i, 1, n) cerr << (dis[i] + 1) / 2 - 1 << ' ';
    // cerr << endl;

    // cerr << "real = " << ans << endl;
    cout << (ans + 1) / 2 << endl;
    return 0;
}