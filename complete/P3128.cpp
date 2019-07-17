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

const int N = 50010;

std::vector<int> g[N];

int d[N], fa[20][N], dep[N], val[N];

void dfs(int u) {
    for (auto v : g[u]) {
        if (v == fa[0][u]) continue;
        fa[0][v] = u;
        dep[v] = dep[u] + 1;
        dfs(v);
    }
}

int up(int u, int l) {
    for (int i = 19; i >= 0; --i) {
        if (l >= (1 << i)) u = fa[i][u], l -= 1 << i;
    }
    return u;
}

int q(int u, int v) {
    if (dep[u] < dep[v]) std::swap(u, v);
    u = up(u, dep[u] - dep[v]);
    if (u == v) return u;
    for (int i = 19; i >= 0; --i)
        if (fa[i][u] != fa[i][v]) u = fa[i][u], v = fa[i][v];
    return fa[0][u];
}

void calc(int u) {
    val[u] = d[u];
    for (auto v : g[u]) {
        if (v == fa[0][u]) continue;
        calc(v), val[u] += val[v];
    }
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, k, u, v;
    cin >> n >> k;
    rep(i, 2, n) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dep[1] = 1, dfs(1);
    rep(k, 1, 19) rep(i, 1, n) fa[k][i] = fa[k - 1][fa[k - 1][i]];
    rep(i, 1, k) {
        cin >> u >> v;
        int lca = q(u, v);
        d[u] += 1, d[v] += 1, d[lca] -= 1, d[fa[0][lca]] -= 1;
    }
    calc(1);
    int ans = 0;
    rep(i, 1, n) ans = std::max(ans, val[i]);
    cout << ans;
    return 0;
}