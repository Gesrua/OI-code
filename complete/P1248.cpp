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
using std::max;
using std::pair;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int ui;

const int N = 1010;

int n;

struct Node {
    int a, b, idx;
    bool operator<(const Node& t) const {
        return (a + max(t.a, b) + t.b < t.a + max(a, t.b) + b);
    }
} p[N];

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n;
    int ans = 0, sa = 0, sb = 0;
    rep(i, 1, n) {
        cin >> p[i].a;
        p[i].idx = i;
    }
    rep(i, 1, n) {
        cin >> p[i].b;
        sb += p[i].b;
    }
    std::sort(p + 1, p + 1 + n);

    ans = 0, sa = 0;
    rep(i, 1, n) {
        sa += p[i].a;
        ans = max(ans, sa + sb);
        sb -= p[i].b;
    }
    cout << ans << endl;
    rep(i, 1, n) { cout << p[i].idx << ' '; }
    return 0;
}