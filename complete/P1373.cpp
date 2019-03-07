// luogu-judger-enable-o2
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

const int N = 803;
#define mod(x) (x) %= 1000000007

unsigned int a[N][N];
unsigned int dp[N][N][17][2];

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    ++k;
    rep(i, 1, n) rep(j, 1, m) {
        cin >> a[i][j];
        dp[i][j][a[i][j] % k][0] = 1;
    }
    unsigned int ans = 0;
    rep(i, 1, n) {
        rep(j, 1, m) {
            rep(h, 0, k - 1) {
                if (i <= n) {
                    mod(dp[i + 1][j][(h + a[i + 1][j]) % k][0] +=
                        dp[i][j][h][1]);
                    mod(dp[i + 1][j][(h - a[i + 1][j] + k) % k][1] +=
                        dp[i][j][h][0]);
                }
                if (j <= m) {
                    mod(dp[i][j + 1][(h + a[i][j + 1]) % k][0] +=
                        dp[i][j][h][1]);
                    mod(dp[i][j + 1][(h - a[i][j + 1] + k) % k][1] +=
                        dp[i][j][h][0]);
                }
            }
            mod(ans += dp[i][j][0][1]);
        }
    }
    cout << ans;
    return 0;
}
