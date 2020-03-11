#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;
const int N = 100010, P = 102;
const ll inf = 0x3f3f3f3f3f3f3f3fll;
ll d[N], t[N], a[N], c[N], f[P][N];
int q[N], l, r;
#define y(x) (f[i-1][x]+c[x])
int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int n, m, p;
    cin >> n >> m >> p;
    rep(i, 2, n){
        ll x; cin >> x;
        d[i] = d[i-1] + x;
    }
    rep(i, 1, m){
        int h, t;
        cin >> h >> t;
        a[i] = t - d[h];
    }
    std::sort(a+1, a+1+m);
    rep(i, 1, m) c[i] = c[i-1] + a[i];
    std::memset(f, 0x3f, sizeof(f));
    f[0][0] = 0;
    rep(i, 1, p){
        q[l = r = 1] = 0;
        rep(j, 1, m){
            while(l < r && (y(q[l+1]) - y(q[l])) <= a[j]*(q[l+1]-q[l])) ++l;
            f[i][j] = std::min(f[i][j], y(q[l]) + a[j]*(j-q[l])-c[j]);
            if (y(j) >= inf) continue;
            while (l < r && (y(q[r])-y(q[r-1]))*(j-q[r])>=(y(j)-y(q[r]))*(q[r]-q[r-1])) --r;
            q[++r] = j;
        }
    }
    cout << f[p][m];
    return 0;
}