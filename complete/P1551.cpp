#include <bits/stdc++.h>
int i, n, m, p, a[5001] = {};
int find(int x){
  if (a[x] == x) return x;
  return a[x] = find(a[x]);
}
void he(int u,int v){
  u = find(u);
  v = find(v);
  if (u != v) a[u] = v;
}
int main(){
  using std::cin;
  using std::cout;
  std::ios::sync_with_stdio(false);
  cin >> n >> m >> p;
  int x, y, i;
  for (i=1;i<=n;i++) a[i] = i;
  for (i=0;i<m;++i){
    cin >> x >> y;
    if (find(x) != find(y)) he(x, y);
  }
  for (i=0;i<p;i++){
    cin >> x >> y;
    if (find(x) == find(y)) cout << "Yes\n";
    else cout << "No\n";
  }
  return 0;
}
