#include <bits/stdc++.h>
int main(){
  int dp[100000];
  std::memset(dp,-1,sizeof(dp));
  dp[0] = 0;
  int t, m, i, ans = 0, v, s, far, j;
  std::cin >> t >> m;
  far = 0;
  for (i=0;i<m;i++){
    std::cin >> s >> v;
    for (j=0;j<=t-s;j++){
      if (dp[j] != -1){
        dp[j+s] = std::max(dp[j+s], dp[j] + v);
        ans = std::max(dp[j+s], ans);
      }
    }
  }
  std::cout << ans;
  return 0;
}
