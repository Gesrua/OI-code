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
typedef pair<int, int> pii;
int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, L, a;
    cin >> n >> L >> a;
    int ans = 0, last = 0;
    rep(i, 1, n) {
        int t, per;
        cin >> t >> per;
        ans += (t - last) / a;
        last = t + per;
    }
    ans += (L - last) / a;
    cout << ans;
    return 0;
}
