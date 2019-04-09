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
using std::min;
using std::pair;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int ui;

const int N = 100100;

ll inf = 10000000001;

int n, fa[20][N], dep[N];

ll dp[N][2];

// f[k][i][i-1<<k选][i选]
ll f[20][N][2][2], val[N], up[N][2];

std::vector<int> g[N];

void dfs(int u) {
    dp[u][1] = val[u];
    for (auto v : g[u])
        if (v != fa[0][u]) {
            dep[v] = dep[u] + 1;
            fa[0][v] = u;
            dfs(v);
            dp[u][1] += min(dp[v][0], dp[v][1]);
            dp[u][0] += dp[v][1];
        }
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) std::swap(u, v);
    int delta = dep[u] - dep[v];
    per(i, 19, 0) if (delta >= (1 << i)) delta -= (1 << i), u = fa[i][u];
    if (u == v) return u;
    per(i, 19, 0) if (fa[i][u] != fa[i][v]) u = fa[i][u], v = fa[i][v];
    return fa[0][u];
}

int up_dep(int u, int delta) {
    if (delta <= 0) return u;
    per(i, 19, 0) if (delta >= (1 << i)) delta -= (1 << i), u = fa[i][u];
    return u;
}

ll query(int u, int v, int su, int sv) {
    if (u == v) {
        if (su == sv)
            return 0;
        else
            return inf;
    }
    if (dep[u] < dep[v]) std::swap(u, v), std::swap(su, sv);
    int ret[2] = {}, tmp[2] = {};
    int delta = dep[u] - dep[v];
    per(i, 19, 0) {
        if (delta == (1 << i)) {
            return f[i][u][sv][su];
        }
        if (delta > (1 << i)) {
            delta -= (1 << i);
            ret[0] = f[i][u][0][su];
            ret[1] = f[i][u][1][su];
            u = fa[i][u];
            break;
        }
    }
    per(i, 19, 0) {
        if (delta == (1 << i)) {
            return min(ret[0] + f[i][u][sv][0], ret[1] + f[i][u][sv][1]);
        }
        if (delta > (1 << i)) {
            delta -= (1 << i);
            tmp[0] = min(ret[0] + f[i][u][0][0], ret[1] + f[i][u][0][1]);
            tmp[1] = min(ret[0] + f[i][u][1][0], ret[1] + f[i][u][1][1]);
            ret[0] = tmp[0];
            ret[1] = tmp[1];
            u = fa[i][u];
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int m;
    std::string s;
    cin >> n >> m >> s;

    rep(i, 1, n) cin >> val[i];
    rep(i, 2, n) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    }
    dep[1] = 1;
    dfs(1);

    rep(u, 1, n) {
        int anc = fa[0][u];
        f[0][u][0][0] = inf;
        f[0][u][0][1] = dp[anc][0] - dp[u][1];
        f[0][u][1][0] = dp[anc][1] - min(dp[u][0], dp[u][1]);
        f[0][u][1][1] = dp[anc][1] - min(dp[u][0], dp[u][1]);
    }

    rep(k, 1, 19) rep(i, 1, n) {
        fa[k][i] = fa[k - 1][fa[k - 1][i]];
        rep(x, 0, 1) rep(y, 0, 1) {
            f[k][i][x][y] = inf;
            rep(z, 0, 1) {
                f[k][i][x][y] =
                    min(f[k][i][x][y],
                        f[k - 1][fa[k - 1][i]][x][z] + f[k - 1][i][z][y]);
            }
        }
    }

    rep(i, 2, n) {
        up[i][0] = min(query(1, i, 0, 0), query(1, i, 1, 0));
        up[i][1] = min(query(1, i, 0, 1), query(1, i, 1, 1));
    }

    while (m--) {
        int u, v, su, sv;
        cin >> u >> su >> v >> sv;
        if (dep[u] > dep[v]) std::swap(u, v), std::swap(su, sv);
        int anc = lca(u, v);
        if (u == anc) {
            ll ans = up[u][su] + query(u, v, su, sv) + dp[v][sv];
            if (ans >= inf) ans = -1;
            cout << ans << endl;
        } else {
            ll ans = inf;
            int us = up_dep(u, dep[u] - dep[anc] - 1);
            int vs = up_dep(v, dep[v] - dep[anc] - 1);
            ll uw[2] = {inf, inf};
            ll vw[2] = {inf, inf};
            if (u == us) uw[su] = dp[u][su];
            else uw[0] = query(us, u, 0, su) + dp[u][su], uw[1] = query(us, u, 1, su) + dp[u][su];
            if (v == vs) vw[sv] = dp[v][sv];
            else vw[0] = query(vs, v, 0, sv) + dp[v][sv], vw[1] = query(vs, v, 1, sv) + dp[v][sv];
            ans = min(
                up[anc][0] + dp[anc][0] - dp[us][1] - dp[vs][1] + uw[1] + vw[1],
                up[anc][1] + dp[anc][1] - min(dp[us][0], dp[us][1]) - min(dp[vs][0], dp[vs][1]) + min(uw[0], uw[1]) + min(vw[0], vw[1])
            );
            if (ans >= inf) ans = -1;
            cout << ans << endl;
        }
    }
    return 0;
}