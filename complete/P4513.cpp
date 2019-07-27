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

const int inf = 500000000;

struct Node {
    int l, r;
    int el, er, m, s;
    Node *ls, *rs;
} T[2000000];
int cnt = 0;

void upd(Node* c) {
    c->m = std::max(c->ls->m, std::max(c->rs->m, c->ls->er + c->rs->el));
    c->el = std::max(c->ls->el, c->ls->s + c->rs->el);
    c->er = std::max(c->rs->er, c->ls->er + c->rs->s);
    c->s = c->ls->s + c->rs->s;
}

void build(Node*& c, int l, int r) {
    c = &T[cnt++];
    c->l = l, c->r = r;
    if (l == r) {
        cin >> c->m;
        c->s = c->el = c->er = c->m;
        return;
    }
    int mid = (l + r) / 2;
    build(c->ls, l, mid), build(c->rs, mid + 1, r);
    upd(c);
}

int P, S;
void e(Node* c) {
    if (c->l == c->r) {
        c->s = c->el = c->er = c->m = S;
        return;
    }
    if (P <= c->ls->r)
        e(c->ls);
    else
        e(c->rs);
    upd(c);
}

// first el
// second er
int ans = 0, L, R;
pii q(Node* c) {
    if (L <= c->l && c->r <= R) {
        ans = std::max(ans, c->m);
        return pii(c->el, c->er);
    }
    int mid = c->ls->r;
    if (R <= mid)
        return q(c->ls);
    else if (mid < L)
        return q(c->rs);
    else {
        pii x = q(c->ls), y = q(c->rs);
        ans = std::max(ans, x.second + y.first);
        return pii(std::max(x.first, c->ls->s + y.first),
                   std::max(y.second, c->rs->s + x.second));
    }
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    Node* rt = nullptr;
    build(rt, 1, n);
    while (m--) {
        int k;
        cin >> k;
        if (k == 1) {
            cin >> L >> R;
            if (L > R) std::swap(L, R);
            ans = -inf;
            q(rt);
            cout << ans << endl;
        } else {
            cin >> P >> S;
            e(rt);
        }
    }
    return 0;
}