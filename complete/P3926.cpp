#include <bits/stdc++.h>
int main(){
  long long t, a, c, p ,q ,r ,x;
  std::cin >> a >> c >> p >> q >> r >> x;
  if (a < c){
    if ((c-a)*p <= x){
      x -= (c-a)*p;
    }else{
      std::cout << a + x/p;
      return 0;
    }
    if (q <= x){
      x -= q;
    }else{
      std::cout << c;
      return 0;
    }
    std::cout << c + x/r;
  }else{
    if (a == c){
      if (q <= x){
        x -= q;
      }else{
        std::cout << c;
        return 0;
      }
      std::cout << c + x/r;
    }
    else {
      std::cout << a + x/r;
    }
  }
  return 0;
}
