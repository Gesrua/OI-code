#include <algorithm>
#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
int a[200010];
int main() {
    int n;
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    std::sort(a, a + n);
    register int t = a[0], cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (t != a[i]) {
            cout << t << ' ' << cnt << endl;
            cnt = 1;
            t = a[i];
            // continue;
        } else {
            ++cnt;
        }
    }
    cout << t << ' ' << cnt;
    return 0;
}