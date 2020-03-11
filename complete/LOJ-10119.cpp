#include <cctype>
#include <cstdio>
#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::isdigit;
using std::max;
int mi[20];
int n, m, a[int(1e5 + 9)];
int bfr[18][int(1e5 + 9)], aft[18][int(1e5 + 9)];
int log233[int(1e5 + 9)];
char s[30000001];
int stl = 0;
inline void rd(int &x) {
    x = 0;
    for (; !isdigit(s[stl]); ++stl)
        ;
    for (; isdigit(s[stl]); ++stl) x = (x << 3) + (x << 1) + s[stl] - '0';
}
int main() {
    fread(s, 30000000, 1, stdin);
    mi[0] = 1;
    for (int i = 1; i < 20; ++i) mi[i] = mi[i - 1] << 1;
    std::ios::sync_with_stdio(false);
    // cin >> n >> m;
    rd(n);
    rd(m);
    for (int i = 1; i <= n; ++i) {
        // cin >> a[i];
        rd(a[i]);
        bfr[0][i] = aft[0][i] = a[i];
    }
    for (int i = 0; i < 18; ++i) {
        for (int j = mi[i]; j < mi[i + 1] && j <= n; ++j) log233[j] = i;
    }
    int lim = log233[n] + 1;
    for (int k = 1; k <= lim; ++k) {
        for (int i = 1; i <= n; ++i) {
            if (i + mi[k] <= n)
                aft[k][i] = max(aft[k - 1][i], aft[k - 1][i + mi[k - 1]]);
            else
                aft[k][i] = aft[k - 1][i];
        }
        for (int i = n; i >= 1; --i) {
            if (i - mi[k] > 0)
                bfr[k][i] = max(bfr[k - 1][i], bfr[k - 1][i - mi[k - 1]]);
            else
                bfr[k][i] = bfr[k - 1][i];
        }
    }
    // for (int i = 0; i <= lim; ++i){
    //     for (int j = 1; j <= n; ++j)
    //         cerr << aft[i][j] << ' ';
    //     cerr << endl;
    // }
    // cerr << endl;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        // cin >> x >> y;
        rd(x);
        rd(y);
        cout << max(aft[log233[y - x]][x], bfr[log233[y - x]][y]) << endl;
    }
    return 0;
}