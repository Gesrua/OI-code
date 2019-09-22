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
int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, s = 0, ans = 1;
    cin >> n;
    rep(i, 1, n) {
        int t = i;
        while (!(t & 1)) s++, t >>= 1;
        while (t % 5 == 0) s--, t /= 5;
        (ans *= t) %= 10;
    }
    rep(i, 1, s)(ans <<= 1) %= 10;
    cout << ans;
    return 0;
}