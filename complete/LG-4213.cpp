#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl; using std::make_pair; using std::pair;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull; typedef pair<int, int> pii; 

const int S = 2642245;

int mu[S+1], p[200000], isp[S+1], smu[S+1];

std::map<ll, ll> b_smu;

void euler(){
    std::memset(isp, 1, sizeof(isp));
    isp[0] = isp[1] = 0;
    mu[1] = 1;
    for(int i = 2; i <= S; ++i){
        if (isp[i]) p[++p[0]] = i, mu[i] = -1;
        for(int j = 1; i*p[j] <= S; ++j){
            isp[i*p[j]] = 0;
            mu[i*p[j]] = -mu[i];
            if (i % p[j] == 0){
                mu[i*p[j]] = 0;
                break;
            }
        }
    }
    // rep(i, 1, 100) cerr << smu[i] << ' '; cerr << endl;
    rep(i, 1, S) smu[i] = smu[i-1] + mu[i];
}

ll s_mu(ll n){
    if (n <= S) return smu[n];
    if (b_smu.count(n)) return b_smu[n];
    ll ret = 1;
    for(ll l = 2, r; l <= n; l = r+1){
        // cerr << l << ' ' << r << ' ' << n << endl;
        r = std::min(n/(n/l), n);
        ret -= (r-l+1) * s_mu(n/l);
    }
    return b_smu[n] = ret;
}

ll s_phi(ll n){
    ll ret = 0;
    for(ll l = 1, r; l <= n; l = r+1){
        // cerr << l << ' ' << r << ' ' << n << endl;
        r = n/(n/l);
        ret += (s_mu(r) - s_mu(l-1)) * (n / l) * (n / l);
    }
    return (ret+1)/2;
}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);

    euler();

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << s_phi(n) << ' ' << s_mu(n) << endl;
    }

    return 0;
}