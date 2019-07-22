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

int cnt = 1;

struct Node {
    double l, r;
    bool operator<(const Node &rhs) const { return l < rhs.l; }
} a[100010];

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, l, w;
    while (cin >> n >> l >> w) {
        double _w = pow(double(w) / 2, 2);
        cnt = 0;
        rep(i, 1, n) {
            double p, r;
            cin >> p >> r;
            if (r * 2 <= w) continue;
            double t = std::sqrt(r * r - _w);
            a[++cnt].l = p - t, a[cnt].r = p + t;
        }
        if (cnt == 0) {
            cout << -1 << endl;
            continue;
        }
        std::sort(a + 1, a + 1 + cnt);
        double left = 0, right = -1;
        int ans = 0;
        rep(i, 1, cnt) {
            if (a[i].l > left) {
                if (right == -1) {
                    cout << -1 << endl;
                    break;
                } else {
                    left = right, right = -1, ans++, --i;
                    continue;
                }
            }
            right = std::max(right, a[i].r);
            if (right >= l) {
                cout << ans + 1 << endl;
                break;
            }
            if (i == cnt) cout << -1 << endl;
        }
    }
    return 0;
}