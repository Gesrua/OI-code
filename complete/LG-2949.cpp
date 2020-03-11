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
struct Node {
    int d;
    ll p;
    bool operator<(const Node& rhs) const { return d > rhs.d; }
} a[1000100];
std::priority_queue<ll> q;
int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n;
    cin >> n;
    rep(i, 1, n) cin >> a[i].d >> a[i].p;
    a[++n].d = 0;
    ll ans = 0;
    std::sort(a + 1, a + 1 + n);
    int ed = a[1].d;
    rep(i, 1, n) {
        if (a[i].d < ed) {
            for (int j = ed - a[i].d; j > 0 && q.size() > 0; --j) {
                ans += q.top();
                q.pop();
            }
        }
        ed = a[i].d;
        q.push(a[i].p);
    }
    cout << ans << endl;
    return 0;
}