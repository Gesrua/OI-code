#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;

const int N = 200010, p = 10007;

std::vector<int> g[N];
ll sum; int mx, w[N], fa[N];

void calc(int u){
    // cerr << u << ' ' << fa[fa[u]] << endl;
    (sum += 2*w[u] * w[fa[fa[u]]]) %= p;
    mx = std::max(mx, w[u]*w[fa[fa[u]]]);
    ll sig = 0; int mx1 = 0, mx2 = 0;
    for(auto v : g[u])
        if (v != fa[u]){
            sig += w[v];
            if (w[v] >= mx1) mx2 = mx1, mx1 = w[v];
            else if (w[v] > mx2) mx2 = w[v];
        }
    mx = std::max(mx, mx1*mx2);
    for(auto v : g[u]){
        if (v == fa[u]) continue;
        (sum += (sig - w[v]) * w[v]) %= p;
        fa[v] = u;
        calc(v);
    }
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int n;
    cin >> n;
    rep(i, 2, n){
        int u, v; cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    }
    rep(i, 1, n) cin >> w[i];
    calc(1);
    cout << mx << ' ' << sum;
    return 0;
}
