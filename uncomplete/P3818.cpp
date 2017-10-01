#include <bits/stdc++.h>
struct cell{
  bool flag;
  int x, y, s;
};
int main(int argc, char const *argv[]) {
  int h, w, d, r, i, j;
  std::cin >> h >> w >> d >> r;
  bool map[1002][1002] = {0};
  char c;
  for (i=1;i<=h;i++)
    for (j=1;j<=w;j++){
      std::cin >> c;
      if (c == '.') map[i][j] = true;
    }
  std::queue<cell> q;
  q.push(cell{flag = false,x=1,y=1,s=0});
  return 0;
}
