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

const int N = 3000, inf = 0x3f3f3f3f;

int a[N], b[N], f[N][N];
int t = 0, upd = 0, ans = inf, n;

void dp() {
    std::memset(f, 0x3f, sizeof(f));
    f[0][0] = 0;
    rep(i, 1, n) {
        t = f[i - 1][0], upd = inf;
        rep(j, 1, n) {
            t = std::min(t, f[i - 1][j]);
            upd = std::min(upd, t + std::abs(a[i] - b[j]));
            f[i][j] = upd;
        }
    }
    rep(j, 1, n) ans = std::min(ans, f[n][j]);
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) b[i] = a[i];
    std::sort(b + 1, b + 1 + n);
    dp();
    std::sort(b + 1, b + 1 + n, std::greater<int>());
    dp();
    cout << ans;
    return 0;
}