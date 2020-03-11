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
using std::max;
using std::pair;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int ui;

const int N = 1010;

int head[N * 2], tail[N * 2], f[N * 2][N * 2];

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);

    int _n, n;
    cin >> _n;
    n = _n * 2;
    rep(i, 1, _n) {
        cin >> head[i];
        head[i + _n] = tail[i - 1] = tail[i + _n - 1] = head[i];
    }
    tail[n] = head[1];
    int ans = 0;
    rep(len, 2, _n) {
        rep(i, 1, n) {
            int j = i + len - 1;
            if (j > n) break;
            rep(k, i, j - 1) {
                f[i][j] = max(f[i][j],
                              f[i][k] + f[k + 1][j] + head[i] * tail[k] * tail[j]);
            }
            if (len == _n) ans = max(f[i][j], ans);
        }
    }
    cout << ans;
    return 0;
}