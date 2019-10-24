#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;
const int N = 3e5+100, inf = 0x3f3f3f3f;
ll st[N], sc[N], s, f[N];
int q[N], l, r;
int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int n;
    cin >> n >> s;
    rep(i, 1, n){
        int t, c;
        cin >> t >> c;
        st[i] = st[i-1] + t, sc[i] = sc[i-1] + c;
    }
    q[l=r=0]=0;
    rep(i, 1, n){
        while(l < r && f[q[l+1]]-f[q[l]] <= (sc[q[l+1]]-sc[q[l]])*(st[i]+s)) ++l;
        f[i] = f[q[l]] + st[i]*(sc[i]-sc[q[l]]) + s*(sc[n] - sc[q[l]]);
        // cerr << f[i] << ' ' << i << " <- " << q[l] << endl;
        while(l < r && (f[q[r]]-f[q[r-1]])*(sc[i]-sc[q[r]]) >= (f[i]-f[q[r]])*(sc[q[r]]-sc[q[r-1]])) --r;
        q[++r] = i;
    }
    cout << f[n];
    return 0;
}