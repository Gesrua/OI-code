#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
const int val[] = {0, 1, 2, 3, 5, 10, 20};
int main() {
    int dp[1010] = {};
    int a[10];
    dp[0] = 1;
    for (register int i = 1; i <= 6; ++i) {
        cin >> a[i];
        for (register int k = 0; k < a[i]; ++k) {
            for (register int j = 1000; j >= val[i]; --j) {
                if (dp[j - val[i]]) dp[j] = dp[j - val[i]];
            }
        }
    }
    int ans = 0;
    for (register int i = 1; i <= 1000; ++i) {
        if (dp[i]) ++ans;
    }
    cout << "Total=" << ans;
    return 0;
}