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

const int N = 20000;

struct node {
    int lmax, rmax, sum, l, r;
    node *ls, *rs;
} t[(N + N) * 22];

int cnt = 0;

node* root[N + 100];

inline node* newnode() { return &t[cnt++]; }

void pushup(node* cur) {
    cur->sum = cur->ls->sum + cur->rs->sum;
    cur->lmax = std::max(cur->ls->lmax, cur->ls->sum + cur->rs->lmax);
    cur->rmax = std::max(cur->rs->rmax, cur->ls->rmax + cur->rs->sum);
}

void build(node* cur, int l, int r) {
    cur->l = l, cur->r = r;
    if (l == r) {
        cur->lmax = cur->rmax = cur->sum = 1;
        return;
    }
    cur->ls = newnode(), cur->rs = newnode();
    int mid = l + r >> 1;
    build(cur->ls, l, mid);
    build(cur->rs, mid + 1, r);
    pushup(cur);
}

int num;

node* insert(node* cur) {
    if (num < cur->l || cur->r < num) return cur;
    node* ret = newnode();
    ret->l = cur->l, ret->r = cur->r;
    if (cur->l == cur->r) {
        ret->lmax = ret->rmax = ret->sum = -1;
        return ret;
    }
    ret->ls = insert(cur->ls), ret->rs = insert(cur->rs);
    pushup(ret);
    return ret;
}

int qsum(node* cur, int l, int r) {
    // cerr << "qsum " << cur->l << ' ' << cur->r << endl;
    if (r < cur->l || cur->r < l) return 0;
    // cerr << "qsum " << cur->l << ' ' << cur->r << endl;
    if (l <= cur->l && cur->r <= r) return cur->sum;
    return qsum(cur->ls, l, r) + qsum(cur->rs, l, r);
}

int qlmax(node* cur, int l, int r) {
    if (l <= cur->l && cur->r <= r) return cur->lmax;  // TODO why?
    int mid = cur->l + cur->r >> 1;
    if (r <= mid) return qlmax(cur->ls, l, r);
    if (mid + 1 <= l) return qlmax(cur->rs, l, r);
    return std::max(qlmax(cur->ls, l, mid), qsum(cur->ls, l, mid) + qlmax(cur->rs, mid + 1, r));
}

int qrmax(node* cur, int l, int r) {
    if (l <= cur->l && cur->r <= r) return cur->rmax;  // TODO why?
    int mid = cur->l + cur->r >> 1;
    if (r <= mid) return qrmax(cur->ls, l, r);
    if (mid + 1 <= l) return qrmax(cur->rs, l, r);
    return std::max(qrmax(cur->rs, mid + 1, r), qsum(cur->rs, mid + 1, r) + qrmax(cur->ls, l, mid));
}

void out(int x) { cerr << x << ' '; }
void out(int x, int y) { out(x), out(y); }
void out(int x, int y, int z) { out(x, y), out(z); }
void out(int a, int b, int c, int d) { out(a, b, c), out(d); }
void out(int a, int b, int c, int d, int e) { out(a, b, c, d), out(e); }
void out(int a, int b, int c, int d, int e, int f) { out(a, b, c, d, e), out(f); }

pii a[N + 100];
pii* dbg = a;

void print(node* cur) {
    out(cur->l, cur->r, cur->lmax, cur->rmax, cur->sum);
    cerr << endl;
    if (cur->l != cur->r) print(cur->ls), print(cur->rs);
}

inline bool check(int num, int a, int b, int c, int d) {
    // print(root[num]);
    // out(a, b, c, d);
    // out(dbg[num].first, qrmax(root[num], a, b), (b+1<=c-1?qsum(root[num],
    // b+1, c-1):0) , qlmax(root[num], c, d)); cerr << endl;
    int sum = (b + 1 <= c - 1 ? qsum(root[num], b + 1, c - 1) : 0) + qrmax(root[num], a, b) + qlmax(root[num], c, d);
    // cerr << "result " <<  (sum>=0) << endl;
    return sum >= 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n;
    cin >> n;
    rep(i, 1, n) {
        cin >> a[i].first;
        a[i].second = i;
    }
    std::sort(a + 1, a + 1 + n);
    root[1] = newnode();
    build(root[1], 1, n);
    rep(i, 2, n + 1) {
        num = a[i - 1].second;
        root[i] = insert(root[i - 1]);
    }
    // rep(i, 1, n+1){
    //     print(root[i]);
    //     cerr << "------" << endl;
    // }
    int q[4];
    int Q;
    cin >> Q;
    int x = 0;
    while (Q--) {
        cin >> q[0] >> q[1] >> q[2] >> q[3];
        q[0] = (q[0] + x) % n + 1, q[1] = (q[1] + x) % n + 1, q[2] = (q[2] + x) % n + 1, q[3] = (q[3] + x) % n + 1;
        std::sort(q, q + 4);
        int l = 1, r = n, ans;
        // out(q[0], q[1], q[2], q[3]); cerr << endl;
        while (l <= r) {
            int mid = l + r >> 1;
            if (check(mid, q[0], q[1], q[2], q[3]))
                ans = mid, l = mid + 1;
            else
                r = mid - 1;
        }
        // cerr << endl;
        cout << a[ans].first << endl;
        x = a[ans].first;
        // cerr << "--------" << endl;
    }
    return 0;
}