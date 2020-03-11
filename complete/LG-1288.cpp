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
    int n, ans = 0, x = -1, y;
    cin >> n;
    rep(i, 1, n) {
        int t;
        cin >> t;
        if (t == 0) (x = (x == -1) ? i : x), y = i;
    }
    // cout << x << ' ' << y << endl;
    if ((x - 1) % 2 == 1) ans = 1;
    if ((n - y) % 2 == 1) ans = 1;
    cout << (ans ? "YES" : "NO") << endl;
    return 0;
}