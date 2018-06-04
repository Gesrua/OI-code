#include <iostream>
#include <cmath>
#include <cstring>
#include <ctime>
int n,m;
bool a[2501][2501] = {};
int dp[2501][2501] = {};
int col[2501][2501] = {}, row[2501][2501] = {}, rowr[2501][2502] = {};
void init(){
    using namespace std;
    ios::sync_with_stdio(false);
    memset(a,0,sizeof(a));
    memset(dp,0,sizeof(dp));
    register int i,j,temp;
    cin>>n>>m;
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++) {
            cin >> temp;
            if (temp == 1) a[i][j] = true;
            else {
                row[i][j] = row[i][j-1] + 1;
                col[i][j] = col[i-1][j] + 1;
            }
        }
    // cerr << endl;
    // for (i = 1; i <= n; ++i){
    //     for (j = 1; j <= m; ++j)
    //         cerr << row[i][j] << ' ';
    //     cerr << endl;
    // }
    // cerr << endl;
    // for (i = 1; i <= n; ++i){
    //     for (j = 1; j <= m; ++j)
    //         cerr << col[i][j] << ' ';
    //     cerr << endl;
    // }
    for (i = 1; i <= n; ++i)
        for (j = m; j >= 1; --j)
            if (a[i][j] == 0) rowr[i][j] = rowr[i][j+1] + 1;
    // cerr << endl;
    // for (i = 1; i <= n; ++i){
    //     for (j = 1; j <= m; ++j)
    //         cerr << rowr[i][j] << ' ';
    //     cerr << endl;
    // }
}
inline int min(int a, int b, int c){
    return std::min(std::min(a, b), c);
}
int main(){
    unsigned int time_start = std::clock();
    using std::max;
    init();
    register int i, j, ans = 0;
    for (i = 1; i <= n; ++i){
        for (j = 1; j <= m; ++j){
            if (a[i][j]){
                dp[i][j] = max(
                    min(dp[i-1][j-1] + 1, row[i][j-1] + 1, col[i-1][j] + 1),
                    min(dp[i-1][j+1] + 1, col[i-1][j] + 1, rowr[i][j+1] + 1)
                );
                if (dp[i][j] > ans) ans = dp[i][j];
            }
        }
    }
    std::cout << ans << std::endl << std::clock()-time_start;
    
    return 0;
}
