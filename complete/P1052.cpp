#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int L, S, T, M;
unsigned int a[200], dp[500000], st[500000] = {};
int main(){
    cin >> L;
    cin >> S >> T >> M;
     int i, j, k, n;
    a[0] = 0;
    for (i = 1; i <= M; ++i){
        cin >> a[i];
    }
    sort(a+1, a+1+M);
    n = 0;
    for (i = 1; i <= M; ++i){
        // a[i] = a[i-1] + (a[i] - a[i-1])%2520; 不可修改 a[i] 有后效性
        k = a[i] - a[i-1];
        if (k >= 2520){
            k %= 2520;
            k += 2520;
        }
        n += k;
        st[n] = 1;
    }
    dp[0] = 0;
    for (i = 1; i <= n + T; ++i){
        dp[i] = M;
        for (j = S; j <= T; ++j){
            if (i-j>=0){
                dp[i] = min(dp[i-j] + st[i], dp[i]);
            }
        }
    }
    unsigned int ans = M;
    for (i = n; i <= n + T; ++i){
        ans = min(ans, dp[i]);
    }
    cout << ans;
    return 0;
}