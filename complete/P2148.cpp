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
typedef unsigned long long ull;

#define c(x, p) (x % p ? x % p : p)

int sg(ui x, ui y) {
    for (ui i = 0, p = 2; i < 31; i++, p *= 2) {
        if ((c(x, p) <= p / 2) && (c(y, p) <= p / 2)) return i;
    }
    return 31;
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cerr << "doing " << T << endl;
        int n;
        cin >> n;
        n /= 2;
        int ans = 0;
        rep(i, 1, n) {
            int x, y;
            cin >> x >> y;
            // cerr << x << ' ' << y << endl;
            ans ^= sg(x, y);
        }
        cout << (ans ? "YES" : "NO") << std::endl;
    }
    return 0;
}