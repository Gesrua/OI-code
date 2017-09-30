#include <iostream>
struct cell{
  int num, next;
}a[101];
void del(int now){
  a[now].next = a[a[now].next].next;
}
int main(){
  int n, m;
  std::cin >> n >> m;
  for (int i=1;i<=n;i++){
    a[i].num = i;
    a[i].next = i+1;
  }
  a[n].next = 1;
  a[0].next = 1;
  int i, now = 0;
  while (n>0){
    for (i=1;i<m;i++){
      now = a[now].next;
    }
    std::cout << a[a[now].next].num << ' ';
    n--;
    del(now);
  }
  return 0;
}
