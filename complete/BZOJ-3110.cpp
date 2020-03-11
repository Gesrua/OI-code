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
typedef unsigned int ui;

const int N = 50009, M = 50009;

int n, m;

struct node {
    int opt, l, r, v, ans, id, c;
} a[M];

inline bool cmp_id(const node& a, const node& b) { return a.id < b.id; }

inline bool cmp_c(const node& a, const node& b) { return a.c < b.c; }

struct BIT {
    ui c[N];
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
} seg;

void solve(int l, int r, int x, int y) {
    if (l > r || x > y) return;
    if (l == r) {
        rep(i, x, y) a[i].ans = l;
        return;
    }
    int mid = l + r + 1 >> 1, p = 0, q = y;
    rep(i, x, y) {
        if (a[i].opt == 1) {  // add
            if (a[i].v >= mid) {
                a[i].c = ++q;
                seg.add(a[i].l, a[i].r, 1);
            } else
                a[i].c = ++p;
        } else {  // ask
            // L = a[i].l;
            // R = a[i].r;
            // ui t = ask(1, 1, n);
            ui t = seg.ask(a[i].l, a[i].r);
            if (t >= (ui)a[i].v) {
                a[i].c = ++q;
            } else {
                a[i].c = ++p;
                a[i].v -= t;
            }
        }
    }
    rep(i, x, y) if (a[i].opt == 1 && a[i].v >= mid)  // add
        seg.add(a[i].l, a[i].r, -1);
    std::sort(a + x, a + y + 1, cmp_c);
    solve(l, mid - 1, x, x + p - 1);
    solve(mid, r, x + p, y);
}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);

    cin >> n >> m;
    rep(i, 1, m) {
        cin >> a[i].opt >> a[i].l >> a[i].r >> a[i].v;
        a[i].id = i;
    }

    solve(-n, n, 1, m);

    std::sort(a + 1, a + 1 + m, cmp_id);
    rep(i, 1, m) {
        if (a[i].opt == 2) {
            cout << a[i].ans << endl;
        }
    }
    return 0;
}
/*
   struct n2 {
    int lazy, clr, s;
   } t[N*4];

   int L, R;

   void pushdown(int x, int l, int r){
    if (l == r){
        t[x].clr = 0;
        return;
    }
    n2& cur = t[x];
    int mid = l+r>>1, lson = x*2, rson = x*2+1;
    if (cur.clr) {
        t[lson].clr = 1;
        t[lson].lazy = 0;
        t[lson].s = 0;
        t[rson].clr = 1;
        t[rson].lazy = 0;
        t[rson].s = 0;
        cur.clr = 0;
    }
    t[lson].lazy += cur.lazy;
    t[lson].s += (mid-l+1)*cur.lazy;
    t[rson].lazy += cur.lazy;
    t[rson].s += (r-mid)*cur.lazy;
    cur.lazy = 0;
   }

   void add(int x, int l, int r){
    if (r < L || R < l) return;
    n2& cur = t[x];
    int lson = x*2, rson = x*2+1;
    pushdown(x, l, r);
    if (L <= l && r <= R) {
        // cerr << l << ' ' << r << " lazy tag plus" << endl;
        cur.lazy++;
        cur.s += (r-l+1);
        // cerr << x << ' ' << l << ' ' << r << ' ' << cur.s << endl;
        return;
    }
    int mid = l+r>>1;
    add(lson, l, mid);
    add(rson, mid+1, r);
    cur.s = t[lson].s + t[rson].s;
    // cerr << x << ' ' << l << ' ' << r << ' ' << cur.s << endl;
   }

   int ask(int x, int l, int r){
    if (r < L || R < l) return 0;
    n2& cur = t[x];
    int lson = x*2, rson = x*2+1;
    pushdown(x, l, r);
    if (L <= l && r <= R) return cur.s;
    int mid = l+r>>1;
    return ask(lson, l, mid) + ask(rson, mid+1, r);
   }

   void solve(int l, int r, int x, int y){
    // cerr << l << ' ' << r << ' ' << x << ' ' <<  y << endl;
    // rep(i, x, y){
    //     cerr << a[i].id << ' ' << a[i].opt << ' ' << a[i].l << ' ' << a[i].r
   << ' ' << a[i].v << endl;
    // }
    // cerr << "-----" << endl;
    if (l > r || x > y) return;
    if (l == r) {
        rep (i, x, y) a[i].ans = l;
        return;
    }
    int mid = l+r+1>>1, p = 0, q = y;
    t[1].clr = 1;
    t[1].s = 0;
    t[1].lazy = 0;
    rep (i, x, y){
        if (a[i].opt == 1) {       // add
            if (a[i].v >= mid) {
                a[i].c = ++q;
                L = a[i].l;
                R = a[i].r;
                add(1, 1, n);
            }
            else a[i].c = ++p;
        }
        else{ // ask
            L = a[i].l;
            R = a[i].r;
            ui t = ask(1, 1, n);
            if (t >= (ui)a[i].v) {
                a[i].c = ++q;
            }else{
                a[i].c = ++p;
                a[i].v -= t;
            }

        }

    }
    std::sort(a+x, a+y+1, cmp_c);
    solve(l, mid-1, x, x+p-1);
    solve(mid, r, x+p, y);
   }
 */
