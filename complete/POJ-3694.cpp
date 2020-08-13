#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;
namespace UnionFindSet {
template <int N>
struct UnionFindSet {
    int fa[N];
    UnionFindSet() {
        for (register int i = 0; i < N; ++i) fa[i] = i;
    }
    int getf(int x) { return fa[x] = (fa[x] == x ? x : getf(fa[x])); }
    inline void merge(int x, int y) { fa[getf(x)] = getf(y); }
    inline bool same(int x, int y) { return getf(x) == getf(y); }
};
};  // namespace UnionFindSet

const int N = 1e5+10, M = 200010;
int e[M*2]; int tot = 2;
std::vector<int> ng[N], g[N];
int c[N], low[N], dfn[N], T, bridge[M*2];
UnionFindSet::UnionFindSet<N> ufs;
void tarjan(int u, int in_edge){
    low[u] = dfn[u] = ++T;
    for(auto i : g[u]){
        if (i == (in_edge^1)) continue;
        int v = e[i];
        if (!dfn[v]){
            tarjan(v, i);
            low[u] = std::min(low[u], low[v]);
            if (low[v] > dfn[u]) bridge[i] = bridge[i^1] = 1;
        } else low[u] = std::min(low[u], dfn[v]);
    }
}
int fa[N], dep[N];
void dfs(int u){
    for(auto v : ng[u]){
        if (v == fa[u]) continue;
        fa[v] = u;
        dep[v] = dep[u] + 1;
        dfs(v);
    }
}
int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int n, m, q, kase = 0;
    while(cin >> n >> m && n){
        kase++;
        tot = 2, T = 0;
        rep(i, 1, n) g[i].clear(), ng[i].clear(), ufs.fa[i] = i;
        std::memset(bridge, 0, sizeof(bridge));
        std::memset(e, 0, sizeof(e));
        std::memset(dep, 0, sizeof(dep));
        std::memset(low, 0, sizeof(low));
        std::memset(dfn, 0, sizeof(dfn));



        rep(i, 1, m){
            int u, v; cin >> u >> v;
            // g[u].push_back(v), g[v].push_back(u);
            e[tot] = v, g[u].push_back(tot++);
            e[tot] = u, g[v].push_back(tot++);
        }
        tarjan(1, 0);
        rep(u, 1, n)
            for(auto i : g[u])
                if (!bridge[i])
                    ufs.merge(u, e[i]);
        int cnt = 0;
        rep(u, 1, n)
            for(auto i : g[u])
                if (bridge[i]){
                    ng[ufs.getf(u)].push_back(ufs.getf(e[i]));
                    ng[ufs.getf(e[i])].push_back(ufs.getf(u));
                    cnt++;
                }
        cnt /= 2;
        // cerr << "bridge number " << cnt << endl;

        int rt = ufs.getf(1);
        dfs(rt);

        cin >> q;
        cout << "Case " << kase << ":\n";
        while(q--){
            int u, v;
            cin >> u >> v;
            u = ufs.getf(u), v = ufs.getf(v);
            while(u != v){
                if (dep[u] < dep[v]) std::swap(u, v);
                int f = ufs.getf(fa[u]);
                --cnt;
                ufs.fa[u] = f;
                u = f;
            }
            cout << cnt << endl;
        }
        cout << endl;
    }

    return 0;
}
