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

const int N = 100010;

std::vector<int> g[N], ng[N];

int fa[20][N], dep[N], val[N];

void dfs(int u) {
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
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

int n, m, ans;

int calc(int u) {
    int ret = 0;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (v == fa[0][u]) continue;
        v = calc(v);
        if (v == 0)
            ans += m;
        else if (v == 1)
            ans += 1;
        ret += v;
    }
    return ret + val[u];
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int u, v;
    cin >> n >> m;
    rep(i, 2, n) {
        cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    }
    dep[1] = 1;
    dfs(1);
    // cerr << "dfs over" << endl;
    rep(k, 1, 19) rep(i, 1, n) fa[k][i] = fa[k - 1][fa[k - 1][i]];
    // cerr << "dfs over" << endl;

    rep(i, 1, m) {
        cin >> u >> v;
        val[u] += 1;
        val[v] += 1;
        val[q(u, v)] -= 2;
    }
    calc(1);
    cout << ans;
    return 0;
}