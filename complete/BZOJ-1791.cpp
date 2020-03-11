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
typedef pair<int, long long> pii;
typedef long long ll;
typedef unsigned int ui;

const int N = 2000010;

// std::vector<pii> g[N];

int deg[N], c[N], siz[N], loop[N * 2];

int q[N * 2], l, r;

ll dp[N], ga, mx[N], d[N * 2];

struct Edge {
    Edge* nxt;
    int v;
    ll w;
} e[N * 2];
Edge* p[N];
int tot = 0;
inline void addedge(int u, int v, int w) {
    e[tot].v = v, e[tot].w = w, e[tot].nxt = p[u], p[u] = &e[tot++];
}

int main() {
#ifdef LOCAL
    freopen("/tmp/data/island1.in", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n;
    cin >> n;
    rep(u, 1, n) {
        int v, w;
        cin >> v >> w;
        addedge(u, v, w), addedge(v, u, w);
        // g[u].push_back(pii(v, w)), g[v].push_back(pii(u, w));
        deg[u]++, deg[v]++;
    }

    int cnt = 0;
    rep(i, 1, n) if (!c[i]) {
        cnt++;
        // q.init(i);
        q[l = 0] = i, r = 1;
        while (l < r) {
            int u = q[l++];
            c[u] = cnt;
            for (Edge* i = p[u]; i; i = i->nxt) {
                int v = i->v;
                if (c[v]) continue;
                q[r++] = v;
            }
        }
    }

    l = r = 0;
    rep(i, 1, n) if (deg[i] == 1) q[r++] = i;
    while (l < r) {
        int u = q[l++];
        for (Edge* i = p[u]; i; i = i->nxt) {
            int v = i->v;
            if (deg[v] > 1) {
                mx[c[u]] = std::max(mx[c[u]], dp[u] + dp[v] + i->w);
                dp[v] = std::max(dp[v], dp[u] + i->w);
                deg[v]--;
                if (deg[v] == 1) q[r++] = v;
            }
        }
    }

    rep(u, 1, n) if (deg[u] == 2) siz[c[u]]++;

    ll ans = 0;
    rep(st, 1, n) {
        if (deg[st] != 2) continue;
        int cnt = 1, m = siz[c[st]];
        int s = st;
        rep(k, 1, m) {
            loop[cnt] = s;
            deg[s] = 1;
            for (Edge* i = p[s]; i; i = i->nxt) {
                if (deg[i->v] == 2) {
                    s = i->v;
                    d[cnt++] = i->w;
                    break;
                }
            }
        }

        s = st;
        if (siz[c[s]] == 2) {
            ll ret = 0;
            for (Edge* i = p[s]; i; i = i->nxt)
                if (i->v == loop[2]) ret = std::max(ret, i->w);
            // cerr << "siz = 2 " << std::max(mx[c[s]], ret + dp[s] +
            // dp[loop[2]]);
            ans += std::max(mx[c[s]], ret + dp[s] + dp[loop[2]]);
            continue;
        }

        for (Edge* i = p[loop[m]]; i; i = i->nxt)
            if (i->v == st) {
                d[m] = i->w;
                break;
            }

        rep(i, 1, m) loop[i + m] = loop[i], d[i + m] = d[i];
        per(i, m * 2 - 1, 1) d[i] += d[i + 1];
        ll ret = mx[c[st]];

        q[l = r = 1] = 1;
        rep(i, 2, m * 2) {
            while (l <= r && q[l] <= i - m) ++l;
            ret = std::max(ret, dp[loop[q[l]]] + d[q[l]] + dp[loop[i]] - d[i]);
            ll x = dp[loop[i]] + d[i];
            while (l <= r && dp[loop[q[r]]] + d[q[r]] <= x) --r;
            q[++r] = i;
        }
        ans += ret;
    }
    cout << ans;
    return 0;
}