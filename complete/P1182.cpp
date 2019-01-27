#include <cmath>
#include <cstdio>
#include <iostream>
int n, m, a[100001], ans, l = 0, r = 0;
void init() {
    using namespace std;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (l < a[i]) l = a[i];
        r += a[i];
    }
}
bool check(int x) {
    int pos = 0, sum = 0, t = m;
    while (t > 0 && pos < n) {
        if (sum + a[pos] > x) {
            --t;
            sum = 0;
        }
        sum += a[pos];
        ++pos;
    }
    if (t > 0)
        return true;
    else
        return false;
}
void solve() {
    int mid;
    while (l != r) {
        mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
        // std::cerr << l << ' ' << r << std::endl;
    }
    ans = l;
}
int main() {
    init();
    solve();
    std::printf("%d\n", ans);
    return 0;
}
