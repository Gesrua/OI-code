#include <cmath>
#include <cstring>
#include <iostream>
#include <stack>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
long long dp[30], g[30][30], N, num[30], n[30];
int dfs(int x) {
    if (dp[x] != -1) return dp[x];
    int max = 0;
    for (int i = x + 1; i <= N; ++i) {
        if (g[x][i] && dfs(i) > max) {
            n[x] = i;
            max = dfs(i);
        }
    }
    max += num[x];
    return dp[x] = max;
}
int main() {
    cin >> N;
    std::memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= N; ++i) {
        cin >> num[i];
    }
    for (int i = 1; i < N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            cin >> g[i][j];
        }
    }
    dp[N] = num[N];
    int ans = 0;
    for (int i = N; i > 0; --i) {
        if (dfs(i) > ans) {
            n[0] = i;
            ans = dfs(i);
        }
    }
    int i = n[0];
    while (i) {
        cout << i << ' ';
        i = n[i];
    }
    cout << endl << ans;
    return 0;
}