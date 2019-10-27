#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;

const int N = 105, inf = 0x3f3f3f3f;

int g[N][N], d[N][N], pos[N][N];

std::vector<int> path;

void get_path(int i, int j){
    if (pos[i][j] == 0) return;
    get_path(i, pos[i][j]), path.push_back(pos[i][j]), get_path(pos[i][j], j);
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    std::memset(g, 0x3f, sizeof(g));
    int n, m; cin >> n >> m;
    rep(i, 1, n) g[i][i] = 0;
    while(m--){
        int u, v, w; cin >> u >> v >> w;
        if (w < g[u][v]) g[u][v] = g[v][u] = w;
    }
    memcpy(d, g, sizeof(g));
    int ans = inf;
    rep(k, 1, n){
        rep(i, 1, k-1) rep(j, i+1, k-1)
            if ((ll)d[i][j] + g[j][k] + g[k][i] < ans){
                ans = d[i][j] + g[j][k] + g[k][i];
                path.clear();
                path.push_back(i);
                get_path(i, j);
                path.push_back(j);
                path.push_back(k);
            }

        rep(i, 1, n) rep(j, 1, n)
            if (d[i][j] > d[i][k] + d[k][j]){
                d[i][j] = d[i][k] + d[k][j],
                pos[i][j] = k;
            }
    }
    if (ans == inf) cout << "No solution.";
    else for(auto i : path) cout << i << ' ';

    return 0;
}
