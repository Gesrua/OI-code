#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;

const int p = 1e9+7;

ll ksm(ll a, ll n, ll p){
    ll ret = 1;
    while(n){
        if (n&1) (ret *= a) %= p;
        (a *= a) %= p;
        n >>= 1;
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    ll n, m;
    cin >> n >> m;
    cout << ksm((ksm(2, m, p)-1+p)%p, n, p);
    return 0;
}
