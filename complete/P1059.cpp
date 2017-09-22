#include <iostream>
int main(){
  int n, sum = 0, t;
  bool a[1002] = {};
  using namespace std;
  cin >> n;
  for(int i = 0;i < n;i++){
    cin >> t;
    if (a[t] == false){
      a[t] = true;
      sum++;
    }
  }
  cout << sum << endl;
  for (int i = 0;i<=1000;i++){
    if (a[i]) cout<<i<<' ';
  }
  return 0;
}
