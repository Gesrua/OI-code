#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl; using std::make_pair; using std::pair;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull; typedef pair<int, int> pii;

const int rqy = 998244353, N = 1e5+10;

int n;

struct Mat{
    int x, y;
    Mat(){}
    Mat(int _x, int _y){ x = _x, y = _y; }
    Mat operator*(const Mat& b){
        return Mat( ( (ll)x*b.x%rqy + (ll)y*b.y%rqy )%rqy, ( (ll)x*b.y%rqy + (ll)y*b.x%rqy )%rqy);
    }
};

struct Node{
    Mat d;
    Node *ls, *rs;
} T[N*276]; int tot = 1;

Node* nn(){
    T[tot].d = Mat(1, 0);
    return &T[tot++];
}

struct Segy{
    Node* rt;
    void modify(Node* &u, const int l, const int r, const int L, const int R, const Mat& x){
        if (r < L || R < l || L > R) return;
        if (!u) u = nn();
        if (L <= l && r <= R){ u->d = u->d * x; return; }
        int mid = (l+r)/2;
        modify(u->ls, l, mid, L, R, x);
        modify(u->rs, mid+1, r, L, R , x);
    }
    Mat query(Node* u, const int l, const int r, const int x){
        if (!u) return Mat(1, 0);
        int mid = (l+r) / 2;
        if (x <= mid) return u->d * query(u->ls, l, mid, x);
        else return u->d * query(u->rs, mid+1, r, x);
    }
};

struct xnode{
    int l, r;
    Segy d;
    xnode *ls, *rs;
} T2[N*17]; int t2 = 1;

xnode* xn(int l, int r){ T2[t2].l = l, T2[t2].r = r; return &T2[t2++]; }

struct Segx{
    xnode* rt;
    void modify(xnode* &u, int l, int r, const int L, const int R, const pii& ry, const Mat& x){
        if (r < L || R < l || L > R) return;
        if (!u) u = xn(l, r);
        if (L <= l && r <= R){ u->d.modify(u->d.rt, 0, n, ry.first, ry.second, x); return; }
        int mid = (l+r)/2;
        modify(u->ls, l, mid, L, R, ry, x);
        modify(u->rs, mid+1, r, L, R , ry, x);
    }
    Mat query(xnode* & u, int x, int y){
        if (!u) return Mat(1, 0);
        int mid = (u->l + u->r) / 2;
        if (x <= mid) return u->d.query(u->d.rt, 0, n, y) * query(u->ls, x, y);
        else return u->d.query(u->d.rt, 0, n, y) * query(u->rs, x, y);
    }
} seg;

int inv(ll a){
    ll ret = 1; int n = rqy-2;
    while(n){
        if (n&1) (ret *= a) %= rqy;
        (a*=a) %= rqy;
        n >>= 1;
    }
    return ret;
}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int m; cin >> n >> m;
    while(m--){
        int opt, l, r;
        cin >> opt >> l >> r;
        if (opt == 1){
            int is = inv(r-l+1);
            seg.modify(seg.rt, 1, n, 1, l-1, {l, r}, Mat(1-is, is));
            seg.modify(seg.rt, 1, n, l, r, {l, r}, Mat((1-2*is)%rqy, 2*is%rqy));
            seg.modify(seg.rt, 1, n, l, r, {r+1, n}, Mat(1-is, is));

            seg.modify(seg.rt, 1, n, l, r, {0, 0}, Mat(is, 1-is));
            seg.modify(seg.rt, 1, n, 1, l-1, {0, 0}, Mat(0, 1));
            seg.modify(seg.rt, 1, n, r+1, n, {0, 0}, Mat(0, 1));
        } else {
            if (l == 1)
                cout << (seg.query(seg.rt, r, 0).x+rqy)%rqy << '\n';
            else
                cout << (seg.query(seg.rt, l-1, r).x+rqy)%rqy << '\n';
        }
    }
    return 0;
}