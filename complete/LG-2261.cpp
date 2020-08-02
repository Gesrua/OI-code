#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl; using std::make_pair; using std::pair;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull; typedef pair<int, int> pii; 
int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    for(ll l = 1, r, p; l <= n; l = r+1){
        p = k/l;
        if (p == 0) break;
        r = std::min(k/p, n);
        ans += (l+r)*(r-l+1)/2 * p;
    }
    ans = n*k - ans;
    cout << ans << endl;
    return 0;
}