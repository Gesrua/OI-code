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
typedef unsigned long long ull;

const int N = 100010;
struct Node {
    ll sum, tag;
    int l, r;
    Node *ls, *rs;
    int dis() { return r - l + 1; }
    void pushdown() {
        ls->sum += ls->dis() * tag;
        ls->tag += tag;
        rs->sum += rs->dis() * tag;
        rs->tag += tag;
        tag = 0;
    }
    void maintain() { sum = ls->sum + rs->sum; }
} T[N * 4];
int cnt = 0;
void build(Node*& c, int l, int r) {
    c = &T[cnt++];
    c->l = l, c->r = r;
    if (l == r) return;
    int mid = (l + r) / 2;
    build(c->ls, l, mid), build(c->rs, mid + 1, r);
}
int L, R;
ll X;
void edit(Node*& c) {
    if (L <= c->l && c->r <= R) {
        c->tag += X, c->sum += c->dis() * X;
        return;
    }
    if (c->r < L || R < c->l) return;
    c->pushdown();
    edit(c->ls), edit(c->rs);
    c->maintain();
}
ll query(Node*& c) {
    if (L <= c->l && c->r <= R) return c->sum;
    if (c->r < L || R < c->l) return 0;
    c->pushdown();
    return query(c->ls) + query(c->rs);
}
void print(Node* c) {
    if (!c) return;
    cout << c->l << ' ' << c->r << ' ' << c->sum << endl;
    print(c->ls), print(c->rs);
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    Node* root;
    build(root, 1, n + 1);
    ll x, xx = 0;
    rep(i, 1, n) {
        cin >> x;
        L = R = i, X = x - xx, edit(root);
        xx = x;
    }
    while (m--) {
        int opt, l, r;
        ll k, d;
        cin >> opt;
        if (opt == 1) {
            cin >> l >> r >> k >> d;
            L = R = l, X = k, edit(root);
            if (l + 1 <= r) L = l + 1, R = r, X = d, edit(root);
            L = R = r + 1, X = -(k + (r - l) * d), edit(root);
        } else {
            cin >> r;
            L = 1, R = r;
            cout << query(root) << endl;
        }
    }
    return 0;
}