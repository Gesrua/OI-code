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

struct Edge {
    int v, cap;
    Edge *nxt, *rev;
} e[6000];

Edge *p[120];

int cnt = 0, bed[120], in[120];

void addedge(int u, int v, int cap) {
    e[cnt] = (Edge){v, cap, p[u], &e[cnt + 1]};
    p[u] = &e[cnt++];
    e[cnt] = (Edge){u, 0, p[v], &e[cnt - 1]};
    p[v] = &e[cnt++];
}

const int inf = 1e5;

int s, t, dep[120], tot;
Edge *cur[120];

bool bfs() {
    rep(i, 0, tot) cur[i] = p[i];
    std::memset(dep, 0, sizeof(dep));
    dep[s] = 1;
    std::queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto i = p[u]; i; i = i->nxt) {
            if (i->cap > 0 && !dep[i->v]) dep[i->v] = dep[u] + 1, q.push(i->v);
        }
    }
    return dep[t];
}

int dfs(int u, int pre) {
    int flow = 0, delta;
    if (u == t || pre <= 0) return pre;
    for (auto i = cur[u]; i; cur[u] = i = i->nxt) {
        if (i->cap <= 0 || dep[i->v] != dep[u] + 1) continue;
        delta = dfs(i->v, std::min(pre, i->cap));
        // cerr << u << ' ' << i->v << ' ' << i->cap << ' ' << delta << endl;
        i->cap -= delta;
        i->rev->cap += delta;
        flow += delta;
        pre -= delta;
        if (pre == 0) break;
    }
    return flow;
}

int maxflow() {
    int flow = 0;
    while (bfs()) {
        flow += dfs(s, inf);
    }
    return flow;
}

void solve() {
    int n, target = 0;
    cnt = 0;
    cin >> n;
    target = n;
    std::memset(p, 0, sizeof(p));
    s = 0, t = 2 * n + 1;
    tot = 2 * n + 1;
    rep(i, 1, n) {
        cin >> bed[i];
        if (bed[i]) addedge(i + n, t, 1);
    }
    rep(i, 1, n) {
        cin >> in[i];
        in[i] ^= 1;
        if (!bed[i] || in[i]) addedge(s, i, 1);
        if (bed[i] && !in[i]) {
            target--;
            // cerr << "target-- " << i << endl;
        }
    }
    rep(i, 1, n) {
        rep(j, 1, n) {
            int t;
            cin >> t;
            if (t || i == j) addedge(i, n + j, 1);
        }
    }
    // rep(u, 0, tot) {
    //     for (auto i = p[u]; i; i = i->nxt)
    //         cerr << u << ' ' << i->v << ' ' << i->cap << endl;
    // }
    int t = maxflow();
    // cerr << t << ' ' << target << endl;
    if (t == target)
        cout << "^_^" << endl;
    else
        cout << "T_T" << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}