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
using std::max;
using std::min;
using std::pair;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int ui;
int a[500] = {}, f[500][500] = {}, pre[500] = {};
inline int q(int l, int r) { return pre[r] - pre[l - 1]; }
const int inf = 0x3f3f3f3f;
int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, _n;
    cin >> n;
    _n = n;
    rep(i, 1, n) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    n *= 2;
    rep(i, 1, n) { pre[i] = pre[i - 1] + a[i]; }

    rep(len, 2, _n) {
        rep(i, 1, n) {
            int j = i + len - 1;
            if (j > n) break;
            f[i][j] = inf;
            rep(k, i, j - 1) f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
            f[i][j] += q(i, j);
        }
    }
    int ans = inf;
    rep(i, 1, _n) ans = min(ans, f[i][i + _n - 1]);
    cout << ans << endl;

    rep(len, 2, _n) {
        rep(i, 1, n) {
            int j = i + len - 1;
            if (j > n) break;
            f[i][j] = 0;
            rep(k, i, j - 1) f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j]);
            f[i][j] += q(i, j);
        }
    }
    ans = 0;
    rep(i, 1, _n) ans = max(ans, f[i][i + _n - 1]);
    cout << ans << endl;
    return 0;
}