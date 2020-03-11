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

const int inf = 0x3f3f3f3f;

int n, m, k, dis[1002], vis[1002];
std::vector<std::vector<pii>> g(1001);
std::deque<int> q;

bool valid(int m) {
    q.push_front(1);
    std::memset(dis, 0x3f, sizeof(dis));
    std::memset(vis, 0, sizeof(vis));
    dis[1] = 0;
    while (q.size()) {
        int u = q.front();
        q.pop_front();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto i : g[u]) {
            int v = i.first, w = i.second;
            if (vis[v]) continue;
            if (w <= m) {
                if (dis[v] >= dis[u]) {
                    dis[v] = dis[u];
                    q.push_front(v);
                }
            } else {
                if (dis[v] > dis[u] + 1) {
                    dis[v] = dis[u] + 1;
                    q.push_back(v);
                }
            }
        }
    }
    return dis[n] <= k;
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n >> m >> k;
    int l = 0, r = 0;
    rep(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(pii(v, w));
        g[v].push_back(pii(u, w));
        r = std::max(r, w);
    }
    int _r = r;
    r++;
    while (l < r) {
        // cout << l << ' ' << r << endl;
        int mid = (l + r) / 2;
        if (valid(mid))
            r = mid;
        else
            l = mid + 1;
    }
    if (l > _r)
        cout << -1;
    else
        cout << l;
    // cout << l << ' ' << r << endl;
    return 0;
}