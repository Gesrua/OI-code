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
    for (j=s;j<=t;j++){
      dp[j] = std::max(dp[j], dp[j-s] + v);
    }
  }
  std::cout << dp[t];
  return 0;
}
