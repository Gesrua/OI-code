#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;

int n, k;
int f[5000], s[20], mx = 0;
int v[20], ans = 0;

int dp(int n){
    std::memset(f, 0x3f, sizeof(f)); f[0] = 0;
    rep(i, 1, n){
        rep(j, s[i-1], s[i]-1) if (f[j] > k) return j-1;

        rep(j, 0, mx){
            // cerr << mx << ' ';
            assert(mx < 5000);
            if (f[j] < k && f[j]+1 < f[j+s[i]]){
                f[j+s[i]] = f[j]+1;
                mx = std::max(mx, j+s[i]);
            }
        }
    }
    rep(j, s[n], mx) if (f[j] > k) return j-1;
    return mx;
}

void dfs(int c, int mx){
    if (c == n+1){
        if (mx > ans){
            ans = mx;
            rep(i, 1, n) v[i] = s[i];
        }
        return;
    }
    for(int i = mx+1; i >=  s[c-1] + 1; --i){    
        s[c] = i;
        dfs(c+1, dp(c));
    }
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> k; std::swap(n, k);
    dfs(1, 0);
    rep(i,1,n) cout << v[i] << ' '; cout << endl;
    cout << "MAX=" << ans;
    return 0;
}
