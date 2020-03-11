#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;
int a[309][309];
int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int n;
    cin >> n;
    for(int j = 1; j <= n; j += 2){
        int k = n * (j-1);
        rep(i, 1, n) a[i][j] = k + i;
    }
    for(int j = 2; j <= n; j += 2){
        int k = n * j + 1;
        rep(i, 1, n) a[i][j] = k - i;
    }
    rep(i, 1, n){
        rep(j, 1, n) cout << a[i][j] << ' ';
        cout << endl;
    }
    return 0;
}
