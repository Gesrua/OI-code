#include <bits/stdc++.h>
double abs(double x){
  if (x>=0) return x;
  else return -x;
}
int main(){
  double a, b, l, i, j, ans_a, ans_b;
  double min = 2100000000;
  double t ,c;
  std::cin >> a >> b >> l;
  c = a/b;
  for (i=1;i<=l;i++){
    for (j=1;j<=l;j++){
      t = i/j - c;
      if (t>=0 && t < min){
        min =  t;
        ans_a = i;
        ans_b = j;
      }
    }
  }
  std::cout << ans_a << ' ' << ans_b;
  return 0;
}
