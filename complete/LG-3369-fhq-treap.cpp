#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;

namespace FHQ_Treap {
template <typename Type, int N>
struct FHQ_Treap {
    inline int rnd() {
        static int seed = 703;
        return seed = int(seed * 48271LL % 2147483647);
    }
    struct Node {
        Type key;
        int siz, pri;
        Node *ls, *rs;
        inline void upd() { siz = (ls ? ls->siz : 0) + (rs ? rs->siz : 0) + 1; }
        inline int rank() { return (ls ? ls->siz : 0) + 1; }
    } T[N], *rt = nullptr;
    typedef std::pair<Node *, Node *> pnn;
    inline Node *gen(Type x) {
        static int cnt = 0;
        T[cnt].key = x, T[cnt].ls = T[cnt].rs = nullptr, T[cnt].siz = 1, T[cnt].pri = rnd();
        return &T[cnt++];
    }
    // first < key, second >= key
    pnn split(Node *u, Type key) {
        if (u == nullptr) return {nullptr, nullptr};
        if (u->key < key) {
            pnn o = split(u->rs, key);
            u->rs = o.first; u->upd();
            return {u, o.second};
        } else {
            pnn o = split(u->ls, key);
            u->ls = o.second; u->upd();
            return {o.first, u};
        }
    }
    Node *merge(Node *u, Node *v) {
        if (u == nullptr) return v;
        if (v == nullptr) return u;
        if (u->pri > v->pri) {
            u->rs = merge(u->rs, v); u->upd();
            return u;
        } else {
            v->ls = merge(u, v->ls); v->upd();
            return v;
        }
    }
    inline Type kth(Node *u, int k) {
        while (u->rank() != k)
            if (u->rank() < k) k -= u->rank(), u = u->rs;
            else u = u->ls;
        return u->key;
    }
    void print(Node *u) {
        if (u == nullptr) return;
        print(u->ls);
        cerr << u->key << ' ';
        print(u->rs);
    }

    inline Type kth(int k){
        return kth(rt, k);
    }
    inline void insert(Type x) {
        pnn o = split(rt, x);
        rt = merge(merge(o.first, gen(x)), o.second);
    }
    inline int rank_of_x(Type x){
        pnn o = split(rt, x);
        int ret = (o.first ? o.first->siz : 0) + 1;
        merge(o.first, o.second);
        return ret;
    }

    // first element < x
    inline int prev(Type x){
        pnn o = split(rt, x);
        int ret = kth(o.first, o.first->siz);
        merge(o.first, o.second);
        return ret;
    }

    // need +1 support
    inline void del(Type x){
        pnn o = split(rt, x+1);
        pnn t = split(o.first, x);
        t.second = merge(t.second->ls, t.second->rs);
        rt = merge(merge(t.first, t.second), o.second);
    }
    inline int succ(Type x){
        pnn o = split(rt, x+1);
        int ret = kth(o.second, 1);
        merge(o.first, o.second);
        return ret;
    }
};
};  // namespace FHQ_Treap

FHQ_Treap::FHQ_Treap<int, 150010> s;

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        int opt, x;
        cin >> opt >> x;
        switch (opt) {
            case 1:
                s.insert(x);
                break;
            case 2:
                s.del(x);
                break;
            case 3:
                cout << s.rank_of_x(x) << endl;
                break;
            case 4:
                cout << s.kth(x) << endl;
                break;
            case 5:
                cout << s.prev(x) << endl;
                break;
            case 6:
                cout << s.succ(x) << endl;
                break;
        }
    }
    return 0;
}
