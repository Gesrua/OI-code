#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl; using std::make_pair; using std::pair;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull; typedef pair<int, int> pii; 

const int N = 100010, p = 998244353, i2 = 499122177;

int inv2[N], pow2[N];

inline int add(int x, int y){ x += y; return x>=p ? x-p : x; }
inline int sub(int x, int y){ x -= y; return x>=0 ? x : x+p;}
inline int mul(int x, int y){ return int((ll)x*y%p); }

struct Node {
    int g, sf, f, tg;
} T[N*4];

#define s T[idx]
#define lc (idx*2)
#define rc (idx*2+1)
#define sl T[idx*2]
#define sr T[idx*2+1]
int L, R;
void pushdown(int idx){
    if (s.tg > 0){
        sl.tg += s.tg, sl.g = add(mul(sl.g, inv2[s.tg]), sub(1, inv2[s.tg]));
        sr.tg += s.tg, sr.g = add(mul(sr.g, inv2[s.tg]), sub(1, inv2[s.tg]));
        s.tg = 0;
    }
}
void pushup(int idx){ s.sf = add(add(s.f, sl.sf), sr.sf); }

int c = 0;
void modify(int idx, int l, int r){
    if (L <= l && r <= R){
        // 3
        s.g = mul(1+s.g, i2);
        s.sf = sub(s.sf, s.f);
        s.f = mul(1+s.f, i2);
        s.sf = add(s.sf, s.f);
        s.tg++; // 4
        return;
    }
    if (r < L || R < l){
        // 2
        s.sf = sub(s.sf, s.f);
        s.f = mul(add(s.g, s.f), i2);
        s.sf = add(s.sf, s.f);
        return;
    }
    // 1
    pushdown(idx);
    s.g = mul(s.g, i2);
    s.f = mul(s.f, i2);
    int mid = (l + r)/2;
    modify(lc, l, mid); modify(rc, mid+1, r);
    pushup(idx);
}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    inv2[0] = 1, inv2[1] = 499122177; rep(i, 2, 100000) inv2[i] = mul(inv2[i-1], inv2[1]);
    pow2[0] = 1; rep(i, 1, 100000) pow2[i] = add(pow2[i-1], pow2[i-1]);

    int n, m; cin >> n >> m;
    while(m--){
        int opt; cin >> opt;
        if (opt == 1){
            cin >> L >> R; c++;
            modify(1, 1, n);
        } else {
            cout << sub( mul(T[1].sf, pow2[c]), 0 ) << '\n';
        }
    }
    return 0;
}