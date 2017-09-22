#include <iostream>
#include <string>
int main(){
  std::string s, ans;
  int j, n, i, ans_n;
  std::cin >> n;
  std::cin >> ans;
  ans_n = 1;
  for (i=2;i<=n;i++){
    std::cin >> s;
    if (s.size() > ans.size()){
      ans = s;
      ans_n = i;
    }
    if (s.size() == ans.size()){
      for (j=0;j<s.size();j++){
        if (s[j] > ans[j]){
          ans = s;
          ans_n = i;
        }
        if (s[j] < ans[j]) break;
      }
    }
  }
  std::cout << ans_n << std::endl << ans;
  return 0;
}
