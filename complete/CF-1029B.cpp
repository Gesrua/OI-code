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
using std::max;
using std::pair;
typedef pair<int, int> pii;
int n;
int a[200005];
int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    int ans = 0, t = 0, prev = 2100000000;
    per(i, n, 1) {
        if (a[i] < prev) {
            if (ans < t) ans = t;
            t = 1;
            prev = (a[i] + 1) / 2;
        } else {
            prev = (a[i] + 1) / 2;
            ++t;
        }
    }
    ans = max(t, ans);
    cout << ans;
    return 0;
}
