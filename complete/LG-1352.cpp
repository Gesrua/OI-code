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

const int N = 6010;

int r[N], f[N][2], fa[N];

std::vector<int> g[N];

void calc(int u) {
    f[u][1] = r[u];
    for (auto v : g[u]) {
        calc(v);
        f[u][0] += std::max(f[v][0], f[v][1]);
        f[u][1] += f[v][0];
    }
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n;
    cin >> n;
    rep(i, 1, n) cin >> r[i];
    rep(i, 2, n) {
        int v, u;
        cin >> v >> u;
        g[u].push_back(v);
        fa[v] = u;
    }
    int rt = 1;
    while (fa[rt] != 0) rt = fa[rt];
    calc(rt);
    // rep(i, 1, n) { cerr << f[i][0] << ' '; }
    // cerr << endl;
    cout << std::max(f[rt][0], f[rt][1]);
    return 0;
}