#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;

namespace Euler_Prime{
template <int n>
struct Euler_Prime{
    int c[n+10], p[n], cnt = 0;
    Euler_Prime(){
        c[1] = 1;
        rep(i, 2, n){
            if (!c[i]) p[++cnt] = i;
            for(int j = 1; j <= cnt && p[j]*i <= n; ++j){
                c[p[j]*i] = 1;
                if (i%p[j] == 0) break;
            }
        }
    }
};
template <int n>
struct Phi{
    int c[n+10], p[n], cnt = 0, phi[n+10];
    Phi(){
        c[1] = 1;
        rep(i, 2, n){
            if (!c[i]) p[++cnt] = i, phi[i] = i-1;
            for(int j = 1; j <= cnt && p[j]*i <= n; ++j){
                c[p[j]*i] = 1;
                phi[p[j]*i] = phi[i] * (p[j] - 1);
                if (i%p[j] == 0) { phi[p[j]*i] = phi[i]*p[j]; break;}
            }
        }
    }
    int operator[](int x){return phi[x];}
};
};

const int N = 1010;

Euler_Prime::Phi<N> phi;

void solve(){
    int n;
    cin >> n;
    ll ans = 0;
    rep(i, 2, n) ans += phi[i];
    ans = 3 + 2 * ans;
    cout << n << ' ' << ans << endl;
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int t; cin >> t;
    rep(i, 1, t){
        cout << i << ' ';
        solve();
    }
    return 0;
}
