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
using std::min;
using std::pair;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int ui;

const int N = 133674, inf = 1e9;

struct Ret {
    int x1, x2, y1, y2;
    bool empty;
    Ret() {}
    Ret(int _x1, int _y1, int _x2, int _y2)
        : x1(_x1), x2(_x2), y1(_y1), y2(_y2), empty(false) {}
    bool upd() {
        empty = (x1 > x2 || y1 > y2);
        return empty;
    }
    bool merge(const Ret& b) {
        x1 = max(x1, b.x1), y1 = max(y1, b.y1);
        x2 = min(x2, b.x2), y2 = min(y2, b.y2);
        return upd();
    }
} a[N], pre[N], suc[N], t;

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n;
    cin >> n;
    pre[0] = suc[n + 1] = Ret(-inf, -inf, inf, inf);
    rep(i, 1, n) {
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
        pre[i] = suc[i] = a[i];
        pre[i].merge(pre[i - 1]);
        // cout << pre[i].x1 << ' ' << pre[i].y1 << ' ' << pre[i].x2 << ' '
        //      << pre[i].y2 << endl;
    }
    per(i, n, 1) suc[i].merge(suc[i + 1]);
    rep(i, 1, n) {
        if (!pre[i - 1].merge(suc[i + 1])) {
            cout << pre[i - 1].x1 << ' ' << pre[i - 1].y1 << endl;
            return 0;
        }
    }
    return 0;
}