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

const int N = 310;
char s[N];

const int MOD = 1e9;
int f[N][N];

// int calc(int l, int r) {
//     // cerr << l << ' ' << r << endl;
//     if (f[l][r] != -1) return f[l][r];
//     if (l == r) return f[l][r] = 1;
//     int ret = 0;
//     rep(k, l + 1, r) {
//         if (s[k] == s[l]) {
//             (ret += (ll)calc(l + 1, k - 1) * calc(k, r) % MOD) %= MOD;
//         }
//     }
//     return f[l][r] = ret;
// }

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> s + 1;
    int n = strlen(s + 1);
    rep(i, 1, n) f[i][i] = 1;
    for (int len = 2; len <= n; len += 2) {
        rep(i, 1, n - len) {
            int j = i + len;
            rep(k, i + 1, j) {
                if (s[i] == s[k]) {
                    (f[i][j] += (ll)f[i + 1][k - 1] * f[k][j] % MOD) %= MOD;
                }
            }
        }
    }
    cout << f[1][n];
    // std::memset(f, -1, sizeof(f));
    // cout << calc(1, n);
    return 0;
}