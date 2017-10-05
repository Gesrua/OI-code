#include <bits/stdc++.h>
int main(){
    long long n, x, i, ans = 0, t1, t2;
    std::cin >> n >> x;
    std::cin >> t1;
    for (i=0; i<n-1; i++) {
        std::cin >> t2;
        if (t1 + t2 > x) {
            ans = ans + t1 + t2 - x;
            t1 = t2 - (t1 + t2 - x);
            if (t1 < 0) t1 = 0;
        }
        else t1 = t2;
    }
    std::cout << ans;
    return 0;
}
