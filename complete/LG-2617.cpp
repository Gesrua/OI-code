#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;
const int N = 100010, M = 100010, inf = 1e9+1;
struct Action{
    int p;
    int l, r, k, id;
} a[N+M+M], la[M+M], ra[M+M];
int seq[N], ans[M];
int c[N+10];
#define lowbit(x) (x&(-x))
void add(int i, int x){ for(; i <= N; i+=lowbit(i)) c[i] += x; }
int sum(int i){ int ret = 0; for(; i > 0; i-=lowbit(i)) ret += c[i]; return ret; }

void solve(int st, int ed, int lv, int rv){
    // cerr << "solve " << st << ' ' << ed << ' ' << lv << ' ' << rv << endl;
    // rep(i, st, ed){
    //     cerr << a[i].p << ' ' << a[i].l << ' ' << a[i].r << ' ' << a[i].k << endl;
    // }
    // cerr << "------" << endl;
    if (st > ed) return;
    if (lv == rv){
        rep(i, st, ed) if (a[i].p == 0) ans[a[i].id] = lv;
        return;
    }
    int mid = (lv+rv)>>1;
    int lp = 0, rp = 0;
    rep(i, st, ed){
        if (a[i].p == 0) { // query
            int x = sum(a[i].r) - sum(a[i].l-1);
            // cerr << "query " << x << endl;
            if (x < a[i].k) a[i].k -= x, ra[++rp] = a[i];
            else la[++lp] = a[i];
        } else {
            if (a[i].k <= mid){
                add(a[i].l, a[i].p);
                la[++lp] = a[i];
            } else {
                ra[++rp] = a[i];
            }
        }
    }
    rep(i, st, ed) if (a[i].p != 0 && a[i].k <= mid) add(a[i].l, -a[i].p);
    rep(i, 1, lp) {
        a[st+i-1] = la[i];
        // cerr << st+i-1 << ' ' << i << endl;
    }
    rep(i, 1, rp){
        a[st+lp+i-1] = ra[i];
        // cerr << st+lp+i-1 << ' ' << i << endl;
    }
    solve(st, st + lp - 1, lv, mid);
    solve(st+lp, ed, mid+1, rv);
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int n, m;
    cin >> n >> m; m += n;
    rep(i, 1, n){
        cin >> a[i].k;
        a[i].p = 1, a[i].l = i;
        seq[i] = a[i].k;
    }
    int t = n, q = 0;
    rep(i, n+1, m){
        char opt;
        cin >> opt;
        if (opt == 'Q'){
            ++t;
            a[t].p = 0, a[t].id = ++q;
            cin >> a[t].l >> a[t].r >> a[t].k;
        } else {
            ++t;
            a[t].p = -1; cin >> a[t].l; a[t].k = seq[a[t].l];
            ++t;
            a[t].p = 1; cin >> a[t].k; seq[a[t].l=a[t-1].l] = a[t].k;
        }
    }
    // rep(i, 1, t){
    //     cout << a[i].p << ' ' << a[i].l << ' ' << a[i].r << ' ' << a[i].k << endl;
    // }
    solve(1, t, 0, inf);
    rep(i, 1, q) cout << ans[i] << endl;
    return 0;
}
