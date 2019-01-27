#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int n, m, a[101], dp[101][101], sum[101] = {0};
int solve(int n_now, int m_now) {
    int ans = 0;
    if (m_now < 0) return 0;
    if (dp[n_now][m_now] != -1) return dp[n_now][m_now];
    if (m_now > sum[n_now]) return dp[n_now][m_now] = 0;
    if (n_now == 1) {
        if (a[1] >= m_now) return dp[n_now][m_now] = 1;
        return dp[n_now][m_now] = 0;
    }
    for (int i = 0; i <= a[n_now]; i++) ans = (ans + solve(n_now - 1, m_now - i)) % 1000007;
    return dp[n_now][m_now] = ans % 1000007;
}
int main() {
    memset(dp, -1, sizeof(dp));
    int i;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    cout << solve(n, m);
    return 0;
}
