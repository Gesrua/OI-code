#include <iostream>
int n,m;
bool a[2501][2501];
int dp[2501][2501];
void init() {
    using namespace std;
    memset(a,0,sizeof(a));
    memset(dp,0,sizeof(dp));
    int i,j,temp;
    cin>>n>>m;
    for (i=0; i<n; i++)
        for (j=0; j<m; j++) {
            cin>>temp;
            if (temp == 1) a[i][j] = true;
        }
}
int main() {
    init();

    return 0;
}
