#include <iomanip>
#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;
bool out, flag[10];
int n;
void dfs(int x, int val) {
    // cerr << x << ' ' << val << endl;
    if (val * n >= 98765) return;
    if (x == 0) {
        int a = val * n;
        bool cnt[10] = {};
        for (int i = 1; i <= 5; ++i) {
            if (flag[a % 10] || cnt[a % 10]) return;
            cnt[a % 10] = true;
            a /= 10;
        }
        out = false;
        cout << std::setfill('0') << std::setw(5) << val * n << " / " << std::setfill('0') << std::setw(5) << val << " = " << n << endl;
        return;
    }
    for (int i = 0; i <= 9; ++i) {
        if (!flag[i]) {
            flag[i] = true;
            dfs(x - 1, val * 10 + i);
            flag[i] = false;
        }
    }
}
int main() {
    bool pe = 1;
    while (cin >> n) {
        if (n == 0) return 0;
        if (pe)
            pe = 0;
        else
            cout << endl;
        out = true;
        dfs(5, 0);
        if (out) cout << "There are no solutions for " << n << ".\n";
        // cerr << "done\n";
    }
    return 0;
}