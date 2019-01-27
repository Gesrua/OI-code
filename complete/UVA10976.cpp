#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
struct node {
    long long x, y;
    node(long long _x, long long _y) { x = _x, y = _y; }
    node() { x = 0, y = 0; }
} a[10000];
int main() {
    long long k;
    while (cin >> k) {
        int cnt = 0;
        // cerr << k << endl;
        for (long long y = k + 1; y <= 2 * k; ++y) {
            long long x = k * y / double(y - k) + 1e-3;
            // cerr << x << ' ' << y << endl;
            if (k * x + k * y == x * y) {
                ++cnt, a[cnt].x = x, a[cnt].y = y;
            }
        }
        // cerr << "here\n";
        cout << cnt << endl;
        for (int i = 1; i <= cnt; ++i) {
            std::printf("1/%lld = 1/%lld + 1/%lld\n", k, a[i].x, a[i].y);
        }
    }
    return 0;
}