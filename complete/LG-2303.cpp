#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl; using std::make_pair; using std::pair;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull; typedef pair<int, int> pii; 

ll phi(ll p, ll n){
    ll ans = 1;
    rep(i, 1, n-1) ans *= p;
    return ans * (p-1);
}

ll phi(ll n){
    if (n == 1) return 1;
    ll ans = 1;
    for(ll i = 2; i*i <= n; ++i){
        if (n % i == 0){
            int c = 0;
            while(n%i == 0) n /= i, ++c;
            ans *= phi(i, c); 
        }
    }
    if (n != 1) ans *= (n-1);
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    ll n; cin >> n;
    ll ans = 0;
    for(ll d = 1; d*d <= n; ++d){
        if (n % d == 0){
            ans += d * phi(n/d);
            if (d*d == n) break;
            ans += n/d * phi(d);
        }
    }
    cout << ans << endl;
    return 0;
}