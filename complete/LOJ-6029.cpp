#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;
using std::make_pair; using std::pair; typedef pair<int, int> pii; typedef pair<int, ll> pil;

const int N = 100010;

inline int fdiv(int x, int y){
    if (x >= 0) return x/y;
    else return (x-y+1)/y;
}

struct Node{
    int l, r, max, min, tag; ll sum;
    Node *lc, *rc;
    void add(int x){
        max += x, min += x, tag += x, sum += (r-l+1)*x;
    }
    void pushdown(){
        if (tag != 0){
            lc->add(tag); rc->add(tag); tag = 0;
        }
    }
    void maintain(){
        max = std::max(lc->max, rc->max);
        min = std::min(lc->min, rc->min);
        sum = lc->sum + rc->sum;
    }
    void add(int l, int r, int x){
        if (l <= this->l && this->r <= r){
            add(x); return;
        }
        pushdown();
        if (l <= lc->r) lc->add(l, r, x);
        if (rc->l <= r) rc->add(l, r, x);
        maintain();
    }
    void div(int l, int r, int x){
        if (l <= this->l && this->r <= r && max - fdiv(max, x) == min - fdiv(min, x)){
            add(fdiv(max, x) - max); return;
        }
        // if (max - fdiv(max, x) == min - fdiv(min, x)){
        //     add(l, r, fdiv(max, x) - max);
        //     return;
        // }
        pushdown();
        if (l <= lc->r) lc->div(l, r, x);
        if (rc->l <= r) rc->div(l, r, x);
        maintain();
    }
    ll qsum(int l, int r){
        if (l <= this->l && this->r <= r) return sum;

        ll ret = 0;
        pushdown();
        if (l <= lc->r) ret += lc->qsum(l, r);
        if (rc->l <= r) ret += rc->qsum(l, r);
        return ret;
    }
    int qmin(int l, int r){
        if (l <= this->l && this->r <= r) return min;

        int ret = 1e9;
        pushdown();
        if (l <= lc->r) ret = std::min(ret, lc->qmin(l, r));
        if (rc->l <= r) ret = std::min(ret, rc->qmin(l, r));
        return ret;
    }
    void show(){
        if (l == r){
            cerr << max << ' '; return;
        }
        pushdown();
        lc->show();
        rc->show();
    }
} T[N*4]; int c = 0;
Node* build(int l, int r){
    Node* ret = &T[c++];
    ret->l = l, ret->r = r;
    if (l != r){
        int mid = (l+r)/2;
        ret->lc = build(l, mid);
        ret->rc = build(mid+1, r);
        ret->maintain();
    } else {
        cin >> ret->min;
        ret->max = ret->sum = ret->min;
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int n, q; cin >> n >> q;
    Node* tree = build(0, n-1);
    while(q--){
        int opt;
        cin >> opt;
        if (opt == 1){
            int l, r, c; cin >> l >> r >> c;
            tree->add(l, r, c);
        } else if (opt == 2){
            int l, r, d; cin >> l >> r >> d;
            tree->div(l, r, d);
        } else if (opt == 3){
            int l, r; cin >> l >> r;
            cout << tree->qmin(l, r) << '\n';
        } else {
            int l, r; cin >> l >> r;
            cout << tree->qsum(l, r) << '\n';
        }
    }
    return 0;
}
