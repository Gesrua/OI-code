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

const int SZ = 7000100, N = 100100;

struct Node {
    int mx, sum, l, r;
    Node *ls, *rs;
} t[SZ];

Node* rt[N];

int P, X, L, R, cnt, w[N], c[N];

inline int qmx(Node* c) { return c == nullptr ? 0 : c->mx; }

inline int qs(Node* c) { return c == nullptr ? 0 : c->sum; }

void pushup(Node* c) {
    c->mx = std::max(qmx(c->ls), qmx(c->rs));
    c->sum = qs(c->ls) + qs(c->rs);
}

void modi(Node*& c, int l, int r) {
    if (P < l || r < P) return;
    // cerr << l << ' ' << r << ' ' << P << ' ' << X << endl;

    if (c == nullptr) {
        c = &t[cnt++];
        c->l = l, c->r = r;
    }
    if (l == r) {
        c->mx = c->sum = X;
        return;
    }
    int mid = (l + r) / 2;
    modi(c->ls, l, mid), modi(c->rs, mid + 1, r);
    pushup(c);
}

int qmax(Node* c) {
    if (c == nullptr) return 0;
    if (R < c->l || c->r < L) return 0;
    if (L <= c->l && c->r <= R) return c->mx;
    return std::max(qmax(c->ls), qmax(c->rs));
}

int qsum(Node* c) {
    if (c == nullptr) return 0;
    if (R < c->l || c->r < L) return 0;
    if (L <= c->l && c->r <= R) return c->sum;
    return qsum(c->ls) + qsum(c->rs);
}

std::vector<int> g[N];

int son[N], sz[N], fa[1][N], dep[N], dfn[N], rev[N], top[N], dst = 0;

void dfs1(int u) {
    sz[u] = 1, dep[u] = dep[fa[0][u]] + 1;
    for (auto v : g[u]) {
        if (v == fa[0][u]) continue;
        fa[0][v] = u;
        dfs1(v);
        if (sz[v] > sz[son[u]]) son[u] = v;
        sz[u] += sz[v];
    }
}

void dfs2(int u) {
    dfn[u] = ++dst, rev[dst] = u;
    if (son[u]) {
        top[son[u]] = top[u];
        dfs2(son[u]);
    }
    for (auto v : g[u]) {
        if (v == fa[0][u] || v == son[u]) continue;
        top[v] = v;
        dfs2(v);
    }
}

void print(Node* c) {
    if (c == nullptr) return;
    cerr << c->l << ' ' << c->r << ' ' << c->mx << ' ' << c->sum << endl;
    print(c->ls), print(c->rs);
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    rep(i, 1, n) { cin >> w[i] >> c[i]; }
    rep(i, 2, n) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    }
    dfs1(1);
    dfs2(1);
    rep(i, 1, n) {
        P = dfn[i], X = w[i], modi(rt[c[i]], 1, n);
        // cerr << "--------" << endl;
    }
    std::string s;
    while (q--) {
        cin >> s;
        if (s[1] == 'C') {
            int x;
            cin >> x;
            P = dfn[x], X = 0, modi(rt[c[x]], 1, n);
            cin >> c[x];
            X = w[x], modi(rt[c[x]], 1, n);
        } else if (s[1] == 'W') {
            int x;
            cin >> x >> w[x];
            P = dfn[x], X = w[x], modi(rt[c[x]], 1, n);
        } else if (s[1] == 'S') {
            int x, y, ans = 0, color;
            cin >> x >> y;
            color = c[x];
            while (top[x] != top[y]) {
                if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
                L = dfn[top[x]], R = dfn[x], ans += qsum(rt[color]);
                x = fa[0][top[x]];
            }
            if (dep[x] > dep[y]) std::swap(x, y);
            L = dfn[x], R = dfn[y], ans += qsum(rt[color]);
            cout << ans << endl;
        } else if (s[1] == 'M') {
            int x, y, ans = 0, color;
            cin >> x >> y;
            color = c[x];
            while (top[x] != top[y]) {
                if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
                L = dfn[top[x]], R = dfn[x],
                ans = std::max(ans, qmax(rt[color]));
                x = fa[0][top[x]];
            }
            if (dep[x] > dep[y]) std::swap(x, y);
            L = dfn[x], R = dfn[y], ans = std::max(ans, qmax(rt[color]));
            cout << ans << endl;
        }
    }
    return 0;
}