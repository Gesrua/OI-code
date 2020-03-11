#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;
using std::make_pair; using std::pair; typedef pair<int, int> pii; typedef pair<int, ll> pil;

typedef double real;

real inline c(real& k, real& b, int x){ return k*x + b; }

struct Node{
    real k, b;
    Node *lc, *rc;
    int l, r;
    inline real get(int x){ return c(this->k, this->b, x); }
    void insert(int l, int r, real k, real b){
        // assert(r >= this->l); assert(l <= this->r);
        int mid = (this->l+this->r)/2;
        if (l <= this->l && this->r <= r){
            if (get(l) >= c(k, b, l) && get(r) >= c(k, b, r)) return;
            // if (l == r && l == 1) cerr << c(k, b, 1) << endl;
            if (get(l) < c(k, b, l) && get(r) < c(k, b, r)){
                this->k = k, this->b = b;
                return;
            }
            real o = get(mid), n = c(k, b, mid);
            if (o <= n) {
                if (this->l == this->r) ;
                else if (k > this->k) lc->insert(l, r, this->k, this->b);
                else rc->insert(l, r, this->k, this->b);
                this->k = k, this->b = b;
            } else {
                if (this->l == this->r) return;
                if (k > this->k) rc->insert(l, r, k, b);
                else lc->insert(l, r, k, b);
            }
            return;
        }
        // cerr << l << ' ' << r << ' ' << this->l << ' ' << this->r << endl;
        // assert(this->l != this->r);
        if (l <= mid) lc->insert(l, r, k, b);
        if (mid < r) rc->insert(l, r, k, b);
    }
    real query(int x){
        real ret = get(x);
        // cerr << x << ' ' << l << ' ' << r << ' ' << get(x) << endl;
        if (l != r){
            if (x <= lc->r) ret = std::max(ret, lc->query(x));
            else ret = std::max(ret, rc->query(x));
        }
        return ret;
    }
} T[100000*4];

Node* tree;

int xa, ya, xb, yb;
void insert(){
    real k, b;
    if (xa == xb){
        k = 0;
        b = std::max(ya, yb);
    } else {
        k = ((real)ya-yb)/(xa-xb);
        b = (real)ya - k * xa;
    }
    if (std::min(xa, xb) > 100000 || std::max(xa, xb) < 1) return;
    tree->insert(std::max(std::min(xa, xb), 1), std::min(std::max(xa, xb), 100000), k, b);
}

int cnt = 0;
Node* build(int l, int r){
    Node* ret = &T[cnt++];
    ret->l = l, ret->r = r; ret->k = 0; ret->b = -1e13;
    if (l != r){
        int mid = (l+r)/2;
        ret->lc = build(l, mid);
        ret->rc = build(mid+1, r);
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C2.in", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int n, m; cin >> n >> m;
    tree = build(1, 100000);
    cerr << "built" << endl;
    rep(i, 1, n){
        cin >> xa >> ya >> xb >> yb;
        insert();
    }
    cerr << "in" << endl;
    cout.setf(std::ios::fixed);
    while(m--){
        int op; cin >> op;
        if (op == 0){
            cin >> xa >> ya >> xb >> yb;
            insert();
        } else {
            int x;
            cin >> x;
            real res = tree->query(x);
            if (res < -1e12) cout << "0\n";
            else cout << std::setprecision(3) << res << '\n';
        }
    }
    return 0;
}
