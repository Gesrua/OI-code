#include <cstdio>
#include <cstring>
int r, a[1001][1001], dp[1001][1001];
void init() {
    using namespace std;
    memset(dp, -1, sizeof(dp));
    scanf("%d", &r);
    int i, j;
    for (i = 1; i <= r; ++i)
        for (j = 1; j <= i; ++j) scanf("%d", &a[i][j]);
    for (i = 1; i <= r; ++i) dp[r][i] = a[r][i];
}
inline int max(int a, int b) { return a > b ? a : b; }
int solve(int x, int y) {
    if (dp[x][y] != -1) return dp[x][y];
    return dp[x][y] = max(solve(x + 1, y), solve(x + 1, y + 1)) + a[x][y];
}
int main() {
    init();
    printf("%d", solve(1, 1));
    return 0;
}
