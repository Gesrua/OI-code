#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::min;
using std::pair;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int ui;
__uint128_t a[60] = {}, f[60][60] = {}, ans, inf;
void out(__uint128_t x) {
    if (x == 0) return;
    out(x / 10);
    cout << int(x % 10);
}
int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n;
    inf = 327828;
    inf *= inf;
    inf *= inf;
    inf *= inf;

    cin >> n;
    rep(i, 1, n) {
        int t;
        cin >> t;
        a[i] = t;
    }
    rep(len, 2, n - 1) {
        rep(i, 1, n - len) {
            int j = i + len;
            f[i][j] = inf;
            rep(k, i + 1, j - 1) f[i][j] =
                min(f[i][j], f[i][k] + f[k][j] + a[i] * a[k] * a[j]);
        }
    }
    if (f[1][n] == 0)
        cout << '0';
    else
        out(f[1][n]);
    return 0;
}