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
#ifndef ONLINE_JUDGE
#include "dbg.h"
#endif
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
typedef unsigned long long ull;

const int N = 2e5 + 10;
struct Edge {
    int v, cap;
    Edge* nxt;
} e[N * 2];
Edge* p[N];
int cnt = 0;
inline void addedge(int u, int v, int cap) {
    e[cnt].nxt = p[u], e[cnt].v = v, e[cnt].cap = cap, p[u] = &e[cnt++];
    e[cnt].nxt = p[v], e[cnt].v = u, e[cnt].cap = cap, p[v] = &e[cnt++];
}
int ans = 0;
int d[N];
const int inf = 0x3f3f3f3f;

int calc1(int u, int fa) {
    if (p[u]->nxt == nullptr) return d[u] = inf;
    int ret = 0;
    for (auto i = p[u]; i; i = i->nxt) {
        if (i->v == fa) continue;
        ret += std::min(i->cap, calc1(i->v, u));
    }
    return d[u] = ret;
}

void calc2(int u, int fa, int up) {
    if (p[u]->nxt == nullptr) return;
    ans = std::max(ans, d[u] + up);
    for (auto i = p[u]; i; i = i->nxt) {
        if (i->v == fa) continue;
        calc2(i->v, u, std::min(i->cap, d[u] - std::min(i->cap, d[i->v]) + up));
    }
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, x, y, z;
        cin >> n;
        std::memset(p, 0, sizeof(p)), cnt = ans = 0;
        rep(i, 2, n) {
            cin >> x >> y >> z;
            addedge(x, y, z);
        }
        int rt;
        rep(i, 1, n) if (p[i]->nxt) {
            rt = i;
            break;
        }
        calc1(rt, 0);
        calc2(rt, 0, 0);
        cout << ans << endl;
    }
    return 0;
}