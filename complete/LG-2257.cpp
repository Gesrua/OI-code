#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl; using std::make_pair; using std::pair;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull; typedef pair<int, int> pii; 

const int N = 1e7+10, n = 1e7;

int p[700000], mu[N], isp[N], g[N], sg[N], cg[N];

void euler(){
    std::memset(isp, 1, sizeof(isp));
    isp[0] = isp[1] = 0;
    mu[1] = 1;
    for(int i = 2; i <= n; ++i){
        if (isp[i]) p[++p[0]] = i, mu[i] = -1;
        for(int j = 1; j <= p[0] && i*p[j] <= n; ++j){
            isp[i*p[j]] = 0;
            mu[i*p[j]] = -mu[i];
            if (i % p[j] == 0){
                mu[i*p[j]] = 0;
                break;
            }
        }
    }
    rep(i, 1, p[0]){
        for(int j = 1; j*p[i] <= n; ++j){
            g[j*p[i]] += mu[j];
        }
    }
    rep(i, 1, n) sg[i] = g[i] + sg[i-1];
    // rep(i, 1, 100) cerr << sg[i] << ' ';
}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);

    euler();

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m; int mi = std::min(n, m);
        ll ans = 0;
        for(int l = 1, r; l <= mi; l = r+1){
            r = std::min(n/(n/l), m/(m/l));
            ans += 1ll * (n/l) * (m/l) * (sg[r] - sg[l-1]);
        }
        cout << ans << endl;
    }

    return 0;
}