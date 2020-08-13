#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;

const int N = 10009, M = 100010;

struct Edge{
    int v;
    Edge* nxt;
} e[M]; int tot = 0;
Edge* p[N];
inline void addedge(int u, int v){
    e[tot].v = v, e[tot].nxt = p[u], p[u] = &e[tot++];
}

std::vector<int> ans;
void dfs(int u){
    while(p[u]){
        int v = p[u]->v;
        p[u] = p[u]->nxt;
        dfs(v);
        ans.push_back(u);
    }
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    rep(i, 1, m){
        int u, v; cin >> u >> v; addedge(u, v); addedge(v, u);
    }
    dfs(1);
    for(int i = ans.size() - 1; i >= 0; --i) cout << ans[i] << ' ';
    cout << 1 << endl;
    return 0;
}
