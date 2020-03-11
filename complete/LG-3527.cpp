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
typedef long long ll;

const int N = 300100, M = 300100, K = 300100;

int n, m, k, sum[M + 9];

std::vector<int> pos[M + 9];

struct n1 {
    int l, r, w;
} star[K];

struct n2 {
    int id, tar, ans;
} c[M + 9], t1[M], t2[M];

struct BIT {
    ll c[N];
    int lowbit(int x) { return x & -x; }
    void add(int pos, ll x) {
        for (int i = pos; i <= n; i += lowbit(i)) c[i] += x;
    }
    ll sum(int n) {
        ll ret = 0;
        for (int i = n; i > 0; i -= lowbit(i)) ret += c[i];
        return ret;
    }
    ll query(int l, int r) { return sum(r) - sum(l); }
};

struct EXBIT {
    BIT t, s;
    void init(int pos, int add) {
        s.add(pos, add);
        t.add(pos, (pos - 1) * add);
    }
    void add(int l, int r, ll x) {
        s.add(l, x);
        s.add(r + 1, -x);
        t.add(l, (l - 1) * x);
        t.add(r + 1, -r * x);
    }
    ll _ask(int r) {
        if (r <= 0) return 0;
        return r * s.sum(r) - t.sum(r);
    }
    ll ask(int l, int r) { return _ask(r) - _ask(l - 1); }
} seg;

bool chk(int x) {
    int id = c[x].id, goal = c[x].tar;
    ll sum = 0;
    // cerr << "checking " << id << ' ' << goal << ' ';

    for (std::vector<int>::iterator i = pos[id].begin(); i != pos[id].end(); ++i) {
        sum += seg.ask(*i, *i);
        if (sum >= goal) { /*cerr << "pass" << endl;*/
            return 1;
        }
    }
    // cerr << "fail" << endl;
    c[x].tar -= sum;
    return 0;
}

void solve(int l, int r, int x, int y) {
    int mid = l + r >> 1;
    // cerr << l << ' ' << mid << ' ' << r << ' ' << x << ' ' << y << endl;
    if (l == r) {
        rep(i, x, y) c[i].ans = l;
        return;
    }
    if (l > r || x > y) return;
    rep(i, l, mid) {
        if (star[i].l <= star[i].r)
            seg.add(star[i].l, star[i].r, star[i].w);
        else
            seg.add(star[i].l, n, star[i].w), seg.add(1, star[i].r, star[i].w);
    }
    int cnt1 = 0, cnt2 = 0;
    rep(i, x, y) {
        if (chk(i))
            t1[cnt1++] = c[i];
        else
            t2[cnt2++] = c[i];
    }
    // cerr << "cnt1 = " <<cnt1 << " cnt2 = " <<cnt2 << endl;
    for (int i = 0; i < cnt1; ++i) c[x + i] = t1[i];
    int t = x + cnt1;
    for (int i = 0; i < cnt2; ++i) c[t + i] = t2[i];
    rep(i, l, mid) {
        if (star[i].l <= star[i].r)
            seg.add(star[i].l, star[i].r, -star[i].w);
        else
            seg.add(star[i].l, n, -star[i].w), seg.add(1, star[i].r, -star[i].w);
    }
    solve(l, mid, x, t - 1);
    solve(mid + 1, r, t, y);
}

bool cmp_id(const n2& a, const n2& b) { return a.id < b.id; }

// int t;
// int read(){int
// x=0;while(t=getchar(),!isdigit(t));while(x=(x<<1)+(x<<3)+t-48,t=getchar(),isdigit(t));
// return x;}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    // m = read(); n = read();
    cin >> m >> n;
    int t;
    // rep(i, 1, n) pos[read()].push_back(i);

    rep(i, 1, n) cin >> t, pos[t].push_back(i);
    rep(i, 1, m) {
        cin >> c[i].tar;
        c[i].id = i, c[i].ans = 0;
    }
    cin >> k;
    rep(i, 1, k) cin >> star[i].l >> star[i].r >> star[i].w;
    ++k;
    star[k].l = 1, star[k].r = n, star[k].w = 1000000000;
    solve(1, k, 1, m);
    std::sort(c + 1, c + 1 + m, cmp_id);
    rep(i, 1, m) {
        if (c[i].ans == 0 || c[i].ans == k)
            cout << "NIE" << endl;
        else
            cout << c[i].ans << endl;
        // cout << (c[i].ans==0) ? ("NIE") : (c[i].ans) << endl;
    }
    return 0;
}