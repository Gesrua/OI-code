#include <cmath>
#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
inline int min(int a, int b) { return a > b ? b : a; }
int m, n, t1, t2, a[52][52];
int dp[52][52][104];
inline int max(int a, int b, int c, int d) {
    a = a > b ? a : b, c = c > d ? c : d;
    return a > c ? a : c;
}
int main() {
    std::ios::sync_with_stdio(false);
    cin >> m >> n;
    for (register int i = 1; i <= m; ++i) {
        for (register int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    for (register int k = 3; k <= m + n; ++k) {
        t1 = min(k - 1, m);
        for (register int i = 1; i <= t1; ++i) {
            t2 = min(k - 1, m);
            for (register int j = 2; j <= t2; ++j) {
                // if (k - i < 1 || k - j < 1) continue;
                dp[i][j][k] = max(dp[i - 1][j][k - 1], dp[i - 1][j - 1][k - 1], dp[i][j - 1][k - 1], dp[i][j][k - 1]) + a[i][k - i] + a[j][k - j];
                if (i == j) dp[i][j][k] -= a[i][k - i];
            }
        }
    }
    cout << dp[m][m][m + n];
    return 0;
}
