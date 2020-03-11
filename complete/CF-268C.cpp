#include <cmath>
#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::min;
int n, m, ans;
int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    int x = min(n, m);
    cout << min(n, m) + 1 << endl;
    for (int i = 0; i <= x; ++i) {
        cout << i << ' ' << m - i << endl;
    }
    return 0;
}
