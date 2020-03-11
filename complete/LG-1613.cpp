#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define rep(i, l, r) for (register int i = (l); i <= (r); ++i)
#define per(i, l, r) for (register int i = (l); i >= (r); --i)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
typedef pair<int, int> pii;
bool dp[51][51][65];
int map[51][51];
int main() {
    std::ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        map[u][v] = 1;
        dp[u][v][0] = 1;
    }
    rep(l, 0, 63) rep(k, 1, n) {
        rep(i, 1, n) {
            rep(j, 1, n) {
                dp[i][j][l + 1] = dp[i][j][l + 1] || (dp[i][k][l] && dp[k][j][l]);
                map[i][j] = map[i][j] || dp[i][j][l + 1];
                // cerr << i << ' ' << j << ' ' << l + 1 << ' ' << dp[i][j][l +
                // 1] << endl;
            }
        }
    }
    rep(i, 1, n) {
        rep(j, 1, n) {
            if (!map[i][j]) map[i][j] = 100000000;
        }
    }
    rep(k, 1, n) {
        rep(i, 1, n) {
            rep(j, 1, n) {
                if (map[i][k] + map[k][j] < map[i][j]) map[i][j] = map[i][k] + map[k][j];
            }
        }
    }
    cout << map[1][n];
    return 0;
}
