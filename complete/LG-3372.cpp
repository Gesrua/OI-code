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

const int N = 100000;

struct Node {
    ll sum, tag;
    int l, r;
    Node *ls, *rs;
    inline int len();
    void maintain();
    void pushdown();
    ll query();
    void add();
    Node *build(int, int);
    void print();
};
Node T[N * 4];
Node *null;
int cnt = 1, L, R, X;

int Node::len() { return r - l + 1; }
void Node::maintain() { sum = ls->sum + rs->sum; }
void Node::pushdown() {
    ls->tag += tag, rs->tag += tag;
    ls->sum += ls->len() * tag, rs->sum += rs->len() * tag;
    tag = 0;
    null->sum = null->tag = 0;
}
ll Node::query() {
    if (L <= l && r <= R) return sum;
    if (r < L || R < l) return 0;
    pushdown();
    return ls->query() + rs->query();
}
void Node::add() {
    if (r < L || R < l) return;
    if (L <= l && r <= R)
        tag += X, sum += len() * X;
    else
        pushdown(), ls->add(), rs->add(), maintain();
}
Node *Node::build(int l, int r) {
    // cerr << l << ' ' << r << endl;
    Node *ret = &T[cnt++];
    ret->l = l, ret->r = r, ret->ls = ret->rs = null;
    if (l == r)
        cin >> ret->sum;
    else {
        int mid = (l + r) / 2;
        ret->ls = build(l, mid), ret->rs = build(mid + 1, r);
        ret->maintain();
    }
    return ret;
}

void Node::print() {
    if (this == null) return;
    cerr << l << ' ' << r << ' ' << sum << ' ' << tag << endl;
    ls->print(), rs->print();
}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, m;
    null = T;
    null->ls = null->rs = null;
    cin >> n >> m;
    Node *rt = null->build(1, n);
    L = 1, R = n;
    while (m--) {
        int opt;
        cin >> opt >> L >> R;
        if (opt == 1) {
            cin >> X;
            rt->add();
        } else
            cout << rt->query() << '\n';
    }
    return 0;
}