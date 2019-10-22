#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;
const int N = 50100;
int color[N];
struct Ques{
    int l, r, id;
    ll ans;
}q[N];
bool cmp_l(const Ques& a, const Ques& b){ return a.l < b.l; }
bool cmp_r(const Ques& a, const Ques& b){ return a.r < b.r; }
bool cmp_id(const Ques& a, const Ques& b){ return a.id < b.id; }
int cnt[N];
ll gcd(ll x, ll y){
    return x?gcd(y%x, x):y;
}
inline ll calc(ll x){ return x*(x-1); }
int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false); cout.tie(0);
    int n, m;
    cin >> n >> m;
    rep(i, 1, n) cin >> color[i];
    rep(i, 1, m){ cin >> q[i].l >> q[i].r; q[i].id = i; }
    std::sort(q+1,q+1+m,cmp_l);
    int lst =0, l = sqrt(n);
    rep(i, 1, m){
        std::memset(cnt,0,sizeof(cnt));
        lst += l;
        int j = i-1;
        for(; q[j+1].l <= lst && j < m; ++j) ;
        std::sort(q+i, q+j+1, cmp_r);
        int left = q[i].l, right = q[i].l;
        ll ans = 0;
        cnt[color[q[i].l]]++;
        // rep(k, i, j) cerr << q[k].l << ' ' << q[k].r << endl;
        // cerr << "------" << endl;
        rep(k, i, j){
            rep(x, right+1, q[k].r){
                // ans += 2*cnt[color[x]];
                ans -= calc(cnt[color[x]]);
                cnt[color[x]]++;
                ans += calc(cnt[color[x]]);
            } right = q[k].r;
            if (q[k].l < left){
                rep(x, q[k].l, left-1){
                    // ans += 2*cnt[color[x]];
                    ans -= calc(cnt[color[x]]);
                    cnt[color[x]]++;
                    ans += calc(cnt[color[x]]);
                } left = q[k].l;
            } else if (left < q[k].l){
                rep(x, left, q[k].l-1){
                    // ans -= cnt[color[x]]-2;
                    ans -= calc(cnt[color[x]]);
                    cnt[color[x]]--;
                    ans += calc(cnt[color[x]]);
                } left = q[k].l;
            }
            q[k].ans = ans;
        }
        i = j;
    }
    std::sort(q+1,q+1+m,cmp_id);
    rep(i, 1, m){
        if (q[i].l == q[i].r){
            cout << "0/1\n";
        } else {
            ll siz = calc(q[i].r-q[i].l+1), g=gcd(siz,q[i].ans);
            cout << q[i].ans/g << '/' << siz/g << '\n';
        }
    }
    return 0;
}