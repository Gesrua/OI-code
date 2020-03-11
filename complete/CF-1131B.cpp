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
int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, lx = 0, ly = 0, x = 0, y = 0, ans = 1, a = 0;
    cin >> n;
    rep(i, 1, n) {
        lx = x;
        ly = y;
        cin >> x >> y;
        if (lx == x && ly == y) continue;
        int t = std::max(lx, ly), s = std::min(x, y);
        // cerr << t << ' ' << s << endl;
        if (s < t) continue;
        ans += s - t + 1;
        if (a == t) ans--;
        a = s;
    }
    // if (x == y) ++ans;
    cout << ans << endl;
    return 0;
}
