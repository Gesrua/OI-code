#include <bits/stdc++.h>
int e, map[20][20]={},dp[20][20][30]={};
void init(){
  std::cin >> e;
  int x,y,z;
  while(std::cin>>x>>y>>z){
    map[x][y] = z;
  }
}
void solve(int x,int m,int l){
  int y = l - x + 1;
  int n = l - m + 1;
  if (x<1 || y<1 || m<1 || n<1 || x>e || y>e || m>e || n>e || l<=0 || dp[x][m][l] != 0) return;
  solve(x,m,l-1);
  solve(x-1,m,l-1);
  solve(x,m-1,l-1);
  solve(x-1,m-1,l-1);
  int t = std::max(std::max(dp[x][m][l-1],dp[x-1][m][l-1]), std::max(dp[x][m-1][l-1],dp[x-1][m-1][l-1]));
  if (x == m){
    dp[x][m][l] = map[x][y] + t;
  }
  else{
    dp[x][m][l] = map[x][y] + map[m][n] + t;
  }
}
int main(){
  init();
  solve(e,e,e+e-1);
  std::cout << dp[e][e][e+e-1];
  return 0;
}
