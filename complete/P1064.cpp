#include <bits/stdc++.h>
struct cell{
  int v, w;
}a[62][4];
int m, n, cur[62] = {};
void init(){
  using std::cin;
  std::ios::sync_with_stdio(false);
  cin >> n >> m;
  int i, v, p ,q;
  for (i=1;i<=m;i++){
    cin >> v >> p >> q;
    if (q==0){
      a[i][0].v = v;
      a[i][0].w = v * p;
    }else{
      if (cur[q] == 0){
        cur[q]++;
        a[q][1].v = a[q][0].v + v;
        a[q][1].w = a[q][0].w + v*p;
      }
      else{
        cur[q]=3;
        a[q][2].v = a[q][0].v + v;
        a[q][2].w = a[q][0].w + v*p;
        a[q][3].v = a[q][1].v + v;
        a[q][3].w = a[q][1].w + v*p;
      }
    }
  }
}
int main(){
  init();
  int dp[32002] = {};
  int i, j, k;
  for (i=1;i<=m;i++){
    if (a[i][0].v > 0){
      for (j=n;j>=0;j--){
        for (k=0;k<=cur[i];k++){
          if (j+a[i][k].v > n) continue;
          if ((j==0) && (dp[a[i][k].v] < a[i][k].w)) dp[a[i][k].v] = a[i][k].w;
          if (dp[j] == 0) continue;
          if (dp[j+a[i][k].v] < dp[j] + a[i][k].w) dp[j+a[i][k].v] = dp[j] + a[i][k].w;
        }
      }
    }
  }
  int ans = 0;
  for (i=1;i<=n;i++)
    if (dp[i] > ans) ans = dp[i];
  std::cout << ans;
  return 0;
}
