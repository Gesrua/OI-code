#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;
const int N = 309, inf = 1e9;
std::vector<int> g[N];
int f[N][N], n, m, w[N];

void solve(int u){
    f[u][1] = w[u];
    for(auto v : g[u]){
        solve(v);
        for(int j = m; j >= 2; --j){
            for(int k = 1; k < j; ++k){ // k < j => j-l >= 1
                f[u][j] = std::max(f[u][j], f[u][j-k] + f[v][k]);
            }
        }
    }
    f[u][0] = 0;
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> m; ++m;
    rep(i, 1, n){
        int t; cin >> t >> w[i];
        g[t].push_back(i);
    }
    solve(0);
    int ans = 0;
    rep(i, 1, m) ans = std::max(ans, f[0][i]);
    cout << ans << endl;
    return 0;
}