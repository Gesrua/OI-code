#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
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
typedef pair<int, int> pii;
long long a[200009], nxt[200009];
typedef long long ll;
// const long long max = 2000000000000000000;
int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    rep(i, 0, n - 1) { cin >> a[i]; }
    per(i, n - 1, 0) {
        if (a[i] == 1) nxt[i] = nxt[i + 1] + 1;
    }
    long long max = (ll)100000000 * k * n;
    // long long max = 2e18;
    long long ans = 0;
    rep(i, 0, n - 1) {
        long long p = 1, s = 0;
        rep(j, i, n - 1) {
            if (max / a[j] < p) break;
            if (a[j] == 1) {
                if (p % k == 0) {
                    long long need = p / k - s;
                    // cerr << p << ' ' << k << endl;
                    if (need > 0 && need <= nxt[j]) {
                        ++ans;
                    }
                }
                s += nxt[j];
                j += nxt[j] - 1;
                continue;
                // if (j >= n) break;
            }
            // if (j >= n) /break;
            p *= a[j];
            s += a[j];
            if (p == (ll)k * s) ++ans;
        }
    }
    cout << ans;
    return 0;
}