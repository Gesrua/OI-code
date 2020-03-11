#include <iostream>
int main() {
    int n, a[10000];
    using std::cerr;
    using std::cin;
    using std::cout;
    using std::endl;
    std::ios::sync_with_stdio(false);
    cin >> n;
    int k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cin >> k;
    int l = 1, r = n;
    while (l < r) {
        // cerr << l << ' ' << r << endl;
        int mid = ((l + r) >> 1);
        if (a[mid] < k) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    if (a[l] == k)
        cout << l;
    else
        cout << -1;
    return 0;
}