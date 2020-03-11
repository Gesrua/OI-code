#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
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
using std::sqrt;
struct node {
    int x, y;
    long double dis(node& b) {
        return sqrt((long double)(x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
    }
} a, b, c, d, req;
long double s(node& a, node& b, node& c) {
    long double l1 = a.dis(b), l2 = a.dis(c), l3 = b.dis(c);
    long double p = (l1 + l2 + l3) / 2;
    p = p * (p - l1) * (p - l2) * (p - l3);
    p = p >= 0 ? p : -p;
    return sqrt(p);
}
int main() {
    std::ios::sync_with_stdio(false);
    int n, dd;
    cin >> n >> dd;
    a.x = dd, a.y = 0, b.x = 0, b.y = dd, c.x = n, c.y = n - dd, d.x = n - dd,
    d.y = n;
    // cerr << a.dis(c);
    int m;
    long double goal = s(a, b, c) * 2;
    // cerr << "goal = " << goal << endl;
    cin >> m;
    while (m--) {
        cin >> req.x >> req.y;
        long double sum =
            s(a, b, req) + s(b, d, req) + s(c, d, req) + s(a, c, req);
        cerr << "sum = " << sum << endl;
        if (((sum - goal > 0) ? (sum - goal) : (goal - sum)) < 1e-4) {
            cout << "YES\n";
        } else
            cout << "NO\n";
    }
    return 0;
}
