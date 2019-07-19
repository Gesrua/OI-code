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
#define rep(i, l, r) for (register int i = (l); i <= (r); ++i)
#define per(i, l, r) for (register int i = (l); i >= (r); --i)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int ui;

int g[209][209], p[1001];

int f[1001][209][209];

#define m(x, y, z) (std::min(x, std::min(y, z)))
#define cm(x, y) x = std::min(x, y)

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::memset(f, 0x3f, sizeof(f));
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int l, n;
    cin >> l >> n;
    rep(i, 1, l) rep(j, 1, l) cin >> g[i][j];
    rep(i, 1, n) cin >> p[i];
    f[0][2][3] = 0, p[0] = 1;
    rep(i, 0, n - 1) rep(y, 1, l) rep(z, 1, l) {
        int x = p[i];
        if (x == y || y == z || x == z) continue;
        if (p[i + 1] != y && p[i + 1] != z)
            cm(f[i + 1][y][z], f[i][y][z] + g[x][p[i + 1]]);
        if (p[i + 1] != x && p[i + 1] != z)
            cm(f[i + 1][x][z], f[i][y][z] + g[y][p[i + 1]]);
        if (p[i + 1] != x && p[i + 1] != y)
            cm(f[i + 1][x][y], f[i][y][z] + g[z][p[i + 1]]);
    }
    int ans = 0x3f3f3f3f;
    rep(y, 1, l) rep(z, 1, l) ans = std::min(f[n][y][z], ans);
    cout << ans;
    return 0;
}