#include <algorithm>
#include <iostream>
struct cell {
    int p, a;
} a[5001];
bool cmp(cell a, cell b) { return a.p < b.p; }
int main() {
    using namespace std;
    int ans = 0, n, m, i;
    cin >> n >> m;
    for (i = 1; i <= m; i++) cin >> a[i].p >> a[i].a;
    sort(a + 1, a + 1 + m, cmp);
    for (i = 1; a[i].a < n; i++) {
        n -= a[i].a;
        ans += a[i].a * a[i].p;
    }
    if (n != 0) ans += a[i].p * n;
    cout << ans;
    return 0;
}
