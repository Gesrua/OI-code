#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;
const int N = 6009;
int siz[N], f[N];
struct Edge{ int u, v, w; } e[N];
bool cmp(const Edge& a, const Edge& b){ return a.w < b.w; }
int getf(int x){ return (f[x] == x) ? x : (f[x] = getf(f[x])); }
int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int T; cin >> T; int n;
    while(cin >> n){
        rep(i, 1, n) f[i] = i, siz[i] = 1;
        for(int i = 1; i < n; ++i) cin >> e[i].u >> e[i].v >> e[i].w;
        std::sort(e+1, e+n, cmp);
        ll ans = 0;
        for(int i = 1; i < n; ++i){
            int u = getf(e[i].u), v = getf(e[i].v);
            ans += ((ll)siz[u]*siz[v]-1)*(e[i].w+1);
            siz[u] += siz[v];
            f[v] = u;
        }
        cout << ans << endl;
    }
    return 0;
}
