#include <bits/stdc++.h>
int main() {
    int n, m, ans_chang = 0, ans_zheng = 0;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == j) {
                ans_zheng += (n - i + 1) * (m - j + 1);
            } else {
                ans_chang += (n - i + 1) * (m - j + 1);
            }
        }
    }
    std::cout << ans_zheng << ' ' << ans_chang;
    return 0;
}
