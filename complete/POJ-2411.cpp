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

const int M = 12;

int v[1 << M];
ll f[2][1 << M];

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, m;
    while (cin >> n >> m && n) {
        for (int i = 0; i < 1 << m; ++i) {
            bool cnt = 0, odd = 0;
            for (int j = 0; j < m; ++j)
                if ((i >> j) & 1)
                    odd |= cnt, cnt = 0;
                else
                    cnt ^= 1;
            v[i] = !(odd || cnt);
        }
        std::memset(f, 0, sizeof(f));
        f[0][0] = 1;
        rep(i, 1, n) {
            for (int j = 0; j < 1 << m; ++j) {
                f[i & 1][j] = 0;
                for (int k = 0; k < 1 << m; ++k) {
                    if (((j & k) == 0) && (v[j | k])) f[i & 1][j] += f[(i - 1) & 1][k];
                }
            }
        }
        cout << f[n & 1][0] << endl;
    }
    return 0;
}