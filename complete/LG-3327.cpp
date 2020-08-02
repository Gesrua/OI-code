#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl; using std::make_pair; using std::pair;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull; typedef pair<int, int> pii; 

const int N = 5e4+10, n = 5e4;

int p[700000], mu[N], isp[N], d[N], f[N], smu[N];

void euler(){
    std::memset(isp, 1, sizeof(isp));
    isp[0] = isp[1] = 0;
    smu[1] = mu[1] = 1, d[1] = 1, f[1] = 1;
    for(int i = 2; i <= n; ++i){
        if (isp[i]) p[++p[0]] = i, mu[i] = -1, d[i] = 2;
        smu[i] = smu[i-1] + mu[i];
        f[i] = f[i-1] + d[i];
        // cerr << i << ' ' << d[i] << endl;
        for(int j = 1; j <= p[0] && i*p[j] <= n; ++j){
            isp[i*p[j]] = 0;
            mu[i*p[j]] = -mu[i];
            d[i*p[j]] = d[i]*2;
            if (i % p[j] == 0){
                int a = 0, t = i;
                while(t % p[j] == 0) ++a, t /= p[j];
                d[i*p[j]] = d[i]/(a+1)*(a+2);
                mu[i*p[j]] = 0;
                break;
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);

    euler();

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m; int mi = std::min(n, m);
        ll ans = 0;
        // rep(d, 1, n){
        //     ans += mu[d] * f[n/d] * f[m/d];
        // }
        for(int l = 1, r; l <= mi; l = r+1){
            r = std::min(n/(n/l), m/(m/l));
            ans += 1ll * f[n/l] * f[m/l] * (smu[r] - smu[l-1]);
        }
        cout << ans << endl;
    }

    return 0;
}