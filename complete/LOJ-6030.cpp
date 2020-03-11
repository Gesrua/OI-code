#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;
using std::make_pair; using std::pair; typedef pair<int, int> pii; typedef pair<int, ll> pil;

const int N = 2010, inf = 1e8;

int hang[N], lie[N], cnt[N], cntlie[N];
char g[N][N];

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int n; cin >> n;
    rep(i, 1, n) cin >> g[i] + 1;
    int ans = inf, all = 0;
    rep(i, 1, n){
        rep(j, 1, n) if (g[i][j] == '.') cnt[i]++;
        hang[i] = (cnt[i] < n);
        all += cnt[i];
    }
    if (all == 0) { cout << 0 << endl; return 0;}
    int d = n;
    rep(j, 1, n){
        rep(i, 1, n) if (g[i][j] == '.') cntlie[j]++;
        lie[j] = (cntlie[j] < n);
        d -= (cntlie[j] == 0);
    }
    rep(i, 1, n){
        int t = 0;
        bool flag = 0;
        if (lie[i]) flag = 1;
        else if (hang[i]) flag = 1, t = 1;
        if (flag){
            ans = std::min(ans, t + cnt[i] + d);
        }
    }
    if (ans == inf) ans = -1;
    cout << ans << endl;
    return 0;
}
