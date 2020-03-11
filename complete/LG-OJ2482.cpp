#include <bits/stdc++.h>
// #define dbg(x) cerr << x << endl;
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;
const int N = 20100;
struct Star{
    ll x, y1, y2, p;
    bool operator<(const Star& rhs) const { return x<rhs.x; }
} a[N*2];
struct Seg{
    struct Node{
        ll l, r, max, tag;
    } T[N*20];
    #define ls (c<<1)
    #define rs ((c<<1)|1)
    #define tag(x) T[x].tag
    #define val(x) T[x].max
    #define mid ((l+r)>>1)
    #define s T[c]
    void build(int c, int l, int r){
        s.l = l, s.r = r, s.max = s.tag = 0;
        if (l == r){ return; }
        build(ls, l, mid), build(rs, mid+1, r);
    }
    void pushdown(int c){
        tag(ls) += s.tag, val(ls) += s.tag;
        tag(rs) += s.tag, val(rs) += s.tag;
        s.tag = 0;
        return;
    }
    void update(int c){ s.max = std::max(val(ls), val(rs)); }
    int L, R, X;
    void _e(int c){
        if (L <= s.l && s.r <= R){
            // cerr << "before " << T[c].max << " after " << s.max + X << endl;
            s.tag += X, s.max += X;
            // cerr << c << ' ' << s.l << ' ' << s.r << ' ' << s.max << endl;
            return;
        }
        if (R < s.l || s.r < L) return;
        pushdown(c);
        _e(ls), _e(rs);
        update(c);
        // cerr << c << ' ' << s.l << ' ' << s.r << ' ' << s.max << endl;
    }
    void edit(int l, int r, ll x){
        // cerr << l << ' ' << r << ' ' << x << endl;
        L = l, R = r, X = x;
        _e(1);
    }
    ll query(){ return T[1].max; }
    void print(int c){
        // cerr << c << ' ' << s.l << ' ' << s.r << ' ' << s.max << endl;
        // if (s.l == s.r) return;
        // print(ls), print(rs);
    }
} seg;
std::map<ll, int> dec;
ll ry[N];

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false); cout.tie(0);
    int n, w, h;
    while(cin >> n >> w >> h){
        int tot = 0;
        rep(i, 1, n){
            int x, y; ll l;
            cin >> x >> y >> l;
            a[i].x = x,  a[i].p = l;
            a[i+n].x = x+w-1, a[i+n].p = -l;
            ry[tot++] = a[i].y1 = a[i+n].y1 = y,
            ry[tot++] = a[i].y2 = a[i+n].y2 = y+h-1;
        }
        std::sort(ry, ry+tot), tot = std::unique(ry,ry+tot)-ry;
        for(int i = 0; i < tot; ++i) dec[ry[i]] = i;
        std::sort(a+1, a+n+n+1);
        ll ans = 0;
        seg.build(1, 0, n);
        rep(i, 1, 2*n){
            ans = std::max(ans, seg.query());
            // seg.print(1); cerr << "------" << endl;
            // cerr << dec[a[i].y1] << ' ' << dec[a[i].y2] << ' ' << a[i].p << endl;
            seg.edit(dec[a[i].y1], dec[a[i].y2], a[i].p);
        }
        cout << ans << endl;
    }
    return 0;
}