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

const int N = 100100;

struct Edge {
    Edge* nxt;
    int v;
} e[1000100];

Edge* p[N];

#define R(i, u) for (Edge* i = p[u]; i; i = i->nxt)

int n, m, cnt;

inline void addedge(int u, int v) {
    e[cnt].v = v, e[cnt].nxt = p[u], p[u] = &e[cnt++];
}

ll ans[N];

int st, dfn[N], low[N], siz[N];

void tarjan(int u) {
    // cerr << u << endl;
    low[u] = dfn[u] = ++st;
    siz[u] = 1;
    int all = 0;
    R(i, u) {
        if (!dfn[i->v]) {
            tarjan(i->v);
            low[u] = std::min(low[i->v], low[u]);
            siz[u] += siz[i->v];
            if (dfn[u] <= low[i->v]) {
                ans[u] += ll(n - siz[i->v]) * siz[i->v];
                all += siz[i->v];
            }
        } else
            low[u] = std::min(dfn[i->v], low[u]);
    }
    if (ans[u])
        ans[u] += ll(n - all - 1) * (all + 1) + (n - 1);
    else
        ans[u] = 2 * (n - 1);
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n >> m;
    rep(i, 1, m) {
        int u, v;
        cin >> u >> v;
        addedge(u, v);
        addedge(v, u);
    }
    tarjan(1);
    rep(i, 1, n) cout << ans[i] << endl;
    return 0;
}