// 在luogu的机器上不开O2,RE
// 在luogu的机器上开O2, AC
// 在自己机器上-O, -O2 都 AC
// 玄学
#include <iostream>
#include <cmath>
using std::min;
using std::max;
int n, m, a[102], dp[110][110][13] = {}, sum[110];
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
const int INF = 210000000;
inline int query(int l, int r){
    // [l, r]
    if (l < 1) l = 1;
    return ((sum[r] - sum[l-1]) % 10 + 10)%10;
}
int dp_min(int l, int r, int k){
    //cerr << l << ' ' << r << ' ' << k << endl;
    if (dp[l][r][k] != INF) return dp[l][r][k];
    if (k == 1){
        return query(l, r);
    }
    for (int i = l; i < r-k+1; ++i){
        dp[l][r][k] = min(dp_min(l, i, k - 1) * query(i + 1, r), dp[l][r][k]);
    }
    return dp[l][r][k];
}
int dp_max(int l, int r, int k){
    //cerr << l << ' ' << r << ' ' << k << endl;
    if (dp[l][r][k] != 0) return dp[l][r][k];
    if (k == 1){
        return query(l, r);
    }
    for (int i = l; i < r; ++i){
        dp[l][r][k] = max(dp_max(l, i, k - 1) * query(i + 1, r), dp[l][r][k]);
    }
    return dp[l][r][k];
}
int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        a[i+n] = a[i];
    }
    sum[0] = 0;
    sum[1] = a[1];
    for (int j = 2; j <= (n<<2); ++j){
        sum[j] = sum[j-1] + a[j];
    }
    int ans_max = 0;
    for (int i = 1; i <= n; ++i){
        ans_max = max(dp_max(i, i + n - 1, m), ans_max);
    }
    for (int i = 1; i <= n; ++i){
        for (int j = i; j <= n<<2; ++j){
            for (int k = 0; k <= m; ++k){
                dp[i][j][k] = INF;
            }
        }
    }
    int ans_min = INF;
    for (int i = 1; i <= n; ++i){
        ans_min = min(dp_min(i, i + n - 1, m), ans_min);
    }
    cout << ans_min << endl << ans_max;
    return 0;
}
// f[开始][结束][已经分的区间数量] = 乘积
// f[i][j][k] = max/min{f[i][x][k-1] * sum(x+1, r) | i <= x < j}
/*

*/