#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;

char s[100];
int a[60];

void solve(){
    int n, n1 = 0, n0 = 0;
    cin >> n;
    rep(i, 1, n){
        cin >> (s+1);
        a[i] = strlen(s+1);
        int k = a[i];
        rep(i, 1, k) n1 += (s[i] == '1'), n0 += (s[i] == '0');
    }
    std::sort(a+1, a+1+n);
    int ans = 0;
    rep(i, 1, n){
        // cerr << "n0 " << n0 << " n1 " << n1 << endl;
        if (a[i]&1){
            if (n1&1) n1--;
            else if (n0&1) n0--;
            else if (n1 > 1) n1--;
            else n0--;
            a[i] -= 1;
        }
        // cerr << "after n0 " << n0 << " n1 " << n1 << endl;

        int k = a[i] / 2;
        // cerr << "init k = " << k << endl;
        if (k > n0/2 + n1/2) break;
        if (k >= n0/2) k -= n0/2, n0 -= n0/2*2;
        else n0 -= 2*k, k = 0;
        if (k >= n1/2) k -= n1/2, n1 -= n1/2*2;
        else n1 -= 2*k, k = 0;
        ++ans;
    }
    cout << ans << endl;
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}
