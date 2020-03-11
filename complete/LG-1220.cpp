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
using std::min;

int l[60], p[60], f[60][60][2], s[60], n, c;

inline int q(int l, int r) { return s[l - 1] + s[n] - s[r]; }
inline int d(int x, int y) { return std::abs(l[y] - l[x]); }

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n >> c;
    rep(i, 1, n) cin >> l[i] >> p[i], s[i] = s[i - 1] + p[i];
    std::memset(f, 0x3f, sizeof(f));
    f[c][c][0] = f[c][c][1] = 0;
    // 0 left
    // 1 right
    per(i, c, 1) {
        rep(j, c, n) {
            int pow = q(i, j);
            f[i - 1][j][0] = min(f[i][j][0] + pow * d(i - 1, i),
                                 f[i][j][1] + pow * d(i - 1, j));
            f[i][j + 1][1] = min(f[i][j][0] + pow * d(i, j + 1),
                                 f[i][j][1] + pow * d(j, j + 1));
        }
    }
    cout << min(f[1][n][0], f[1][n][1]);
    return 0;
}