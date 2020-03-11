#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;

const int N = 2e5 + 10;

std::vector<ll> v[N];

void solve(){
    int n; cin >> n;
    rep(i, 0, n) v[i].clear();
    rep(i, 1, n){
        ll m, p; cin >> m >> p; v[m].push_back(p);
    }
    std::multiset<ll> s;
    ll prev = n, cnt = 0, res = 0;
    per(i, n, 0){
        prev -= v[i].size();
        int need = i - prev - cnt;
        for(auto x : v[i]) s.insert(x);
        for(; need > 0; --need){
            ++cnt;
            res += *s.begin();
            s.erase(s.begin());
        }
    }
    cout << res << endl;
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int t; cin >> t; while(t--) solve();
    return 0;
}
