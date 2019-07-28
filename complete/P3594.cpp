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
typedef pair<int, ll> pii;

const int N = 2000010;

ll a[N], s[N];

std::deque<pii> q;

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, d;
    ll p;
    cin >> n >> p >> d;
    rep(i, 1, n) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    int ans = d, l = 1, r = d;
    ll c = 0;
    q.push_back(pii(1, s[d]));
    for (; r <= n; ++r) {
        // c += a[r];
        c = s[r] - s[r - d];
        while (q.size() && q.back().second <= c) q.pop_back();
        q.push_back(pii(r - d + 1, c));
        c = s[r] - s[l - 1] - q.front().second;
        while (c > p) {
            ++l;
            while (q.size() && q.front().first < l) q.pop_front();
            c = s[r] - s[l - 1] - q.front().second;
        }
        ans = std::max(r - l + 1, ans);
        // for(q.size() && q.front().first)
    }
    cout << ans;
    return 0;
}