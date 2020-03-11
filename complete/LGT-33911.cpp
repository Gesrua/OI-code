#include <iostream>
int t1, t2, s, n;
bool a[10000001] = {};
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;
int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    s = 0;
    char c1, c2;
    for (register int i = 1; i <= n / 2; ++i) {
        cin >> c1 >> c2;
        t1 = c1 - '0';
        t2 = c2 - '0';
        a[i + 1] = (t1 + t2 + a[i]) >> 1;
        a[i] = (t1 + t2 + a[i]) % 2;
    }
    for (register int i = n / 2 + 1; i >= 1; --i) {
        cout << a[i];
    }
    return 0;
}