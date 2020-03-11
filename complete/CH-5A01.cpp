#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;
const int N = 5010, inf = 0x3f3f3f3f;
int st[N], sc[N], S;
int f[N];
int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int n;
    cin >> n >> S;
    rep(i, 1, n){
        int t, c;
        cin >> t >> c;
        st[i] = st[i-1] + t, sc[i] = sc[i-1] + c;
    }
    rep(i, 1, n){
        f[i] = inf;
        rep(j, 0, i - 1){
            f[i] = std::min(f[i], f[j] + st[i]*(sc[i]-sc[j]) + S*(sc[n] - sc[j]));
        }
    }
    cout << f[n];
    return 0;
}