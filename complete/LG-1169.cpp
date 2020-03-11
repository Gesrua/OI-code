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

const int N = 2010;

int n, m, a[N][N], l[N][N], r[N][N], h[N][N], f[N][N];

inline int min(int x, int y, int z) { return std::min(x, std::min(y, z)); }
inline int min(int x, int y) { return std::min(x, y); }

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n >> m;
    rep(i, 1, n) rep(j, 1, m) cin >> a[i][j];
    rep(i, 1, n) {
        l[i][1] = 1;
        rep(j, 2, m) if (a[i][j] != a[i][j - 1]) l[i][j] = l[i][j - 1] + 1;
        else l[i][j] = 1;
    }
    rep(i, 1, n) {
        r[i][m] = 1;
        per(j, m - 1, 1) if (a[i][j] != a[i][j + 1]) r[i][j] = r[i][j + 1] + 1;
        else r[i][j] = 1;
    }
    rep(j, 1, m) {
        h[1][j] = 1;
        rep(i, 2, n) if (a[i][j] != a[i - 1][j]) h[i][j] = h[i - 1][j] + 1;
        else h[i][j] = 1;
    }

    int ans = 0;
    rep(i, 1, n) rep(j, 1, m) {
        if (a[i][j] == a[i - 1][j - 1])
            f[i][j] = min(f[i - 1][j - 1] + 1, h[i][j], l[i][j]);
        else
            f[i][j] = 1;
        ans = std::max(ans, f[i][j]);
    }
    cout << ans * ans << endl;

    ans = 0;
    int ht = 0, lt = 0, rt = 0;
    rep(j, 1, m) rep(i, 1, n) {
        if (a[i][j] != a[i - 1][j])
            lt = min(l[i][j], lt), rt = min(r[i][j], rt);
        else
            lt = l[i][j], rt = r[i][j];
        ans = std::max(ans, h[i][j] * (lt + rt - 1));
    }

    cout << ans;
    return 0;
}