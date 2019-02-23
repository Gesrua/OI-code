#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
int main() {
    int n;
    std::ios::sync_with_stdio(false);
    cin >> n;
    int z[1000], k[1000];
    for (int i = 1; i <= n; ++i) {
        cin >> z[i] >> k[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;
            if (z[i] == k[j]) ++ans;
        }
    }
    cout << ans;
    return 0;
}
