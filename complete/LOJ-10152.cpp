#include <cmath>
#include <iostream>
using std::max;
#define rep(i, l, r) for (register int i = (l); i <= (r); ++i)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
__int128 a[90] = {}, f[90][90] = {}, ans = 0;
char s[300];
void myitoa(__int128 v, char* s) {
    char temp;
    int i = 0, j;
    if (v == 0) {
        s[0] = '0';
        s[1] = '\0';
        return;
    }
    while (v > 0) {
        s[i++] = v % 10 + '0';
        v /= 10;
    }
    s[i] = '\0';
    j = 0;
    i--;
    while (j < i) {
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
        j++;
        i--;
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int k = 1; k <= n; ++k) {
        int x;
        rep(j, 1, m) {
            cin >> x;
            a[j] = x;
        }
        f[0][0] = 0;
        rep(i, 1, m) {
            f[i][0] = f[i - 1][0] + (a[m - i + 1] << i);
            rep(j, 1, i) {
                f[i][j] = max(f[i - 1][j] + (a[m - i + j + 1] << i),
                              f[i - 1][j - 1] + (a[j] << i));
            }
        }
        __int128 t = 0;
        rep(i, 0, m) t = max(t, f[m][i]);
        ans += t;
    }
    myitoa(ans, s);
    cout << s;
    // cout << ans;
    return 0;
}