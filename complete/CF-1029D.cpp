#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define rep(i, l, r) for (register int i = (l); i <= (r); ++i)
#define per(i, l, r) for (register int i = (l); i >= (r); --i)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
typedef long long LL;
typedef pair<int, int> pii;
inline int dc(int x) {
    int ans = x == 0 ? 1 : 0;
    while (x) x /= 10, ++ans;
    return ans;
}
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    // std::ios::sync_with_stdio(false);
    int n, k;
    LL x, a[200009], d[200009];
    std::map<LL, LL> v[11];
    // while (cin >> n) cout << d(n) << endl;
    cin >> n >> k;
    LL ans = 0;
    rep(i, 1, n) {
        LL x;
        cin >> a[i];
        d[i] = dc(a[i]);
        a[i] %= k;
        x = a[i] * 10 % k;
        rep(j, 1, 10) {
            if (j == d[i] && (x + a[i] == k || x + a[i] == 0)) --ans;
            ++v[j][x];
            x *= 10;
            x %= k;
        }
    }
    // int ans = 0;
    rep(i, 1, n) {
        // int x = (k - a[i]%k)%k;
        auto x = v[d[i]].find((k - a[i] % k) % k);
        if (x != v[d[i]].end()) ans += x->second;
    }
    cout << ans;
    return 0;
}
