#include <algorithm>
#include <iostream>
int main() {
    int n, sum = 0, a[101] = {};
    using namespace std;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    std::sort(a, a + n);
    sum = std::unique(a, a + n) - a;
    cout << sum << endl;
    for (int i = 0; i < sum; ++i) cout << a[i] << ' ';
    return 0;
}
