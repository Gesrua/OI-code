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

const int P = 100003;
const int N = 100010;

int dis[N], cnt[N];
std::vector<int> g[N];
std::priority_queue<pii, std::vector<pii>, std::greater<pii>> q;

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    std::memset(dis, 0x3f, sizeof(dis));
    int n, m;
    cin >> n >> m;
    rep(i, 1, m) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    }
    q.push(pii(0, 1));
    dis[1] = 0;
    cnt[1] = 1;
    while (!q.empty()) {
        auto u = q.top().second, d = q.top().first;
        q.pop();
        if (d > dis[u]) continue;
        // cerr << u << endl;
        for (auto v : g[u]) {
            if (dis[v] == d + 1) {
                // cerr << u << ' ' << v << ' ' << d << endl;
                (cnt[v] += cnt[u]) %= P;
            } else if (dis[v] > d + 1) {
                (cnt[v] = cnt[u]) %= P;
                dis[v] = d + 1;
                q.push(pii(d + 1, v));
            }
        }
    }
    // rep(i, 1, n) cerr << dis[i]; cerr << endl;
    rep(i, 1, n) cout << cnt[i] << endl;
    return 0;
}