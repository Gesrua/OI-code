#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;
char s[400010];
int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> s+1;
        int n = strlen(s+1), ans = 0;
        for(int i = 1, k = 0, bef = 0, all = 0; i <= n; ++i){
            if (k == 1) k += bef, bef = 0;
            if (k >= 2) k += bef + all, bef = all = 0;
            ans = std::max(ans, k);
            if (s[i] == '*') k = k + 1;
            else if (s[i] == '#') {
                if (s[i+1] == '#'){
                    if (s[i+2] == '*') {
                        if (k == 0) break;
                        i += 2;
                    } else break;
                } else {
                    if (s[i+1] == '*'){
                        if (k == 0) all += bef, bef = 0;
                    } else {
                        if (k == 0) break;
                        else k--, bef++;
                    }
                }
            }
            if (k == 1) k += bef, bef = 0;
            if (k >= 2) k += bef + all, bef = all = 0;
            ans = std::max(ans, k);
        }
        cout << ans << endl;
    }
    return 0;
}
