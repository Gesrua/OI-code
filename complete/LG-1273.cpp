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

int f[3010][3010], n, m, val[3010];

std::vector<pii> g[3010];

int calc(int u) {
    f[u][0] = 0;
    if (u > n - m) {
        f[u][1] = val[u];
        return 1;
    }
    int s = 0;
    for (auto i : g[u]) {
        int v = i.first, w = i.second, t = calc(v);
        s += t;
        per(i, s, 1) {
            // int lim = std::min(t, i);
            rep(j, 1, t) {
                if (i < j) break;
                f[u][i] = std::max(f[u][i], f[u][i - j] + f[v][j] - w);
            }
        }
    }
    return s;
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n >> m;
    std::memset(f, 0x8F, sizeof(f));
    int k, v, w;
    rep(u, 1, n - m) {
        cin >> k;
        while (k--) {
            cin >> v >> w;
            g[u].push_back(pii(v, w));
        }
    }
    rep(i, n - m + 1, n) cin >> val[i];
    calc(1);
    per(i, m, 0) if (f[1][i] >= 0) {
        cout << i;
        break;
    }

    return 0;
}