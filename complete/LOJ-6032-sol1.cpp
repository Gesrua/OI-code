#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;
using std::make_pair; using std::pair; typedef pair<int, int> pii; typedef pair<int, ll> pil;

const int N = 100010;

namespace DisjointSetUnion {
template <int N>
struct DisjointSetUnion {
    int fa[N];
    DisjointSetUnion() {
        for (register int i = 0; i < N; ++i) fa[i] = i;
    }
    int getf(int x) { return fa[x] = (fa[x] == x ? x : getf(fa[x])); }
    inline void merge(int x, int y) { fa[getf(x)] = getf(y); }
    inline bool same(int x, int y) { return getf(x) == getf(y); }
};
};  // namespace DisjointSetUnion
DisjointSetUnion::DisjointSetUnion<N> dsu;

struct OPT{
    int i, y, k;
} q[N+N];
inline bool cmp(const OPT& a, const OPT& b){
    return a.y != b.y ? a.y < b.y : a.k < b.k;
}
int f[N], g[N];

void solve(){
    for (register int i = 0; i < N; ++i) dsu.fa[i] = i;
    std::memset(f, 0, sizeof(f)); std::memset(g, 0, sizeof(g));
    int n, m; cin >> n >> m;
    int cnt = 0;
    rep(i, 1, n - 1){ q[++cnt].i = i; cin >> q[cnt].y; q[cnt].k = -1; }
    rep(i, 1, m){ ++cnt; cin >> q[cnt].i >> q[cnt].y >> q[cnt].k; }
    std::sort(q+1, q+1+cnt, cmp);
    rep(qaq, 1, cnt){
        int i = q[qaq].i, y = q[qaq].y, k = q[qaq].k;
        if (k == -1){
            int j = dsu.getf(i + 1); i = dsu.getf(i);
            f[i] += f[j], g[i] += g[j]; dsu.fa[j] = i;
        } else if (k == 0){
            i = dsu.getf(i);
            f[i]++; // y + 0.5 无水
        } else {
            i = dsu.getf(i);
            g[i]++;
            f[i] = std::max(f[i], g[i]); // y + 0.5 有水
        }
    }
    cout << f[dsu.getf(1)] << endl;
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
}
