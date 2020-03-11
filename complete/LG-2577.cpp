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
using std::pair;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int ui;

const int N = 209;

int f[N][N * N], s[N];

struct P {
    int a, b;
    bool operator<(const P& y) const { return b > y.b; }
} a[N];

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    std::memset(f, 1, sizeof(f));
    // cout << f[0][0] << ' ' << f[12][32];
    int n;
    cin >> n;
    rep(i, 1, n) cin >> a[i].a >> a[i].b;
    std::sort(a + 1, a + 1 + n);
    f[0][0] = 0;
    rep(i, 1, n) s[i] = s[i - 1] + a[i].a;
    rep(i, 0, n - 1) {
        rep(j, 0, 40000) {
            int k = s[i] - j;
            f[i + 1][j + a[i + 1].a] =
                std::min(f[i + 1][j + a[i + 1].a],
                         std::max(f[i][j], j + a[i + 1].a + a[i + 1].b));
            f[i + 1][j] = std::min(
                f[i + 1][j], std::max(f[i][j], k + a[i + 1].a + a[i + 1].b));
        }
    }
    int ans = N * N;
    rep(j, 0, 40000) ans = std::min(f[n][j], ans);
    cout << ans;
    return 0;
}