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
typedef long long ll;
typedef unsigned int ui;
typedef pair<ui, int> pii;
int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    std::stack<pii> s;
    int n;
    ui x = 0;
    cin >> n;
    s.push(pii(2147483648u, 0));
    ll ans = 0;
    ui pre = 0;
    rep(i, 1, n) {
        cin >> x;
        if (x >= pre) --ans, pre = x;  // 维护全局最大值，因为最先有 inf
        while (s.top().first < x) ans += s.top().second, s.pop();
        if (x == s.top().first)
            ans += s.top().second + 1, s.top().second++;
        else
            ++ans, s.push(pii(x, 1));
    }

    cout << ans;
    return 0;
}