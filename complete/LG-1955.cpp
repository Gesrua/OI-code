#include <algorithm>
#include <cassert>
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
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int ui;
struct N {
    int i, j, e;
} a[100010];
int uq[200010], f[200010];
inline int get(int x) {
    return std::lower_bound(uq + 1, uq + 1 + uq[0], x) - uq;
}
int getf(int x) { return x == f[x] ? x : (f[x] = getf(f[x])); }
int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        uq[0] = 0;
        int n;
        cin >> n;
        rep(i, 1, n) {
            cin >> a[i].i >> a[i].j >> a[i].e;
            uq[++uq[0]] = a[i].i;
            uq[++uq[0]] = a[i].j;
        }
        std::sort(uq + 1, uq + 1 + uq[0]);
        uq[0] = (std::unique(uq + 1, uq + 1 + uq[0]) - uq) - 1;
        rep(i, 0, uq[0]) f[i] = i;
        rep(i, 1, n) a[i].i = get(a[i].i), a[i].j = get(a[i].j);
        rep(i, 1, n) {
            if (a[i].e == 1) {
                a[i].i = getf(a[i].i), a[i].j = getf(a[i].j);
                f[a[i].i] = a[i].j;
            }
        }
        bool flag = 1;
        rep(i, 1, n) {
            if (a[i].e == 0)
                if (getf(a[i].i) == getf(a[i].j)) {
                    flag = 0;
                    break;
                }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}