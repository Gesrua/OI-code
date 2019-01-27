#include <algorithm>
#include <cstdio>
#include <iostream>
int n, m, a[100001];
using std::scanf;
bool check(int x) {
    int t = 1, last = 1, pos = 1;
    while (pos <= n) {
        if (a[pos] - a[last] >= x) {
            ++t;
            last = pos;
        }
        ++pos;
    }
    return t >= m;
}
int main() {
    int mid, l = 0, r = 1e9;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    std::sort(a + 1, a + 1 + n);
    while (l < r) {
        mid = (l + r + 1) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
        // std::cerr << l << ' ' << r << std::endl;
    }
    std::printf("%d", r);
    return 0;
}
