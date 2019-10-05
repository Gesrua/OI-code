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
typedef unsigned long long ull;

const int N = 3833, inf = 0x3f3f3f3f;

int f[2][N][2], u[N], n, b;

void init(int a[][2]) {
    for (register int i = 0; i < N; ++i) a[i][0] = a[i][1] = -inf;
}

void run() {
    rep(i, 2, n) {
        init(f[i & 1]);
        f[i & 1][0][0] = f[(i - 1) & 1][0][0];
        rep(j, 1, std::min(i, b)) {
            f[i & 1][j][1] = std::max(f[(i - 1) & 1][j - 1][0], f[(i - 1) & 1][j - 1][1] + u[i]);
            f[i & 1][j][0] = std::max(f[(i - 1) & 1][j][0], f[(i - 1) & 1][j][1]);
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n >> b;
    rep(i, 1, n) cin >> u[i];
    int ans = 0;
    init(f[0]), init(f[1]), f[1][0][0] = 0, f[1][1][1] = 0, run();
    ans = std::max(f[n & 1][b][0], f[n & 1][b][1]);
    init(f[0]), init(f[1]), f[1][1][1] = u[1], run();
    ans = std::max(ans, f[n & 1][b][1]);
    cout << ans << endl;
    return 0;
}