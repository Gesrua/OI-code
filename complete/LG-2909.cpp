#include <algorithm>
#include <cmath>
#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::sort;
int main() {
    int n, m, d, l, s[50010], h[50010] = {};
    std::ios::sync_with_stdio(false);
    cin >> n >> m >> d >> l;
    for (register int i = 1; i <= n; ++i) cin >> s[i];
    sort(s + 1, s + 1 + n);
    int ans = 0;
    int i = 1, j = 1;
    while (s[i] < l) ++i;
    for (; i <= n; ++i) {
        if (s[i] - h[j] * d >= l) {
            ++ans, ++h[j], j = j % m + 1;
        }
    }
    cout << ans;
    return 0;
}