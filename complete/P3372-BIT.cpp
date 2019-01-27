#include <algorithm>
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
#define rep(i, l, r) for (register int i = (l); i <= (r); ++i)
#define per(i, l, r) for (register int i = (l); i >= (r); --i)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
typedef pair<int, int> pii;
typedef long long ui;
const int NMAX = 100010;
const int MMAX = 100010;

int n, m;

struct BIT {
    ui c[NMAX];
    int lowbit(int x) { return x & -x; }
    void add(int pos, ui x) {
        for (int i = pos; i <= n; i += lowbit(i)) c[i] += x;
    }
    ui sum(int n) {
        ui ret = 0;
        for (int i = n; i > 0; i -= lowbit(i)) ret += c[i];
        return ret;
    }
    ui query(int l, int r) { return sum(r) - sum(l); }
};

struct EXBIT {
    BIT t, s;
    void init(int pos, int add) {
        s.add(pos, add);
        t.add(pos, (pos - 1) * add);
    }
    void add(int l, int r, ui x) {
        s.add(l, x);
        s.add(r + 1, -x);
        t.add(l, (l - 1) * x);
        t.add(r + 1, -r * x);
    }
    ui _ask(int r) {
        if (r <= 0) return 0;
        return r * s.sum(r) - t.sum(r);
    }
    ui ask(int l, int r) { return _ask(r) - _ask(l - 1); }
} a;

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n >> m;
    int prev = 0, cur;
    rep(i, 1, n) {
        cin >> cur;
        a.init(i, cur - prev);
        prev = cur;
    }

    int opt, l, r;
    ui x;
    rep(i, 1, m) {
        cin >> opt >> l >> r;
        if (opt == 1) {
            // add
            cin >> x;
            a.add(l, r, x);
        } else {
            cout << a.ask(l, r) << endl;
        }
    }
    return 0;
}