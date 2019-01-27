#include <algorithm>
#include <cmath>
#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
const int MOD = 10007;
int fp(int a, int n) {
    int ans = 1;
    a %= MOD;
    while (n) {
        if (n & 1) {
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        n >>= 1;
    }
    return ans % MOD;
}
int gcd(int x, int y) { return x == 0 ? y : gcd(y % x, x); }
int main() {
    int a, b, k, n, m, t, x;
    int arr[10001];
    cin >> a >> b >> k >> n >> m;
    long long ans = fp(a, n) * fp(b, m) % MOD;
    if (k - n < n) n = k - n;
    int s = k - n + 1;
    for (int i = k - n + 1; i <= k; ++i) {
        arr[i] = i;
    }
    for (int i = 2; i <= n; ++i) {
        t = i;
        for (int j = k - n + 1; j <= k; ++j) {
            x = gcd(std::min(arr[j], t), std::max(arr[j], t));
            t /= x;
            arr[j] /= x;
        }
    }

    for (int i = k - n + 1; i <= k; ++i) {
        ans = ans * (arr[i] % MOD) % MOD;
    }
    cout << ans;
    return 0;
}