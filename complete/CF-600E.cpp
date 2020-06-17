#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl; using std::make_pair; using std::pair;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull; typedef pair<int, int> pii; 

const int N =  1e5+10;

int c[N], n;
std::vector<int> g[N];

int siz[N], son[N];

void dfs1(int u, int fa){
    siz[u] = 1;
    for(auto v : g[u]){
        if (v == fa) continue;
        dfs1(v, u);
        siz[u] += siz[v];
        if (siz[son[u]] < siz[v]) son[u] = v;
    }
}

int cnt[N]; ll sum[N]; int mx; ll ans[N];

void erase(int u, int fa){
    cnt[c[u]] = 0;
    for(auto v : g[u]){
        if (v == fa) continue;
        erase(v, u);
    }
}
void add(int u, int fa, int p){
    sum[cnt[c[u]]] -= c[u];
    cnt[c[u]]++;
    sum[cnt[c[u]]] += c[u];
    mx = std::max(mx, cnt[c[u]]); 
    for(auto v : g[u]){
        if (v == fa || v == p) continue;
        add(v, u, p);
    }
}

void calc(int u, int fa, int clean){
    for(auto v : g[u]){
        if (v == fa || v == son[u]) continue;
        calc(v, u, 1);
    }
    if (son[u]) calc(son[u], u, 0);

    add(u, fa, son[u]);
    ans[u] = sum[mx];

    if (clean){
        rep(i, 0, mx) sum[i] = 0;
        mx = 0;
        erase(u, fa);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n; rep(i, 1, n) cin >> c[i];
    rep(i, 2, n){
        int u, v; cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }
    dfs1(1, 1);
    calc(1, 1, 0);
    rep(i, 1, n) cout << ans[i] << ' ';
    return 0;
}