
#include <bits/stdc++.h>
int n ,m, a[103], dp[200][200][10], sum[200][200];
int acc(const int l, const int r){
  if (sum[l][r] != -1) return sum[l][r];
  if (l == r) return a[l];
  return sum[l][r] = acc(l,r-1) + a[r];
}
inline int mod(int x){
  return (x%10+10)%10;
}
int solve_max(const int l, const int r, const int k){
  // std::cout << l << ' ' << r << ' ' << k << std::endl;
  if (dp[l][r][k] != -1) return dp[l][r][k];
  if (k == 0) {
    return mod(acc(l,r));
  }
  int i, ans = 0;
  for (i=l;i<r;i++){
    ans = std::max(ans, mod(acc(l,i)) * solve_max(i+1,r,k-1));
  }
  return dp[l][r][k] = ans;
}
int solve_min(const int l, const int r, const int k){
  // std::cout << l << ' ' << r << ' ' << k << std::endl;
  if (dp[l][r][k] != -1) return dp[l][r][k];
  if (k == 0) {
    return mod(acc(l,r));
  }
  int i, ans = 21000000;
  for (i=l;i<r;i++){
    ans = std::min(ans, mod(acc(l,i)) * solve_min(i+1,r,k-1));
    // std::cout << l << ' ' << r << ' ' << k << ' ';
    // std::cout << mod(acc(l,i)) * solve_min(i+1,r,k-1) << '\n';
  }
  // std::cout << std::endl;
  // std::cout << l << ' ' << r << ' ' << k << ' ' << ans << std::endl;
  return dp[l][r][k] = ans;
}
int main(){
  int i, ans = 0;
  std::cin >> n >> m;
  std::memset(sum,-1,sizeof(sum));
  std::memset(dp,-1,sizeof(dp));
  for (i=1;i<=n;i++){
    std::cin >> a[i];
    a[i+n] = a[i];
  }
  // for (i=1;i<=n*2;i++){
  //   for (int j = i;j<=n*2;j++)
  //     std::cout << i << ' ' << j << ' ' << acc(i,j) << std::endl;
  // }
  ans = 21000000;
  for (i=1;i<=n;i++){
    ans = std::min(solve_min(i,i+n-1,m-1), ans);
  }
  std::cout << ans << std::endl;
  ans = 0;
  std::memset(dp,-1,sizeof(dp));
  for (i=1;i<=n;i++){
    ans = std::max(solve_max(i,i+n-1,m-1), ans);
  }
  std::cout << ans << std::endl;
  // std::cout << solve(4,7,1);
  // std::cout << (acc(4,6)%10) * (a[7] % 10);
  return 0;
}
