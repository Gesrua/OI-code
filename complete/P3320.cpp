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

int fa[20][N], dep[N], dfn[N], stamp = 0, rev[N];
ll dis[N];

int up_dep(int u, int delta) {
    if (delta <= 0) return u;
    per(i, 19, 0) if (delta >= (1 << i)) delta -= (1 << i), u = fa[i][u];
    return u;
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) std::swap(u, v);
    u = up_dep(u, dep[u] - dep[v]);
    if (u == v) return u;
    per(i, 19, 0) if (fa[i][u] != fa[i][v]) u = fa[i][u], v = fa[i][v];
    return fa[0][u];
}

std::vector<std::pair<int, ll>> g[N];

void dfs(int u) {
    dfn[u] = ++stamp;
    rev[stamp] = u;
    for (auto i : g[u])
        if (i.first != fa[0][u]) {
            fa[0][i.first] = u, dep[i.first] = dep[u] + 1,
            dis[i.first] = i.second + dis[u];
            dfs(i.first);
        }
}

ll query(int u, int v) { return dis[u] + dis[v] - 2 * dis[lca(u, v)]; }

auto cmp_dfn = [](int u, int v) { return dfn[u] < dfn[v]; };

std::set<int, decltype(cmp_dfn)> s(cmp_dfn);

int main() {
#ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    rep(i, 2, n) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }
    int rt = 1;
    dep[rt] = 1;
    dfs(rt);
    dep[n + 1] = 0;
    dfn[n + 1] = ++stamp;
    rev[stamp] = n + 1;
    rep(k, 1, 19) rep(i, 1, n) fa[k][i] = fa[k - 1][fa[k - 1][i]];
    ll ans = 0;
    while (q--) {
        int t;
        cin >> t;
        if (s.count(t) == 0) {
            if (s.size() == 0)
                ans = 0, s.insert(t);
            else if (s.size() == 1)
                ans = query(*s.begin(), t) * 2, s.insert(t);
            else {
                int head = *s.begin(), tail = *(--s.end());
                if (dfn[t] < dfn[head]) {
                    ans += query(t, head) - query(head, tail) + query(tail, t);
                    s.insert(t);
                } else if (dfn[t] > dfn[tail]) {
                    ans += query(tail, t) + query(t, head) - query(head, tail);
                    s.insert(t);
                } else {
                    auto cur = s.insert(t);
                    head = *(--cur.first);
                    ++cur.first;
                    tail = *(++cur.first);
                    ans += query(head, t) + query(t, tail) - query(head, tail);
                }
            }
        } else {
            if (s.size() == 1 || s.size() == 2)
                ans = 0, s.erase(t);
            else {
                // a b c d
                int head = *s.begin(), tail = *(--s.end());

                if (head == t) {
                    head = *(++s.begin());
                    ans += query(head, tail) - query(t, head) - query(t, tail);
                    s.erase(t);
                } else if (tail == t) {
                    tail = *(--(--s.end()));
                    ans += query(tail, head) - query(tail, t) - query(t, head);
                    s.erase(t);
                } else {
                    auto cur = s.find(t);
                    head = *(--cur);
                    ++cur;
                    tail = *(++cur);
                    ans += query(head, tail) - query(head, t) - query(t, tail);
                    s.erase(t);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}