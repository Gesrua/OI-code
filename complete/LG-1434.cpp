#include <bits/stdc++.h>
const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int r, c, map[200][200] = {}, dp[200][200] = {};
int solve(const int x, const int y) {
    if (dp[x][y] != -1) return dp[x][y];
    dp[x][y] = 0;
    int tx, ty;
    for (int i = 0; i < 4; i++) {
        tx = x + dir[i][0];
        ty = y + dir[i][1];
        if ((tx > 0) && (ty > 0) && (tx <= r) && (ty <= c) && (map[tx][ty] < map[x][y])) dp[x][y] = std::max(solve(tx, ty), dp[x][y]);
    }
    dp[x][y]++;
    return dp[x][y];
}
int main() {
    std::memset(dp, -1, sizeof(dp));
    int i, j, ans = 0;
    std::cin >> r >> c;
    for (i = 1; i <= r; i++)
        for (j = 1; j <= c; j++) std::cin >> map[i][j];
    for (i = 1; i <= r; i++)
        for (j = 1; j <= c; j++) {
            ans = std::max(solve(i, j), ans);
        }
    std::cout << ans;
    return 0;
}
