#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;
int main() {
    int d, n, a[200][200] = {};
    long long s[200][200] = {};
    int x, y, k;
    cin >> d >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y >> k;
        a[x + 1][y + 1] = k;
    }
    for (int i = 1; i <= 129; ++i) {
        for (int j = 1; j <= 129; ++j) {
            s[i][j] = a[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
    int t1, t2, l1, l2, cnt = 0;
    long long cur, ans = -1;
    for (int i = 1; i <= 129; ++i) {
        for (int j = 1; j <= 129; ++j) {
            t1 = max(i - d, 1) - 1;
            t2 = max(j - d, 1) - 1;
            l1 = min(129, i + d);
            l2 = min(129, j + d);
            cur = s[l1][l2] + s[t1][t2] - s[l1][t2] - s[t1][l2];
            if (cur > ans) {
                ans = cur;
                cnt = 1;
                continue;
            }
            if (cur == ans) {
                ++cnt;
            }
            // ans = max(ans, cur);
        }
    }
    cout << cnt << ' ' << ans;
    return 0;
}