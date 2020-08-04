#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl; using std::make_pair; using std::pair;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull; typedef pair<int, int> pii; 

const int S = 2642245;

int phi[S+1], p[200000], isp[S+1];

ll f[S+1], sf[S+1], inv4, inv6;

std::map<ll, ll> b_sf;

ll n; int rqy;

void euler(){
    std::memset(isp, 1, sizeof(isp));
    isp[0] = isp[1] = 0;
    phi[1] = 1;
    for(int i = 2; i <= S; ++i){
        if (isp[i]) p[++p[0]] = i, phi[i] = i-1;
        for(int j = 1; i*p[j] <= S; ++j){
            isp[i*p[j]] = 0;
            phi[i*p[j]] = phi[i] * (p[j]-1);
            if (i % p[j] == 0){
                phi[i*p[j]] = phi[i] * p[j];
                break;
            }
        }
    }
    rep(i, 1, S){
        f[i] = 1ll*i*i%rqy*phi[i]%rqy;
        (sf[i] = f[i] + sf[i-1]) %= rqy;
    }
}

ll inv(ll a){
    int n = rqy-2; ll ret = 1;
    while(n){
        if (n&1) (ret *= a) %= rqy;
        (a *= a) %= rqy;
        n >>= 1;
    }
    return ret;
}

ll s(ll n){
    n %= rqy;
    return inv4*n%rqy*n%rqy*(n+1)%rqy*(n+1)%rqy;
}

ll s_g(ll n){
    n %= rqy;
    return n*(n+1)%rqy*(2*n+1)%rqy*inv6%rqy;
}

ll s_f(ll n){
    if (n <= S) return sf[n];
    if (b_sf.count(n)) return b_sf[n];
    ll ret = s(n);
    for(ll l = 2, r; l <= n; l = r+1){
        r = n/(n/l);
        (ret -= s_f(n/l) * (s_g(r) - s_g(l-1)) % rqy) %= rqy;
    }
    return b_sf[n] = ret;
}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    
    cin >> rqy >> n;

    inv4 = inv(4), inv6 = inv(6);

    euler();

    ll ret = 0;

    for(ll l = 1, r; l <= n; l = r+1){
        r = n/(n/l);
        (ret += s(n/l) * (s_f(r) - s_f(l-1))) %= rqy;
    }

    cout << (ret+rqy)%rqy << endl;

    return 0;
}