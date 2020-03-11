#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;
const int N = 1e5 + 10;
ll a[N], f[N];
std::multiset<ll> s;
std::deque<int> q;

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int n; ll m; cin >> n >> m;
    rep(i, 1, n) { cin >> a[i]; if (a[i] > m) {cout << -1; return 0;} }
    q.push_back(0); s.insert(f[0] + a[1]);
    ll sum = 0; int lst = 1;
    rep(i, 1, n){
        sum += a[i];
        while(sum > m) sum -= a[lst++];
        int x;
        while(q.size() && q.front() < lst - 1){
            x = q.front(); q.pop_front();
            s.erase(f[x] + (q.size() ? a[q.front()] : a[i]));
        }
        x = i;
        if (q.size() && a[q.back()] <= a[i]){
            s.erase(f[q.back()] + a[i]);
            x = q.back(); q.pop_back();
            if (q.size()) s.erase(f[q.back()] + a[x]);
        }
        while(q.size() && a[q.back()] <= a[i]){
            x = q.back(); q.pop_back();
            if (q.size()) s.erase(f[q.back()] + a[x]);
        }
        if (q.size()) s.insert(f[q.back()] + a[i]);

        f[i] = f[lst-1] + (q.size() ? a[q.front()] : a[i]);
    
        if (q.size()) f[i] = std::min(f[i], *s.begin());

        q.push_back(i); s.insert(f[i]+a[i+1]);
    }
    cout << f[n] << endl;
    return 0;
}