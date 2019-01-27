#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
typedef long long LL;
int main() {
    LL n, k, m, x, t, b = 10;
    cin >> n >> t >> k >> x;
    m = 1;
    while (k) {
        if (k & LL(1)) {
            m *= b;
            m %= n;
        }
        b = b * b;
        b %= n;
        k >>= 1;
    }
    m *= t % n;
    m %= n;
    // cerr << x << endl;
    cout << (x + m) % n;
    return 0;
}