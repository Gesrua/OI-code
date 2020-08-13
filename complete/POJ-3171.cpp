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

const int L = 86401, FIX = 5;
struct Node {
    int l, r;
    ll min;
} T[L * 4];
#define ls (c * 2)
#define rs ((c * 2) + 1)
void build(int c, int l, int r) {
    T[c].l = l, T[c].r = r, T[c].min = 1e9;
    if (l != r) {
        int mid = (l + r) / 2;
        build(ls, l, mid), build(rs, mid + 1, r);
    }
}
inline void maintain(int c) { T[c].min = std::min(T[ls].min, T[rs].min); }
void edit(int c, int p, int x) {
    if (T[c].l == T[c].r) {
        T[c].min = x;
        return;
    }
    if (p <= T[ls].r)
        edit(ls, p, x);
    else
        edit(rs, p, x);
    maintain(c);
}
ll query(int c, int L, int R) {
    if (L <= T[c].l && T[c].r <= R) return T[c].min;
    if (T[c].r < L || R < T[c].l) return 1e9;
    return std::min(query(ls, L, R), query(rs, L, R));
}
const int N = 10000;
struct W {
    int a, b, c;
    bool operator<(const W& rhs) const { return b < rhs.b; }
} a[N + 10];
ll f[L + 10];

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, m, e;
    cin >> n >> m >> e;
    rep(i, 1, n) cin >> a[i].a >> a[i].b >> a[i].c;
    std::sort(a + 1, a + 1 + n);
    build(1, 1, L + FIX);
    edit(1, m - 1 + FIX, 0);
    std::memset(f, 0x3f, sizeof(f));
    rep(i, 1, n) {
        // [ai, bi]
        // j in [ai - 1, bi - 1]
        f[a[i].b] = std::min(f[a[i].b], query(1, a[i].a - 1 + FIX, a[i].b - 1 + FIX) + a[i].c);
        edit(1, a[i].b + FIX, f[a[i].b]);
        // cerr << a[i].b << ' ' << f[a[i].b] << endl;
    }
    ll ans = 1e9;
    rep(i, e, L) ans = std::min(f[i], ans);
    if (ans == 1000000000) ans = -1;
    cout << ans;
    return 0;
}