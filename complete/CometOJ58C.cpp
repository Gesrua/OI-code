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
#define int ll

int a[100100], pre[100100];

int q(int l, int r) { return (l <= r ? pre[r] - pre[l - 1] : 0); }

int32_t main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    int x, y;
    cin >> x >> y;
    rep(i, 2, n) {
        cin >> x;
        a[i - 1] = y * x;
        pre[i - 1] = pre[i - 2] + a[i - 1];
        cin >> y;
    }
    pre[n] = pre[n - 1];
    n -= 1;
    const int inf = 10000000000000LL;
    int mi = -inf, p = -inf;
    per(i, n + 1, 0) p = std::max(p, (1 - k) * a[i] + (1 - k * k) * q(i + 1, n) + mi), mi = std::max(mi, (1 - k) * a[i] - (1 - k * k) * q(i, n));
    cout << std::min(pre[n] - p, pre[n]);
    return 0;
}