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

const int N = 1005;

std::vector<int> g[N];
int fa[N];
int dp[N][5];

// 0 覆盖子树
// 1, 2 外
// 3 u 未覆盖
// 4 u's child 未覆盖

int min(int x, int y) { return std::min(x, y); }
int min(int x, int y, int z) { return min(x, min(y, z)); }
int min(int a, int b, int c, int d) { return min(min(a, b), min(c, d)); }
int min(int a, int b, int c, int d, int e) { return min(e, min(a, b, c, d)); }

void solve(int u) {
    if (g[u].size() == 0) {
        dp[u][2] = 1;
        dp[u][0] = dp[u][1] = 1000;
        return;
    }
    int d1 = 1000, d2 = 1000, d3 = 1000;
    dp[u][2] = 1;
    for (auto v : g[u]) {
        auto cur = dp[v];
        solve(v);
        dp[u][2] += min(cur[0], cur[1], cur[2], cur[3], cur[4]);
        dp[u][1] += min(cur[2], cur[1], cur[0], cur[3]);
        d1 = min(d1, cur[2] - min(cur[1], cur[0], cur[3]));
        dp[u][0] += min(cur[1], cur[0]);
        d2 = min(d2, cur[1] - cur[0]);
        dp[u][3] += cur[0];
        dp[u][4] += min(cur[3], cur[1], cur[0]);
    }
    if (d1 > 0) dp[u][1] += d1;
    if (d2 > 0) dp[u][0] += d2;
}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n;
    cin >> n;
    rep(i, 2, n) {
        cin >> fa[i];
        g[fa[i]].push_back(i);
    }
    solve(1);
    // rep(i, 1, n) {
    //     cerr << i << ' ' << dp[i][4] << ' ' << dp[i][3] << ' ' << dp[i][0]
    //          << ' ' << dp[i][1] << ' ' << dp[i][2] << endl;
    // }
    cout << min(dp[1][0], dp[1][1], dp[1][2]);
    return 0;
}
