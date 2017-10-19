#include <bits/stdc++.h>
int ans, dp[20][20];
int dfs(const int q, const int top){
  if (dp[q][top] != -1) return dp[q][top];
  if (top == 0){
    if (q == 0){
      return dp[q][top] = 1;
    }else{
      return dp[q][top] = dfs(q-1,1);
    }
  }else {
    if (q == 0){
      return dp[q][top] = 1;
    }
    else return dp[q][top] = dfs(q-1,top+1) + dfs(q,top-1);
  }
}
int main(){
  int n;
  std::cin >> n;
  std::memset(dp,-1,sizeof(dp));
  std::cout << dfs(n,0);
  return 0;
}
