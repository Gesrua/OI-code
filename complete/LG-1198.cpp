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

const int N = 200000;
ll T[200000 * 4];
#define ls (c * 2)
#define rs (c * 2 + 1)
int P, X;
void add(int c = 1, int l = 1, int r = N) {
    if (l == r) {
        T[c] = X;
        return;
    }
    int mid = (l + r) / 2;
    if (P <= mid)
        add(ls, l, mid);
    else
        add(rs, mid + 1, r);
    T[c] = std::max(T[ls], T[rs]);
}
int L, R;
ll q(int c = 1, int l = 1, int r = N) {
    if (r < L || R < l) return 0;
    if (L <= l && r <= R) return T[c];
    int mid = (l + r) / 2;
    return std::max(q(ls, l, mid), q(rs, mid + 1, r));
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int m, l;
    ll d;
    cin >> m >> d;
    ll t = 0, n;
    char opt;
    int cnt = 0;
    while (m--) {
        cin >> opt;
        if (opt == 'Q') {
            cin >> l;
            L = cnt - l + 1, R = cnt;
            cout << (t = q()) << endl;
        } else {
            cin >> n;
            P = ++cnt, X = (n + t) % d;
            add();
        }
    }
    return 0;
}