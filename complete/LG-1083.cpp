#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;

const int N = 1e6+10;

struct Node{
    int l, r;
    ll mi, tag;
} T[N*4];

#define s T[c]
#define ls (c<<1)
#define rs ((c<<1)|1)
inline void update(int c){ T[c].mi = std::min(T[ls].mi, T[rs].mi); }
void build(int c, int l, int r){
    s.l = l, s.r = r;
    if (l == r){
        cin >> s.mi;
        return;
    }
    int mid = (l+r)/2;
    build(ls, l, mid), build(rs, mid+1, r);
    update(c);
}
inline void pushdown(int c){
    T[ls].tag += s.tag; T[rs].tag += s.tag;
    T[ls].mi += s.tag; T[rs].mi += s.tag;
    s.tag = 0;
}
int L, R, P; ll X;
const ll inf = 1e9+10;
ll _query(int c){
    if (s.r < L || R < s.l) return inf;
    if (L <= s.l && s.r <= R) return s.mi;
    pushdown(c);
    return std::min(_query(ls), _query(rs));
}
ll query(int l, int r){
    L = l, R = r;
    return _query(1);
}
void _edit(int c){
    if (s.r < L || R < s.l) return;
    if (L <= s.l && s.r <= R){
        s.tag += X;
        s.mi += X;
        return;
    }
    pushdown(c);
    _edit(ls); _edit(rs);
    update(c);
}
void edit(int l, int r, ll x){
    L = l, R = r, X = x;
    _edit(1);
}
void print(int c){
    cerr << s.l << ' ' << s.r << ' ' << s.mi << ' ' << s.tag << endl;
    if (s.l != s.r) print(ls), print(rs);
}
#undef s

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    build(1, 1, n);
    rep(i, 1, m){
        ll d;
        int s, t;
        cin >> d >> s >> t;
        if (query(s, t) < d){
            cout << "-1\n" << i;
            return 0;
        }
        edit(s, t, -d);

        // print(1);
        // rep(i, 1, n){
        //     cerr << query(i, i) << ' ';
        // } cerr << endl;
    }
    cout << 0;
    return 0;
}
