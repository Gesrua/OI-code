#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;
int main() {
    int n;
    long long a[100][2000] = {};
    cin >> n;
    a[0][0] = 1;
    if (n % 2 != 0) {
        cout << "nonono.";
        return 0;
    }
    n /= 2;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            a[i][j + 1] += a[i][j];
            a[i + 1][j] += a[i][j];
        }
    }
    cout << a[n][n];
    return 0;
}
