#include <bits/stdc++.h>
std::string solve(int n){
    std::string s, ans;
    while (n) {
        s = s + char((n % 2)+'0');
        n /= 2;
    }
    for (int i = s.size()-1; i>=0; i--) {
        if (s[i] == '1') {
            if (i == 0) {
                ans += "2(0)+";
                continue;
            }
            if (i == 1) {
                ans += "2+";
                continue;
            }
            if (i == 2) {
                ans += "2(2)+";
                continue;
            }
            if (i == 3) {
                ans+= "2(2+2(0))+";
                continue;
            }
            ans += "2(";
            ans += solve(i);
            ans += ")+";
        }
    }
    return ans.substr(0,ans.size()-1);
}
int main() {
    int n;
    std::cin >> n;
    std::cout << solve(n);
    return 0;
}
