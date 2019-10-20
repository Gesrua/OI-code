#define NDEBUG
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <iomanip>
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

std::map<double, int> ord;

const int N = 220;

double x[N], y[N], ans, raw[N];

struct P {
    double x, y1, y2;
    int p = 0;
    bool operator<(const P& rhs) const { return x < rhs.x; }
} p[N];

struct Node {
    int l, r, t; double sum;
}T[N*16];
#define s T[c]
#define ls (c<<1)
#define rs ((c<<1)|1)
void build(int c, int l, int r){
    s.l = l, s.r = r, s.t = 0;
    if (l == r) return;
    int mid = (l+r)>>1;
    build(ls, l, mid), build(rs, mid+1, r);
}
void edit(int c, int l, int r, int p){
    assert(l<=r); assert(p == 1 || p == -1);
    if (r < s.l || s.r < l) return;
    if (l <= s.l && s.r <= r) {
        s.t += p;
        s.sum = s.t ? raw[s.r] - raw[s.l-1] : (s.l == s.r ? 0 : T[ls].sum + T[rs].sum);
        return; 
    }
    edit(ls, l, r, p), edit(rs, l, r, p);
    s.sum = s.t ? raw[s.r] - raw[s.l-1] : (s.l == s.r ? 0 : T[ls].sum + T[rs].sum);
}
void print(int c){
    cerr << s.l << ' ' << s.r << ' ' << s.sum << ' ' << s.t << endl;
    if (s.l == s.r) return;
    print(ls), print(rs);
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int n, num = 0;
    cout.setf(std::ios::fixed);
    while(cin >> n && n != 0){
        ++num, ans = 0; int tot = 0;
        double x1, x2, y1, y2;
        rep(i, 1, n) {
            cin >> x1 >> y1 >> x2 >> y2;
            p[i].p = 1, p[i].x = x1,
            p[i+n].p = -1, p[i+n].x = x2,
            raw[tot++] = p[i].y1 = p[i+n].y1 = y1,
            raw[tot++] = p[i].y2 = p[i+n].y2 = y2;
        }
        std::sort(p+1, p+1+n+n);
        std::sort(raw, raw+tot), tot = std::unique(raw, raw+tot) - raw;
        build(1, 0, tot);
        ord.clear();
        for(int i = 0; i < tot; ++i) ord[raw[i]] = i;
        rep(i, 1, 2*n){
            // cerr << p[i].x - p[i-1].x << ' ' << T[1].sum << endl;
            ans += (p[i].x - p[i-1].x) * T[1].sum;
            // cerr << "edit " << ord[p[i].y1] << ' ' << ord[p[i].y2] << ' ' << p[i].p << endl;
            assert(ord.count(p[i].y1) & ord.count(p[i].y2));
            edit(1, ord[p[i].y1]+1, ord[p[i].y2], p[i].p);
            // print(1);
        }
        cout << "Test case #" << std::setprecision(2) << num << endl << "Total explored area: " << ans << endl << endl;
    }
    return 0;
}