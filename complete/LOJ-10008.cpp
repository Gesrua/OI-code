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

const int T = 7.5 * 1e5;

struct BIT {
    ui c[T], n = 7 * 1e5;
    int lowbit(int x) { return x & -x; }
    void add(int pos, ui x) {
        for (int i = pos; i <= n; i += lowbit(i)) c[i] += x;
    }
    ui sum(int n) {
        ui ret = 0;
        for (int i = n; i > 0; i -= lowbit(i)) ret += c[i];
        return ret;
    }
    ui query(int l, int r) { return sum(r) - sum(l - 1); }
} st;

struct Node {
    int s, d;
    bool operator<(const Node& b) const {
        return (s == b.s ? d > b.d : s > b.s);
    }
} a[1000010];

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, ans = 0;
    cin >> n;
    rep(i, 1, n) cin >> a[i].d >> a[i].s, st.add(i, 1);
    std::sort(a + 1, a + 1 + n);
    rep(i, 1, n) {
        int l = 1, r = a[i].d;
        if (st.sum(r) == 0)
            continue;
        else {
            ans += a[i].s;
            while (l <= r) {
                if (l == r) {
                    st.add(l, -1);
                    // cerr << l << endl;
                    break;
                }
                int mid = (l + r) / 2;
                if (st.query(mid + 1, r) > 0)
                    l = mid + 1;
                else
                    r = mid;
            }
        }
    }
    cout << ans << endl;
    return 0;
}