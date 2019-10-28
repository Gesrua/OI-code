#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;
const int N = 100009, M = 300009;
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
UnionFindSet::UnionFindSet<N> ufs;
int tag[M];
struct Edge{
    int u, v, w;
} e[M];
bool cmp_w(const Edge& a, const Edge& b){return a.w < b.w;}
std::vector<pii> g[N];
pii merge(pii x, pii y){
    static int a[4];
    a[0] = x.first, a[1] = x.second,
    a[2] = y.first, a[4] = y.second;
    std::sort(a,a+4,std::greater<int>());
    std::unique(a,a+4);
    return {a[0], a[1]};
}
const int K = 18;
int dep[N], fa[K+1][N];
pii f[K+1][N];
void dfs(int u){
    for(auto i : g[u]){
        int v = i.first, w = i.second;
        if (v == fa[0][u]) continue;
        f[0][v].first = w;
        fa[0][v] = u;
        dep[v] = dep[u] + 1;
        dfs(v);
    }
}
pii query(int u, int v){
    pii ret;
    if (dep[u] < dep[v]) std::swap(u, v);
    int d = dep[u] - dep[v];
    per(k, K, 0)
        if (d & (1<<k)){
            ret = merge(ret, f[k][u]);
            u = fa[k][u];
        }
    if (u == v) return ret;
    per(k, K, 0)
        if (fa[k][u] != fa[k][v]){
            ret = merge(ret, f[k][u]);
            ret = merge(ret, f[k][v]);
            u = fa[k][u], v = fa[k][v];
        }
    ret = merge(ret, f[0][u]);
    ret = merge(ret, f[0][v]);
    return ret;
}
int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int n, m; cin >> n >> m;
    rep(i, 1, m) cin >> e[i].u >> e[i].v >> e[i].w;
    std::sort(e+1, e+1+m, cmp_w);
    ll ans = 0;
    rep(i, 1, m)
        if (!ufs.same(e[i].u, e[i].v)){
            ufs.merge(e[i].u, e[i].v);
            g[e[i].u].push_back({e[i].v, e[i].w});
            g[e[i].v].push_back({e[i].u, e[i].w});
            ans += e[i].w;
            tag[i] = 1;
        }
    dep[1] = 1, dfs(1);
    rep(k, 1, K)
        rep(i, 1, n){
            fa[k][i] = fa[k-1][fa[k-1][i]];
            f[k][i] = merge(f[k-1][i], f[k-1][fa[k-1][i]]);
        }
    int d = 1e9+1;
    pii t;
    rep(i, 1, m){
        if (!tag[i]){
            t = query(e[i].u, e[i].v);
            if (t.first == e[i].w) d = std::min(d, e[i].w - t.second);
            else d = std::min(d, e[i].w - t.first);
        }
    }
    cout << ans + d;
    return 0;
}
