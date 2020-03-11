#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;
int f[13][4];
void init(){
    f[0][0] = 1;
    for(int i = 1; i <= 12; ++i){
        f[i][1] = f[i-1][0];
        f[i][2] = f[i-1][1];
        f[i][3] = 10*f[i-1][3] + f[i-1][2];
        f[i][0] = 9*(f[i-1][0]+f[i-1][1]+f[i-1][2]);
    }
}
int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    init();
    int T, n; cin >> T;
    while(cin >> n){
        int m = 1;
        for(; f[m][3] < n; ++m) ;
        cerr << m << endl;
        for(int i = m, k = 0; i; --i){
            rep(j, 0, 9){
                int cnt = f[i-1][3];
                if (j == 6 || k == 3)
                    for(int l = std::max(0, 3-k-(j==6)); l < 3; ++l)
                        cnt += f[i-1][l];
                if (cnt < n) n -= cnt;
                else{
                    cout << j;
                    if (k < 3){
                        if (j == 6) ++k;
                        else k = 0;
                    }
                    break;
                }
            }
        }
        cout << endl;
    }
    return 0;
}