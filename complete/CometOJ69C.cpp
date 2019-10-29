#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;

const int N = 2e5 + 10, inf = 0x3f3f3f3f;
typedef int Type;
typedef pair<int, Type> pii;
std::vector<pii> g[N]; Type f[N], d[N], h[N]; ll ans = 0;

void dfs1(int u, int fa){
    Type mx1 = -inf, mx2 = -inf;
    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i].first; Type w = g[u][i].second;
        if (v == fa) continue;
        dfs1(v, u);
        f[u] = std::max(f[u], f[v]);
        Type x = h[v] + w;
        if (x > mx1) mx2 = mx1, mx1 = x;
        else if (x > mx2) mx2 = x;
    }
    h[u] = std::max(0, mx1);
    f[u] = std::max(f[u], std::max(mx1+mx2, mx1));
}

struct S4{
    Type mx[4];
    S4(){mx[0]=mx[1]=mx[2]=0;}
    void insert(Type x){
        if (x > mx[0]){
            mx[2] = mx[1];
            mx[1] = mx[0];
            mx[0] = x; 
        } else {
            if (x > mx[1]){
                mx[2] = mx[1];
                mx[1] = x;
            } else if (x > mx[2]) mx[2] = x;
        }
    }
    Type query_max(Type ex){
        if (ex == mx[0]) return mx[1];
        else return mx[0];
    }
    Type query_sum(Type ex){
        if (ex == mx[0]) return mx[1] + mx[2];
        if (ex == mx[1]) return mx[0] + mx[2];
        else return mx[0] + mx[1];
    }
};

void dfs2(int u, int fa, Type uph, Type upf){
    S4 fs, hs;
    hs.insert(uph), fs.insert(upf);
    hs.insert(0);
    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i].first; Type w = g[u][i].second;
        if (v == fa) continue;
        fs.insert(f[v]); hs.insert(h[v] + w);
    }
    for(int i = 0; i < g[u].size(); ++i){
        int v = g[u][i].first; Type w = g[u][i].second;
        if (v == fa) continue;
        d[v] = std::max(fs.query_max(f[v]), hs.query_sum(h[v]+w));
        dfs2(v, u, w+hs.query_max(h[v]+w), std::max(d[v], w+hs.query_max(h[v]+w)));
    }
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int n; cin >> n; ll ans = 0;
    rep(i, 2, n){ int u, v, w; cin >> u >> v >> w; g[u].push_back(pii(v, w)), g[v].push_back(pii(u, w)); }
    dfs1(1, 0);
    dfs2(1, 0, 0, 0);
    rep(i, 2, n) ans = std::max(ans, (ll)f[i] * d[i]);

    std::memset(f, 0, sizeof(f)); std::memset(h, 0, sizeof(h)); 
    rep(u, 1, n){
        for(int i = 0; i < g[u].size(); ++i)
            g[u][i].second = -g[u][i].second;
    }
    dfs1(1, 0);
    dfs2(1, 0, 0, 0);
    rep(i, 2, n) ans = std::max(ans, (ll)f[i] * d[i]);

    cout << ans << endl;

    return 0;
}
