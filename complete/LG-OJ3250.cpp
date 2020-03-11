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

int a[80010];

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n;
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    std::stack<pii> s;
    ll ans = 0;
    per(i, n, 1) {
        while (s.size() && s.top().first < a[i]) s.pop();
        if (s.size())
            ans += s.top().second - i - 1;
        else
            ans += n - i;
        s.push(pii(a[i], i));
    }
    cout << ans;
    return 0;
}