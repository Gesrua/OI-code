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
    void init(){
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
};

Euler_Prime::Euler_Prime<1000000> e;

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int n;
    cin >> n;
    e.init();
    rep(i, 1, e.cnt){
        int ans = 0;
        for(ll j = e.p[i]; j <= n; j *= e.p[i]){
            ans += n/j;
        }
        if (ans != 0) cout << e.p[i] << ' ' << ans << endl;
    }
    return 0;
}
