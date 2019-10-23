// #include <bits/stdc++.h>
#include <iostream>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
// using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;
const int N = 14, mod = 100000000;
int f[N][2<<N], a[N][N];

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> a[i][j];

    f[0][0] = 1;
    for (int i = 1; i <= n; ++i){
        for (int j = 0; j < (1<<m); ++j){
            bool valid = 1;
            for (int k = 0; k < m; ++k)
                if (((j>>k)&1) && a[i][k] == 0 || (((j>>k)&1)&((j>>(k+1))&1))){
                    valid = 0;
                    break;
                }
            if (!valid) continue;
            for (int k = 0; k < (1<<m); ++k)
                if (!(j&k)) (f[i][j] += f[i-1][k]) %= mod;
        }
    }

    int ans = 0;
    for (int j = 0; j < (1<<m); ++j) (ans += f[n][j]) %= mod;

    cout << ans << endl;
    return 0;
}