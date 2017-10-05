#include <bits/stdc++.h>
const int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int r, c, map[200][200] = {}, dp[200][200] = {};
int solve(const int x, const int y){
    if (dp[x][y] != 0) return dp[x][y];
    int tx, ty;
    for (int i=0; i<4; i++) {
        tx = x + dir[i][0];
        ty = y + dir[i][1];
        if((map[tx][ty] < map[x][y]) && (tx > 0) && (ty > 0) && (tx <= r) && (tx <= c))
            dp[x][y] = std::max(solve(x+dir[i][0], y+dir[i][1]), dp[x][y]);
    }
    dp[x][y]++;
    return dp[x][y];
}
int main(int argc, char const *argv[]) {
    int i, j, ans = 0;
    std::cin >> r >> c;
    for (i=1; i<=r; i++)
        for (j=1; j<=c; j++)
            std::cin >> map[i][j];
    for (i=1; i<=r; i++)
        for (j=1; j<=c; j++) {
            ans = std::max(solve(i, j), ans);
        }
    std::cout << ans;
    return 0;
}
