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

struct Node {
    int l, r;
    ll s, m;
    Node *ls, *rs;
} T[400000];
int cnt = 0;

inline void upd(Node* c) {
    c->s = c->ls->s + c->rs->s;
    c->m = std::max(c->ls->m, c->rs->m);
}

void build(Node*& c, int l, int r) {
    if (c == NULL) c = &T[cnt++];
    c->l = l, c->r = r;
    if (l == r) {
        cin >> c->m;
        c->s = c->m;
        return;
    }
    int mid = (l + r) / 2;
    build(c->ls, l, mid);
    build(c->rs, mid + 1, r);
    upd(c);
}

int L, R;

ll qs(Node* c) {
    if (c->r < L || R < c->l) return 0;
    if (L <= c->l && c->r <= R) return c->s;
    return qs(c->ls) + qs(c->rs);
}

void edit(Node* c) {
    if (c->r < L || R < c->l || c->m <= 1) return;
    if (c->l == c->r) {
        c->m = std::sqrt(c->m);
        c->s = std::sqrt(c->s);
        return;
    }
    edit(c->ls), edit(c->rs);
    upd(c);
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, m;
    cin >> n;
    Node* rt = NULL;
    build(rt, 1, n);
    // cerr << "built" << endl;
    cin >> m;
    while (m--) {
        int x;
        cin >> x >> L >> R;
        if (L > R) std::swap(L, R);
        if (x == 1)
            cout << qs(rt) << endl;
        else
            edit(rt);
    }
    return 0;
}