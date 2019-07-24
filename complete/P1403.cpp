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
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n;
    ll ans = 0;
    cin >> n;
    rep(i, 1, n) {
        int t = n / i;
        ans += t * (n / t - i + 1);
        i = n / t;
    }
    // int i = 0;
    // per(t, n, 1) {
    //     ans += t * (n / t - i);
    //     i = n / t;
    // }
    cout << ans;
    return 0;
}