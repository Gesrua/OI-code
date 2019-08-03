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

const int N = 500100;

struct Q {
    int id, l, r, ans;
} q[N];
int a[N], c[N], lst[1000100], n;

bool cmp_r(const Q& x, const Q& y) { return x.r < y.r; }
bool cmp_id(const Q& x, const Q& y) { return x.id < y.id; }
inline int lowbit(int i) { return i & (-i); }
void add(int i, int x) {
    for (; i <= n; i += lowbit(i)) c[i] += x;
}
int s(int i) {
    int ret = 0;
    for (; i > 0; i -= lowbit(i)) ret += c[i];
    return ret;
}
int ask(int l, int r) { return s(r) - s(l - 1); }

int main() {
#ifdef LOCAL
    freopen("/tmp/1878/1878/1.in", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    int m;
    cin >> m;
    rep(i, 1, m) {
        q[i].id = i;
        cin >> q[i].l >> q[i].r;
    }
    std::sort(q + 1, q + 1 + m, cmp_r);
    int idx = 1;
    rep(i, 1, m) {
        // cerr << i << endl;
        for (; idx <= q[i].r; ++idx) {
            // cerr << idx << endl;
            if (lst[a[idx]]) add(lst[a[idx]], -1);
            add(idx, 1);
            lst[a[idx]] = idx;
        }
        // cerr << "asking" << endl;
        q[i].ans = ask(q[i].l, q[i].r);
    }
    std::sort(q + 1, q + 1 + m, cmp_id);
    rep(i, 1, m) cout << q[i].ans << endl;
    return 0;
}