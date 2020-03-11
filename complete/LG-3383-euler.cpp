#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;

const int n = 10000000;
int c[n+10], p[n], cnt = 0;

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    c[1] = 1;
    rep(i, 2, n){
        if (!c[i]) p[++cnt] = i;
        for(int j = 1; j <= cnt && p[j]*i <= n; ++j){
            c[p[j]*i] = 1;
            if (i%p[j] == 0) break;
        }
    }
    int q; cin >> q >> q;
    while(q--){
        int x; cin >> x;
        puts(c[x]?"No":"Yes");
    }
    return 0;
}
