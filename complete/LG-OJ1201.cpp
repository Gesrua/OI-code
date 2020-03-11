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
#define ls (u << 1)
#define rs ((u << 1) | 1)

const int N = 50010;

inline int lowbit(int x) { return x & (-x); }

struct N {
    int sum, tag;
} T[N * 4];

int L, R;

inline void pushdown(int u, int l, int r) {
    if (T[u].tag) {
        T[ls].tag = T[rs].tag = 1;
        int mid = (l + r) / 2;
        T[ls].sum = mid - l + 1, T[rs].sum = r - mid;
    }
}

inline void pushup(int u) { T[u].sum = T[ls].sum + T[rs].sum; }

int _q(int u, int l, int r) {
    int mid = (l + r) / 2;
    if (r < L || R < l) return 0;
    if (L <= l && r <= R) return T[u].sum;
    pushdown(u, l, r);
    return _q(ls, l, mid) + _q(rs, mid + 1, r);
}

int q(int l, int r) {
    L = l, R = r;
    return _q(1, 1, N);
}

void _a(int u, int l, int r) {
    if (r < L || R < l) return;
    // cerr << l << ' ' << r << endl;
    if (L <= l && r <= R) {
        // cerr << l << ' ' << r << endl;

        T[u].tag = 1;
        T[u].sum = r - l + 1;
        // cerr << l << ' ' << r << ' ' << T[u].sum << endl;

        return;
    }
    int mid = (l + r) / 2;
    _a(ls, l, mid), _a(rs, mid + 1, r);
    pushup(u);
}

void add(int l, int r) {
    // cerr << "ADD " << l << ' ' << r << endl;
    L = l, R = r;
    _a(1, 1, N);
}

struct Node {
    int a, b, c;
} a[N];

bool cmp(const Node &a, const Node &b) { return a.b < b.b; }

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n;
    cin >> n;
    rep(i, 1, n) {
        cin >> a[i].a >> a[i].b >> a[i].c;
        a[i].a++, a[i].b++;
    }
    std::sort(a + 1, a + 1 + n, cmp);
    int ans = 0;
    rep(i, 1, n) {
        int u = a[i].c - q(a[i].a, a[i].b);
        if (u > 0) {
            int l = a[i].a, r = a[i].b;
            while (l + 1 < r) {
                // cerr << l << ' ' << r << endl;
                int mid = (l + r) / 2;
                int qa = q(mid, a[i].b);
                if (a[i].b - mid + 1 - qa >= u)
                    l = mid;
                else
                    r = mid - 1;
            }
            if (a[i].b - r + 1 == u + q(r, a[i].b))
                add(r, a[i].b);
            else
                add(l, a[i].b);
        }
    }
    cout << q(1, N);
    return 0;
}