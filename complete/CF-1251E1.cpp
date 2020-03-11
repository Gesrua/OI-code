#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;

const int N = 5050;

ll f[N][N];
struct P{
    ll p, m;
} a[N];
bool cmp(const P&a, const P&b){return a.m < b.m;}

void solve(){
    int n; cin >> n;
    rep(i, 1, n) cin >> a[i].m >> a[i].p;
    std::sort(a+1, a+1+n, cmp);
    rep(i, 1, n){
        rep(j, 0, n){
            f[i][j] = f[i-1][j+1] + a[i].p;
            if (i-1+j >= a[i].m) f[i][j] = std::min(f[i][j], f[i-1][j]);
        }
    }
    rep(i, 0, n){
        rep(j, 0, n) cerr << f[i][j] << ' ';
        cerr << endl;
    }
    cout << f[n][0] << endl;
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int t; cin >> t; while(t--) solve();
    return 0;
}
