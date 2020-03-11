#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::max;
int main() {
    int now, n, prev, ans;
    std::ios::sync_with_stdio(false);
    cin >> n >> prev;
    ans = prev;
    for (int i = 1; i < n; ++i) {
        cin >> now;
        ans += max(0, now - prev);
        prev = now;
    }
    cout << ans;
    return 0;
}