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

const int N = 35, M = 5009;

int g[N], f[N][M], pre[N], ans[N], id[N], pos[N];

pii from[N][M];

void upd(int x, int y, int a, int b) {}

int q(int x, int y) { return pre[y] - pre[x - 1]; }

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    rep(i, 1, n) cin >> g[pos[i] = id[i] = i];

    // std::sort(g + 1, g + 1 + n, std::greater<int>());
    rep(i, 1, n) rep(j, i + 1, n) {
        if (g[i] < g[j]) {
            std::swap(g[i], g[j]);
            std::swap(pos[id[i]], pos[id[j]]);
            std::swap(id[i], id[j]);
        }
    }

    rep(i, 1, n) pre[i] = pre[i - 1] + g[i];
    m -= n;
    std::memset(f, 0x3f, sizeof(f));
    f[0][0] = 0;
    rep(i, 1, n) {
        f[i][0] = 0;
        rep(j, 1, m) {
            if (j - i >= 0 && f[i][j - i] < f[i][j]) {
                f[i][j] = f[i][j - i];
                from[i][j] = {i, j - i};
            }
            rep(k, 0, i - 1) if (j - k >= 0 && f[k][j - k] + k * q(k + 1, i) < f[i][j]) {
                f[i][j] = f[k][j - k] + k * q(k + 1, i);
                from[i][j] = {k, j - k};
            }
        }
    }
    cout << f[n][m] << endl;
    pii ed = {0, 0};
    int delta = 0, last = n + 1;
    for (pii i = {n, m}; i != ed; i = from[i.first][i.second]) {
        if (i.first < last) {
            rep(j, i.first + 1, last) ans[j] = delta;
            last = i.first;
            delta++;
        } else
            delta++;
    }
    rep(i, 1, last) ans[i] = delta;
    rep(i, 1, n) cout << ans[pos[i]] << ' ';
    return 0;
}