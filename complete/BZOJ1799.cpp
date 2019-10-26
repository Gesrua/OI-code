#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;
int bit[19];
ll f[19][164][164];
const ll po[19] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000, 100000000000, 1000000000000, 10000000000000, 100000000000000, 1000000000000000, 10000000000000000, 100000000000000000, 1000000000000000000};
int k;
#define mod(x) (((x)%k+k)%k)
ll calc(int i, int s, int r, int limit){
    if (!limit && f[i][s][r] != -1) return f[i][s][r];
    if (i == 0){
        if (r == 0 && s == 0) return f[i][s][r] = 1;
        else return f[i][s][r] = 0;         
    }
    int up = limit?bit[i]:9;
    ll ret = 0;
    for(int p = 0; p <= up && p <= s; ++p){
        ret += calc(i-1, s - p, mod(r-p*po[i-1]), limit&&(p==up));
    }
    if (!limit) f[i][s][r] = ret;
    return ret;
}

ll solve(ll n){
    int l = 1;
    ll ret = 0;
    for(ll x = n; x; x /= 10, ++l) bit[l] = x % 10;
    --l;
    int maxsum = 9*(l-1) + bit[l];
    for(k = 1; k <= maxsum; ++k){
        std::memset(f, -1, sizeof(f));
        ret += calc(l, k, 0, 1);
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    ll a, b;
    cin >> a >> b;
    cout << (solve(b) - solve(a-1));    
    return 0;
}