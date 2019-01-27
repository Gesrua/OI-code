#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
const int MOD = 20123;
unsigned int n, m, ans;
struct node {
    bool flag;
    int s;
} a[10000][100];
int next(int x) {
    if (x == m - 1) return 0;
    return x + 1;
}
int prev(int x) {
    if (x == 0) return m - 1;
    return x - 1;
}
int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    unsigned int i, j, k, tot[10000], ans = 0, now, t, start;
    for (i = 0; i < n; ++i) {
        tot[i] = 0;
        for (j = 0; j < m; ++j) {
            cin >> t;
            a[i][j].flag = t;
            cin >> a[i][j].s;
            if (t) ++tot[i];
        }
    }
    cin >> start;
    for (i = 0; i < n; ++i) {
        t = a[i][start].s % tot[i];
        if (t == 0) t = tot[i];
        ans += a[i][start].s;
        ans %= MOD;
        now = start;
        while (true) {
            if (a[i][now].flag) --t;
            if (t == 0) break;
            now = next(now);
        }
        // cout << a[i][start].s << endl;
        start = now;
    }
    cout << ans % MOD;
    return 0;
}