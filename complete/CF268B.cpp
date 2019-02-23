#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
int main() {
    int n;
    std::ios::sync_with_stdio(false);
    cin >> n;
    long long ans = 0;
    for (int i = 1; i <= n; ++i) ans += (n - i) * i;
    ans += n;
    cout << ans;
    return 0;
}
