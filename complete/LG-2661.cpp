#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
using std::min;
char s[20000001];
int stl;
inline void rd(int &x) {
    x = 0;
    for (; !isdigit(s[stl]); ++stl)
        ;
    for (; isdigit(s[stl]); ++stl) x = (x << 3) + (x << 1) + s[stl] - '0';
}
int main() {
    fread(s, 20000000, 1, stdin);
    int n, t[200010];
    rd(n);
    for (int i = 1; i <= n; ++i) rd(t[i]);
    int cnt, ans = 2100000000;
    int flag[200010] = {}, a[200010] = {};
    // flag 盖戳
    // a 第几次盖戳
    // std::memset(flag, 0, sizeof(flag));
    for (int i = 1; i <= n; ++i) {
        if (a[i]) continue;
        cnt = 1;
        for (register int j = t[i];; j = t[j]) {
            if (a[j] != 0 && a[j] != i) break;
            if (flag[j]) {
                ans = min(ans, cnt - flag[j]);
                break;
            }
            flag[j] = cnt;
            a[j] = i;
            ++cnt;
        }
    }
    cout << ans;
    return 0;
}