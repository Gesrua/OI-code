#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;
const int N = 500010, M = 500010, V = 1000003, inf = 1e9, ninf = -2139062144;
int ans[M];
struct Action{
    int query; // 0->edit 1->query
    int x, y;
    int id;
} a[N+M], b[N+M];
bool cmp_x(const Action& x, const Action& y){ return x.x < y.x; }
int c[V+10];
#define ckmx(x, y) (x)=((x>y)?(x):(y))
// inline int lowbit(int x){ return x&(-x); }
#define lowbit(x) (x&(-x))
// void upd(int i, int x){ for(; i <= V; i += lowbit(i)) ckmx(c[i], x); }
void upd(int i, int x){ for(; i <= V && c[i]<x; i += lowbit(i)) c[i] = x; }
void clear(int i){ for(; i <= V; i+=lowbit(i)) c[i] = ninf; }
int query(int i){
    int ret = ninf;
    for(; i > 0; i-=lowbit(i)) ckmx(ret, c[i]);
    return ret;
}
int n, m, nm;
void solve(int l, int r){
    if (l == r) return;
    int mid = (l+r)/2;
    if (l == 1 && r == nm) mid = n;
    if (r == n){
        std::sort(a+1, a+1+n, cmp_x);
        return;
    }
    solve(l, mid); solve(mid+1, r);
    int i = l;
    rep(j, mid+1, r){
        if (a[j].query){
            for(; i <= mid && a[i].x <= a[j].x; ++i)
                if (!a[i].query) upd(a[i].y, a[i].x+a[i].y);
            ans[a[j].id] = std::min(ans[a[j].id], a[j].x+a[j].y-query(a[j].y));
        }
    }
    rep(x, l, i) if (!a[x].query) clear(a[x].y);
    std::inplace_merge(a+l, a+mid+1, a+r+1, cmp_x);
}
int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::memset(c, 0x80, sizeof(c)); std::memset(ans, 0x3f, sizeof(ans));
    std::ios::sync_with_stdio(0); cout.tie(0);
    cin >> n >> m; nm = n+m; int tot = 0;
    rep(i, 1, n) cin >> a[i].x >> a[i].y; 
    for(int i = n+1; i <= nm; ++i){
        cin >> a[i].query >> a[i].x >> a[i].y;
        if (--a[i].query) a[i].id = ++tot;
    }
    rep(i, 1, nm) a[i].x++, a[i].y++;
    memcpy(b, a, sizeof(a));

    // x, y
    solve(1, nm);
    // rep(i, 1, tot) cout << ans[i] << endl;
    // cerr << ans[1] << endl;
    // assert(ans[10]>=45506);

    // x, rev(y)
    rep(i, 1, nm) b[i].y = V - b[i].y;
    memcpy(a, b, sizeof(a));
    solve(1, nm);
    // rep(i, 1, tot) cout << ans[i] << endl;

    // rev(x), rev(y)
    rep(i, 1, nm) b[i].x = V - b[i].x;
    memcpy(a, b, sizeof(a));
    solve(1, nm);
    // rep(i, 1, tot) cout << ans[i] << endl;

    // rev(x), y
    rep(i, 1, nm) b[i].y = V - b[i].y;
    memcpy(a, b, sizeof(a));
    solve(1, nm);

    rep(i, 1, tot) cout << ans[i] << endl;
    return 0;
}