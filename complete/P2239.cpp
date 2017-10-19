#include <bits/stdc++.h>
int top, bottom;
int main(){
  int n, i, j;
  std::cin >> n >> i >> j;
  if (n % 2 == 0){
    int ans = 0;
    int tot_layer = n/2;
    int max_layer, layer;
    if (i>tot_layer) max_layer = 2*tot_layer - i+1;
    else max_layer = i;
    if (j<=max_layer) layer = j;
    else if (j>=n-max_layer+1) layer = n - j +1;
         else layer = max_layer;
    bottom = n - (layer-1)*2;
    int start = std::pow(n,2) - std::pow(bottom,2) + 1;
    top = 1;
    i = i - layer + 1;
    j = j - layer + 1;
    if (i==1){
      ans = start - 1 + j;
    }else{
      if(j==bottom){
        ans = start + bottom - 2 + i;
      }
      else{
        if (i==bottom){
          ans = start + bottom * 3 - 2 - j;
        }
        else{
          ans = start + bottom * 4 - 3 - i;
        }
      }
    }
    std::cout << ans;
  }else{
    int ans = 0, tot_layer = (n+1)/2, max_layer, layer, start, top, bottom;
    if (i==tot_layer && j==tot_layer) {
      ans = std::pow(n,2);
      layer = tot_layer;
      i = i - layer + 1;
      j = j - layer + 1;
    }
    else{
      if (i<=tot_layer) max_layer = i;
      else max_layer = 2*tot_layer - i;
      if (j<=max_layer) layer = j;
      else{
        if (j>=n-max_layer+1) layer = n - j + 1;
        else layer = max_layer;
      }
      top = 1;
      bottom = n - (layer - 1)*2;
      start = std::pow(n,2) - std::pow(bottom,2) + 1;
      i = i - layer + 1;
      j = j - layer + 1;
      if (i==1){
        ans = start - 1 + j;
      }else{
        if(j==bottom){
          ans = start + bottom - 2 + i;
        }
        else{
          if (i==bottom){
            ans = start + bottom * 3 - 2 - j;
          }
          else{
            ans = start + bottom * 4 - 3 - i;
          }
        }
      }
    }
    std::cout << ans;
  }
  return 0;
}
