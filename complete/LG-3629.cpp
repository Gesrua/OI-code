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

const int N = 100010;

struct Edge {
    Edge* nxt;
    int v, w;
} e[N * 2];
Edge* p[N];
int cnt = 0;
void addedge(int u, int v, int w) {
    e[cnt].v = v, e[cnt].w = w, e[cnt].nxt = p[u], p[u] = &e[cnt++];
}

int dis[N], from[N];

void dfs(int u, int fa, int& far) {
    if (dis[far] < dis[u]) far = u;
    for (auto i = p[u]; i; i = i->nxt) {
        if (i->v == fa) continue;
        dis[i->v] = dis[u] + i->w;
        from[i->v] = (i - e) ^ 1;
        dfs(i->v, u, far);
    }
}

int tot, dp[N];

void calc(int u, int fa) {
    for (auto i = p[u]; i; i = i->nxt) {
        if (i->v == fa) continue;
        calc(i->v, u);
        tot = max(tot, i->w + dp[u] + dp[i->v]);  // 精妙
        dp[u] = max(dp[u], dp[i->v] + i->w);      // 精妙
    }
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    rep(i, 2, n) {
        int u, v;
        cin >> u >> v;
        addedge(u, v, 1);
        addedge(v, u, 1);
    }
    int s, t;
    dfs(1, 0, s);
    dis[s] = 0, t = s;
    dfs(s, 0, t);
    int ans = (n - 1) * 2 - dis[t] + 1;
    cerr << ans << endl;
    while (t != s) {
        e[from[t]].w = e[from[t] ^ 1].w = -1;
        t = e[from[t]].v;
    }
    if (k == 2) {
        std::memset(dis, 0, sizeof(dis));
        calc(s, 0);
        ans = ans - tot + 1;
    }
    cout << ans;
    return 0;
}