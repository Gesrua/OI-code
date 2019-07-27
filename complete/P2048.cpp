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

const int FIX = 1e9 + 1;

struct Node {
    int t;
    Node *ls, *rs;
    int rk() { return ls == nullptr ? 0 : ls->t; }
} T[50000000];
int cnt = 0;

int X, pre[500010], L, R;
Node* rt[500010];

inline void upd(Node* c) {
    c->t =
        (c->ls == nullptr ? 0 : c->ls->t) + (c->rs == nullptr ? 0 : c->rs->t);
}

Node* insert(Node* c, int l, int r) {
    // cerr << l << ' ' << r << endl;
    Node* n = &T[cnt++];
    if (l == r) {
        // cerr << l << endl;
        n->t = (c == nullptr ? 1 : (1 + c->t));
        return n;
    }
    int mid = l + (r - l) / 2;
    if (X <= mid) {
        if (c == nullptr)
            n->ls = insert(nullptr, l, mid);
        else {
            n->ls = insert(c->ls, l, mid);
            n->rs = c->rs;
        }
    } else {
        if (c == nullptr)
            n->rs = insert(nullptr, mid + 1, r);
        else {
            n->ls = c->ls;
            n->rs = insert(c->rs, mid + 1, r);
        }
    }
    upd(n);
    return n;
}

void print(Node* c, int l, int r) {
    if (c == nullptr) return;
    cerr << l - FIX << ' ' << r - FIX << ' ' << c->t << endl;
    int mid = l + (r - l) / 2;
    print(c->ls, l, mid);
    print(c->rs, mid + 1, r);
}

int q(Node* x, Node* y, int l, int r, int k) {
    // cerr << l << ' ' << r << ' ' << y->t << endl;
    if (l == r) return l - FIX;
    int tot = y->rk() - (x == nullptr ? 0 : x->rk());
    int mid = l + (r - l) / 2;

    if (k <= tot) {
        return q(x == nullptr ? x : x->ls, y->ls, l, mid, k);
    } else {
        return q(x == nullptr ? x : x->rs, y->rs, mid + 1, r, k - tot);
    }
}

struct C {
    int k, o, t;
    C() { o = k = t = 0; }
    C(int _o, int _k) {
        o = _o, k = _k;
        if (o - R <= 0) {
            t = pre[o] - q(nullptr, rt[o - L], 1, FIX * 2, _k);
        } else {
            t = pre[o] - q(rt[o - R - 1], rt[o - L], 1, FIX * 2, _k);
        }
        // if (o == L)
        //     t = pre[o];
        // else {
        //     // cerr << "q " << std::max(o - R, 0) + 1 << ' ' << o - L <<
        //     endl; t = pre[o] -
        //         q(rt[std::max(o - R - 1, 0)], rt[o - L], 1, FIX * 2, _k);
        // }
        // cerr << "C " << o << ' ' << k << ' ' << t << endl;
    }
    bool operator<(const C& y) const { return t < y.t; }
};

std::priority_queue<C> h;

int main() {
#ifdef LOCAL
    freopen("/tmp/2006/2006/1.in", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, k;
    cin >> n >> k >> L >> R;
    int t = 0;
    X = FIX;
    rt[0] = insert(nullptr, 1, FIX * 2);
    rep(i, 1, n) {
        cin >> t;
        pre[i] = pre[i - 1] + t;
        X += t;
        rt[i] = insert(rt[i - 1], 1, FIX * 2);
    }
    rep(i, L, n) {
        // cerr << i << endl;
        h.push(C(i, 1));
    }
    // cerr << "push over" << endl;
    ll ans = 0;
    C x;
    while (k--) {
        x = h.top();
        h.pop();
        ans += x.t;
        // cerr << "ADD " << x.t << endl;
        // cerr << x.k << ' ' << x.o << endl;
        if (x.k < std::min(R - L + 1, x.o - L + 1)) {
            // cerr << "push " << x.o << ' ' << x.k + 1 << endl;
            h.push(C(x.o, x.k + 1));
        }
    }
    cout << ans;
    return 0;
}