#include <algorithm>
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
#define rep(i, l, r) for (register int i = (l); i <= (r); ++i)
#define per(i, l, r) for (register int i = (l); i >= (r); --i)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int ui;
const int N = 100000, Q = 1000000;

int tot = 0, n, q, v[N + 100], st[19][N + 100], f[19][N + 100];

struct edge {
    int v;
    edge* nxt;
} e[N * 2 + 100];

#define travel(i, u) for (edge* i = p[u]; i; i = i->nxt)

edge* p[N + 100];

void addedge(int u, int v) {
    e[tot].v = v, e[tot].nxt = p[u], p[u] = &e[tot++];
    e[tot].v = u, e[tot].nxt = p[v], p[v] = &e[tot++];
}

void dfs(int fa, int x) {
    f[0][x] = fa;
    st[0][x] = v[x];
    travel(i, x) {
        if (i->v == fa) continue;
        dfs(x, i->v);
    }
}

int ans_id[N];

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n >> q;
    rep(i, 1, n) cin >> v[i];
    rep(i, 2, n) {
        int u, v;
        cin >> u >> v;
        addedge(u + 1, v + 1);
    }
    dfs(0, 1);
    rep(k, 1, 18) {
        rep(i, 1, n) f[k][i] = f[k - 1][f[k - 1][i]];
        rep(i, 1, n) st[k][i] = std::max(st[k - 1][i], st[k - 1][f[k - 1][i]]);
    }
    rep(i, 2, n) {
        int x = f[0][i], goal = v[i] - v[1];
        if (st[18][x] < goal) {  // -1
            ans_id[i] = -1;
            continue;
        }
        if (v[x] >= goal) {
            ans_id[i] = x;
            continue;
        }
        per(k, 18, 0) if (st[k][x] < goal) x = f[k][x];
        ans_id[i] = x;
    }
    rep(i, 1, q) {
        int x;
        cin >> x;
        ++x;
        if (ans_id[x] == -1)
            cout << -1 << endl;
        else
            cout << ans_id[x] - 1 << ' ' << v[ans_id[x]] << endl;
    }
    // rep(k, 0, 4){
    //     rep(i, 1, n) cout << st[k][i] << ' ';
    //     cout << endl;
    // }
    return 0;
}