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

int _x[200100];
std::map<int, int> H;

int low(int x) { return x & -x; }
struct B {
    int siz;
    int c[200100];
    void add(int pos, int x) {
        for (int i = pos; i <= siz; i += low(i)) c[i] += x;
    };
    int s(int pos) {
        int ret = 0;
        for (int i = pos; i > 0; i -= low(i)) ret += c[i];
        return ret;
    }
    int q(int l, int r) { return l > r ? 0 : s(r) - s(l - 1); }
} s1, s2;
struct P {
    int x, y;
    bool operator<(const P& rhs) const {
        return (y == rhs.y ? x < rhs.x : y < rhs.y);
    }
} a[200100];

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n;
    cin >> n;
    rep(i, 1, n) {
        // cin >> x[i];
        cin >> a[i].x >> a[i].y;
        _x[i] = a[i].x;
    }
    std::sort(_x + 1, _x + 1 + n);
    s1.siz = s2.siz = std::unique(_x + 1, _x + 1 + n) - (_x + 1);
    rep(i, 1, s1.siz) H[_x[i]] = i, s2.add(i, 1);
    rep(i, 1, n) a[i].x = H[a[i].x], s1.add(a[i].x, 1);
    std::sort(a + 1, a + 1 + n);
    int y = -1, l = 0, s = s1.siz, start = 1;
    ll ans = 0;
    rep(i, 1, n) {
        if (y != a[i].y) {
            rep(j, start, i - 1) {
                s1.add(a[j].x, -1);
                if (s1.q(a[j].x, a[j].x) == 0) s2.add(a[j].x, -1);
            }
            start = i;
            y = a[i].y;
            l = 1;
        }
        ans += (ll)s2.q(l, a[i].x) * s2.q(a[i].x, s);
        l = a[i].x + 1;
    }
    cout << ans;
    return 0;
}
