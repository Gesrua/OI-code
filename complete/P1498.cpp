#include <bits/stdc++.h>
char map[(1<<12)][(1<<12)];
void solve(int x, int y, int now){
  if (now == 1){
    map[x][y] = ' ';
    map[x][y+1] = '/';
    map[x][y+2] = '\\';
    map[x][y+3] = ' ';
    map[x+1][y] = '/';
    map[x+1][y+1] = '_';
    map[x+1][y+2] = '_';
    map[x+1][y+3] = '\\';
    return;
  }
  solve(x, y+(1<<(now-1)), now-1);
  solve(x+(1<<(now-1)), y, now-1);
  solve(x+(1<<(now-1)), y+(1<<(now)), now-1);
}
int main(int argc, char const *argv[]) {
  int n;
  std::ios::sync_with_stdio(false);
  std::cin >> n;
  for (int i=1;i<=(1<<n);i++){
    for (int j=1;j<=(1<<(n+1));j++)
      map[i][j] = ' ';
  }
  solve(1, 1, n);
  for (int i=1;i<=(1<<n);i++){
    for (int j=1;j<=(1<<(n+1));j++)
      std::cout << map[i][j];
    std::cout << std::endl;
  }
  return 0;
}
