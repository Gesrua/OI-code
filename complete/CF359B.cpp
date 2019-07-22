#include <iostream>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cin;
using std::cout;
int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    if (k == 0) {
        per(i, 2 * n, 1) cout << i << ' ';
        return 0;
    }
    cout << 1 << ' ' << k + 1 << ' ';
    per(i, 2 * n, 2) {
        if (i == k + 1) continue;
        cout << i << ' ';
    }
    return 0;
}