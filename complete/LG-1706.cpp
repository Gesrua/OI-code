#include <cstring>
#include <iomanip>
#include <iostream>
bool flag[12] = {};
int n, s[12];
using std::cerr;
using std::cout;
using std::endl;
void dfs(int x) {
    if (x == n) {
        for (int i = 0; i < n; ++i) {
            cout << std::setw(5) << s[i];
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (flag[i]) {
            // cerr << x << ' ' << i << endl;
            flag[i] = false;
            s[x] = i;
            dfs(x + 1);
            flag[i] = true;
        }
    }
}
int main() {
    cout.flags(std::ios::right);
    std::memset(flag, 1, sizeof(flag));
    std::cin >> n;
    dfs(0);
    return 0;
}