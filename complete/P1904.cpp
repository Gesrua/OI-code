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

struct Q {
    int p, h;
    bool operator<(const Q& y) const { return p < y.p; }
} a[10010], lst;

std::multiset<int> s;

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n = 0;
    int l, h, r;
    while (cin >> l >> h >> r) {
        a[n++] = {l, h};
        a[n++] = {r, -h};
    }
    std::sort(a, a + n);
    // cerr << "n " << n << endl;
    // for (int i = 0; i < n; ++i) cerr << a[i].p << ' ' << a[i].h << endl;
    s.insert(0);
    for (int i = -1; i + 1 < n;) {
        // cerr << i << endl;
        do {
            ++i;
            // cerr << "i " << i << endl;
            if (a[i].h > 0)
                s.insert(a[i].h);
            else {
                // cerr << "count " << s.count(-a[i].h) << endl;
                s.erase(-a[i].h);
            }
            // cerr << "insert over " << i << ' ';
            // for (auto x : s) cerr << x << ' ';
            // cerr << endl;
        } while (a[i].p == a[i + 1].p);
        if (*(--s.end()) != lst.h) {
            lst.h = *(--s.end());
            cout << a[i].p << ' ' << lst.h << ' ';
        }
    }
    return 0;
}