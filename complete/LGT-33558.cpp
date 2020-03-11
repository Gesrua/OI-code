#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;
int m, n, lim, t;
long long sum[102][102] = {}, dp[102];
bool flag;
int main() {
    std::ios::sync_with_stdio(false);
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> t;
            sum[i][j] = sum[i - 1][j] + t;
        }
    }
    // for (int i = 1; i <= m; ++i){
    //  for (int j = 1; j <= n; ++j){
    //      cerr << sum[i][j] << ' ';
    //  }
    //  cerr << endl;
    // }
    long long ans = -2141111111;
    for (register int i = 0; i < m; ++i) {
        for (register int j = i + 1; j <= m; ++j) {
            dp[0] = -2100000000;
            for (register int k = 1; k <= n; ++k) {
                if (dp[k - 1] < 0) {
                    // dp[k] = sum[j][k] - sum[i][k];
                    dp[k] = dp[k - 1] + sum[j][k] - sum[i][k];
                    if (dp[k] > ans) ans = dp[k];
                    dp[k] -= dp[k - 1];
                    if (j - i > 1 && dp[k] > ans) {
                        ans = dp[k];
                    }
                } else {
                    dp[k] = dp[k - 1] + sum[j][k] - sum[i][k];
                    if (dp[k] > ans) ans = dp[k];
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
