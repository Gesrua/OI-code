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
#define R(i, n) for (int i = 0; i < n; ++i)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int ui;

const int N = 21;

int n, g[N][N], f[1 << N][N];

void s1() {
    for (int i = 2; i <= (1 << n) - 1; ++i) {
        R(u, n) if ((1 << u) & i) R(v, n) if ((u != v) && ((1 << v) & i)) {
            f[i][v] = std::min(f[i ^ (1 << v)][u] + g[u][v], f[i][v]);
        }
    }
}

void s2() {
    for (int i = 1; i < (1 << n) - 1; ++i)
        R(u, n) if ((1 << u) & i) R(v, n) if (u != v && !((1 << v) & i)) {
            f[i | (1 << v)][v] =
                std::min(f[i | (1 << v)][v], f[i][u] + g[u][v]);
        }
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::memset(f, 0x3f, sizeof(f));
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n;
    R(i, n) R(j, n) cin >> g[i][j];
    f[1][0] = 0;

    s1();
    // s2(); // 两种写法都可

    cout << f[(1 << n) - 1][n - 1];
    return 0;
}