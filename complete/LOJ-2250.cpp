#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl; using std::make_pair; using std::pair;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull; typedef pair<int, int> pii; 

const int N = 5e5 + 10, rqy = 998244353;

std::vector<int> g[N];

int a[N], h[N], f[N];
int dfn[N], dfnt, d[N], tag[N], low[N], rev[N];

bool is_catus;

int dfs(int u, int fa){
    // cerr << u << endl;
    dfn[u] = low[u] = ++dfnt; rev[dfn[u]] = u;
    int ret = 0;
    for(auto v : g[u]){
        if (v == fa) continue;
        if (dfn[v]){
            if (dfn[v] < dfn[u]){
                // cerr << u << ' ' << v << endl;
                d[u]++; d[v]--;
                low[u] = std::min(low[u], dfn[v]);
            }
        } else {
            int x = dfs(v, u);
            ret += x;
            low[u] = std::min(low[u], low[v]);
        }
    }
    ret += d[u];
    if (ret > 1) is_catus = false;
    if (low[u] != dfn[u]) tag[u] = low[u];
    else tag[u] = dfn[u];
    return ret;
}

int find(int x){ return dfn[x] == tag[x] ? dfn[x] : (tag[x]  = find(rev[tag[x]])); }

void calc(int u, int fa){
    // cerr << "into " << u << endl;
    // assert(f[u] == 0);
    // if (tag[u]){ f[u] = h[u] = 1; return; }
    int s = 0;
    ll pihv = 1;
    for(auto v : g[u]){
        if (v == fa || tag[u] == tag[v]) continue;
        // cerr << u << ' ' << v << ' ' << tag[u] << ' ' << tag[v] << endl;
        s++;
        calc(v, u);
        pihv = pihv * h[v] % rqy;
    }
    f[u] = pihv * a[s] % rqy;
    assert(f[u] != 0);
    h[u] = (f[u] + s * pihv % rqy * a[s-1] % rqy) % rqy;
}

void solve(){
    dfnt = 0; is_catus = true;
    int n, m; cin >> n >> m;
    rep(i, 1, n) dfn[i] = low[i] = tag[i] = f[i] = h[i] = d[i] = 0;
    rep(i, 1, n) g[i].clear();

    rep(i, 1, m){ int u, v; cin >> u >> v; g[u].push_back(v); g[v].push_back(u); }

    dfs(1, 1);

    rep(i, 1, n) find(i);

    // rep(i, 1, n) cerr << tag[i] << ' '; cerr << endl;

    if (!is_catus){ cout << 0 << '\n'; return; }
    // cerr << "counting" << endl;
    ll ans = 1;
    rep(i, 1, n){
        if (f[i] == 0){
            calc(i, i);
            // cerr << i << ' ' << f[i] << endl;
            // cerr << "-----" << endl;
            (ans *= f[i]) %= rqy;
        }
    }
    cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int T; cin >> T;
    a[0] = a[1] = 1;
    rep(i, 2, 500000) a[i] = (a[i-1] + (ll)a[i-2]*(i-1)) % rqy;
    while(T--) solve();
    return 0;
}