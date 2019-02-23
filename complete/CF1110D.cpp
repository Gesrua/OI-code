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

const int N = 1000100;

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    static int n, m, f[N][3][3], a[N];
    cin >> n >> m;
    rep(i, 1, n) {
        int t;
        cin >> t;
        a[t]++;
    }
    // rep(i, 1, m) { cerr << a[i] << ' '; }
    int ans = 0;
    rep(i, 0, m) rep(j, 0, 2) rep(k, 0, 2) f[i][j][k] = -333334;
    f[0][0][0] = 0;
    rep(i, 1, m) {
        rep(j, 0, 2) {
            rep(k, 0, 2) {
                rep(l, 0, 2) {
                    if (j + k + l > a[i]) break;
                    f[i][j][k] =
                        std::max(f[i][j][k],
                                 f[i - 1][k][l] + l + (a[i] - j - k - l) / 3);
                    ans = std::max(f[i][j][k], ans);
                }
            }
        }
    }
    cout << ans;
    return 0;
}
