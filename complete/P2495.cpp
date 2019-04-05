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

const int N = 250100;

std::vector<pii> g[N];

int h[N], dfn[N], fa[20][N], dep[N];
bool tag[N];
int st[20][N];

const int inf = 100000;

int query(int u, int v) {
    int delta = dep[v] - dep[u], ret = inf;
    per(i, 19, 0) if (delta >= (1 << i)) {
        delta -= (1 << i), ret = min(ret, st[i][v]), v = fa[i][v];
    }
    return ret;
}

bool cmp_dfn(const int x, const int y) { return dfn[x] < dfn[y]; }

struct Edge {
    int v, w;
    Edge* nxt;
} e[N * 2];
Edge* p[N];
int cnt = 0;
void addedge(int u, int v, int w) {
    e[cnt] = (Edge){v, w, p[u]};
    p[u] = &e[cnt++];
}
void addedge(int u, int v) {
    e[cnt] = (Edge){v, query(u, v), p[u]};
    p[u] = &e[cnt++];
}

int stk[N], sz;

int stamp = 0;

void dfs(int u) {
    dfn[u] = ++stamp;
    for (auto i : g[u])
        if (i.first != fa[0][u])
            fa[0][i.first] = u, st[0][i.first] = i.second,
            dep[i.first] = dep[u] + 1, dfs(i.first);
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) std::swap(u, v);
    int delta = dep[u] - dep[v];
    per(i, 19, 0) if (delta >= (1 << i)) delta -= (1 << i), u = fa[i][u];
    if (u == v) return u;
    per(i, 19, 0) if (fa[i][u] != fa[i][v]) u = fa[i][u], v = fa[i][v];
    return fa[0][u];
}

ll solve(int u) {
    tag[u] = 0;
    if (p[u] == nullptr) return inf;
    ll ret = 0;
    for (auto i = p[u]; i; i = i->nxt) {
        ret += min((ll)i->w, tag[i->v] ? (solve(i->v), (ll)inf) : solve(i->v));
    }
    p[u] = nullptr;
    return ret;
}

void printvt(int u) {
    for (auto i = p[u]; i; i = i->nxt) {
        cerr << u << " -- " << i->v << endl;
        printvt(i->v);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n;
    cin >> n;
    rep(i, 2, n) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }
    int rt = 1;
    dep[rt] = 1;
    dfs(rt);
    rep(k, 1, 19) rep(i, 1, n) fa[k][i] = fa[k - 1][fa[k - 1][i]],
                               st[k][i] =
                                   min(st[k - 1][i], st[k - 1][fa[k - 1][i]]);
    // rep(k, 0, 2) rep(i, 1, n) cerr << st[k][i] << (i == n ? '\n' : ' ');
    int q;
    cin >> q;
    int m;
    while (q--) {
        sz = cnt = 0;

        cin >> m;
        rep(i, 1, m) {
            cin >> h[i];
            tag[h[i]] = 1;
        }
        std::sort(h + 1, h + 1 + m, cmp_dfn);
        stk[sz++] = rt;
        if (h[1] != rt) stk[sz++] = h[1];
        rep(i, 2, m) {
            int lca = ::lca(h[i], stk[sz - 1]);
            if (lca == stk[sz - 1])
                stk[sz++] = h[i];
            else {
                while (sz - 2 >= 0 && dep[stk[sz - 2]] >= dep[lca]) {
                    addedge(stk[sz - 2], stk[sz - 1]);
                    sz--;
                }
                if (stk[sz - 1] != lca) {
                    addedge(lca, stk[sz - 1]);
                    stk[sz - 1] = lca;
                }
                stk[sz++] = h[i];
            }
        }
        rep(i, 0, sz - 2) addedge(stk[i], stk[i + 1]);
        // printvt(rt);
        cout << solve(rt) << endl;
    }
    return 0;
}