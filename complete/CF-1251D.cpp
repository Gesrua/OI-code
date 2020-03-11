#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;
typedef pair<ll, ll> pll;
const int N = 200010;
pll a[N]; int n; ll s;

bool ok(ll mid){
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    ll ans = 0;
    std::vector<ll> v;
    rep(i, 1, n){
        if (a[i].second < mid) ++cnt1, ans += a[i].first;
        else if (a[i].first > mid) ++cnt3, ans += a[i].first;
        else v.push_back(a[i].first);
    }
    if (cnt1 > n/2) return 0;
    int need = std::max(0, n/2+1-cnt3);
    ans += need*mid;
    for(int i = 0; i < v.size() - need; ++i) ans += v[i];
    return ans <= s;
}

void solve(){
    cin >> n >> s;
    ll l = 0, r = s;
    rep(i, 1, n) cin >> a[i].first >> a[i].second;
    std::sort(a+1, a+1+n);

    while(l < r){
        ll mid = (l+r+1)/2;
        if(ok(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int t; cin >> t; while(t--) solve();
    return 0;
}
