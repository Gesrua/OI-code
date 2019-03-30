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

#define ls son[0]
#define rs son[1]

const int inf = 100000000;

const int N = 100000;

void kn();

void printrt();

struct Node {
    int val, num, siz;
    Node *fa, *son[2];
    void maintain() { siz = ls->siz + rs->siz + num; }
    void link(Node* x, int d) {
        son[d] = x;
        x->fa = this;
        kn();
    }
    int cmp(int x) { return x < val ? 0 : x == val ? -1 : 1; }
    int relation() { return fa->rs == this; }
    void rotate();
    void splay(Node* target) {
        target = target->fa;
        while (this->fa != target) {
            if (fa->fa == target)
                rotate();
            else if (relation() == fa->relation())
                fa->rotate(), rotate();
            else
                rotate(), rotate();
        }
    }
    void print();
} T[N * 4], *null, *rt;

void Node::rotate() {
    int d = relation();
    Node* old = fa;

    fa->fa->link(this, fa->relation());
    old->link(son[d ^ 1], d);
    this->link(old, d ^ 1);

    if (this->fa == null) rt = this;

    old->maintain();
    this->maintain();
}

void Node::print() {
    if (this == null) return;
    ls->print();
    cerr << val << ' ';
    rs->print();
}

void print(Node* cur) {
    cerr << "----\n";
    cur->print();
    cerr << "\n****\n";
}

void printrt() { print(rt); }

int cnt = 1;

void ins(int x) {
    if (rt == null) {
        rt = &T[cnt++];
        *rt = (Node){x, 1, 1, null, null, null};
        return;
    }
    Node* cur = rt;
    while (1) {
        // cerr << "dbg " << cur->val << endl;
        cur->siz++;
        int d = cur->cmp(x);
        if (d == -1) {
            cur->num++;
            // print(rt);
            cur->splay(rt);
            return;
        }
        if (cur->son[d] == null) {
            T[cnt] = (Node){x, 0, 0, cur, null, null};
            cur->son[d] = &T[cnt++];
        }
        cur = cur->son[d];
    }
}

int pre(int x) {
    Node *cur = rt, *ans = null;
    int ret = -inf;
    while (cur != null) {
        // cerr << "dbg " << cur->val << endl;
        if (cur->val < x && cur->val > ret) {
            // cerr << "update" << cur->val << endl;
            ret = cur->val, ans = cur;
        }
        cur = cur->son[x <= cur->val ? 0 : 1];
    }
    // cerr << "pre before ret = " << ans->val << endl;
    ans->splay(rt);
    // cerr << "pre ret = " << ans->val << endl;
    return ans->val;
}

int suc(int x, Node* target = rt) {
    Node *cur = target, *ans = null;
    int ret = inf;
    while (cur != null) {
        // cerr << "dbg " << cur->val << endl;
        if (cur->val > x && cur->val < ret) ret = cur->val, ans = cur;
        cur = cur->son[x >= cur->val ? 1 : 0];
    }
    // cerr << "ans = " << ret << endl;
    ans->splay(target);
    // cerr << "suc over" << endl;
    // printrt();
    return ans->val;
}

int kth(int k) {
    Node* cur = rt;
    while (cur != null) {
        if (k <= cur->ls->siz)
            cur = cur->ls;
        else if (cur->ls->siz + cur->num < k)
            k -= cur->ls->siz + cur->num, cur = cur->rs;
        else {
            cur->splay(rt);
            return cur->val;
        }
    }
    return 0;
}

int rank(int x) {
    Node* cur = rt;
    pre(x);
    return rt->ls->siz + rt->num + 1;
}

void del(int x) {
    Node* cur = rt;
    pre(x);
    suc(x, rt->rs);
    // cerr << "new root " << rt->val << endl;
    cur = rt;
    cur->siz--;
    cur = cur->rs;
    while (1) {
        cur->siz--;
        // cerr << cur->val << endl;
        if (cur->ls == null) {
            if (cur->num == 1)
                cur->fa->son[cur->relation()] = null;
            else
                cur->num--;
            return;
        }
        cur = cur->ls;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n;
    cin >> n;
    null = T;
    kn();
    rt = null;
    ins(-inf + 1);
    ins(inf - 1);
    while (n--) {
        int opt, x;
        cin >> opt >> x;
        switch (opt) {
            case 1:
                ins(x);
                break;
            case 2:
                del(x);
                break;
            case 3:
                cout << rank(x) - 1 << '\n';
                break;
            case 4:
                cout << kth(x + 1) << '\n';
                break;
            case 5:
                cout << pre(x) << '\n';
                break;
            case 6:
                cout << suc(x) << '\n';
                break;
        }
        // printrt();
    }
    return 0;
}

void kn() {
    null->fa = null->ls = null->rs = null;
    null->siz = null->val = null->num = 0;
}