#include <algorithm>
#include <cstdio>
#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;
int per, f[60] = {}, maxl, minl = 100, n = 0, sum = 0;
void dfs(int k, int now, int left) {  // cur 是木棍数， k是凑
    if (k == 0) {
        cout << per;
        exit(0);
    }
    if (now == per) {
        dfs(k - 1, 0, maxl);
    }

    for (int i = min(left, per - now); i >= minl; --i) {
        if (f[i]) {
            --f[i];
            dfs(k, now + i, i);
            ++f[i];
            if (now == 0 || now + i == per) return;
        }
    }
}
int main() {
    int x, t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> x;
        if (x <= 50) {
            maxl = max(maxl, x);
            minl = min(minl, x);
            sum += x;
            ++n;
            // ++a[x];
            ++f[x];
        }
    }
    // std::sort(a+1, a+1+n);
    for (int i = maxl; i <= sum; ++i) {
        if (sum % i == 0) {
            // cerr << endl << i << endl;
            per = i;
            dfs(sum / i, 0, maxl);
        }
    }

    return 0;
}