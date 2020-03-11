#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;

const int p[] = {1,2,3,5,7,11,13,17,19,23,29}, l = 10; // 1~10

ll po[10][35];

int c[12], ans = 0, n;
ll ansc = 0;

void dfs(int i, ll s){
    // cerr << s << endl;
    if (s > n || s <= 0) return;
    if (i == 11 || c[i-1] == 0){
        // cerr << s << endl;
        ll cnt = 1;
        rep(k, 1, i-1) cnt *= c[k]+1;
        assert(s <= n);
        if (cnt > ansc || (cnt == ansc && s < ans)) {
            // cerr << s << endl;
            ansc = cnt;
            ans = s;
            // cerr << "ans = " << ans << endl;
        }
        return;
    }
    per(k, c[i-1], 0){
        c[i] = k;
        dfs(i+1, s*po[i][k]);
    }
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    rep(i, 0, 10){
        po[i][0] = 1;
        rep(j, 1, 30){
            po[i][j] = p[i] * po[i][j-1];
            // cerr << po[i][j] << endl;
        }
    }
    ans = ansc = 0;
    cin >> n;
    c[0] = 30;
    dfs(1, 1);
    cout << ans;
    return 0;
}
