#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define rep(i, l, r) for (register int i = (l); i <= (r); ++i)
#define per(i, l, r) for (register int i = (l); i >= (r); --i)
#define travese(i, u) for (edge* i = p[u]; i != NULL; i = i->nxt)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
typedef pair<int, int> pii;
const int N = 200000;
int n, dep[N + 100];
struct edge {
    int u, v;
    edge* nxt;
} e[N * 2 + 200];
edge* p[N + 100];
int tot = 0, ans = 0;
inline void addedge(int u, int v) {
    e[tot].v = v, e[tot].nxt = p[u], p[u] = &e[tot++];
}
bool flag[N + 100];
void dfs1(int u, int fa, int w) {
    flag[u] = true;
    if (w == 2) return;
    travese(i, u) if (i->v != fa) dfs1(i->v, u, w + 1);
}
void dfs(int u, int fa) {
    travese(i, u) {
        if (i->v != fa) dfs(i->v, u);
    }
    // rep (i, 1, n){
    //     cout << flag[i] << ' ';
    // }
    // cout << endl;
    if (!flag[u]) ++ans, dfs1(fa, 0, 1);
}
int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    int u, v;
    rep(i, 2, n) {
        cin >> u >> v;
        addedge(u, v);
        addedge(v, u);
    }
    dfs1(1, 0, 0);
    dfs(1, 0);
    cout << ans;
    return 0;
}
