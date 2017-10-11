#include <bits/stdc++.h>
int heap[100000];
void push(int x){
  
}
void del(){
  
}
int main(){
  int i, n, m, x;
  std::cin >> n;
  std::cin >> m;
  std::cin >> heap[1];
  for (i=1;i<n;i++){
    std::cin >> m;
    switch(m){
    case 1:{
      std::cin >> x;
      push(x);
    }
    case 2:{
      std::cout << heap[1];
    }
    case 3:{
      del();
    }
    }
  }
  return 0;
}
