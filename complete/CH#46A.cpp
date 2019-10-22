#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;
const int N = 250010;
struct Magnet{
    ui d;
    int p, m, r;
    bool operator<(const Magnet& rhs) const{
        return d < rhs.d;
    }
} a[N];
bool operator<(const int&a,const Magnet& b){ return a < b.d; }
bool cmp_m(const Magnet& a, const Magnet& b){ return a.m < b.m; }
int L[510], R[510], t, del[N];
ui mx[510];
int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false); cout.tie(0),cin.tie(0);
    ll x0, y0; int p, r, n;
    cin >> x0 >> y0 >> p >> r >> n;
    std::queue<pii> q; q.push({p, r});
    rep(i, 1, n){
        int x,y,m,p,r;cin>>x>>y>>a[i].m>>a[i].p>>a[i].r;
        a[i].d = ceil(sqrt((x0-x)*(x0-x)+(y0-y)*(y0-y)));
    }
    std::sort(a+1, a+1+n, cmp_m);
    int t = sqrt(n), cnt = 0;
    rep(i, 1, t) L[i] = R[i-1]+1, R[i] = R[i-1]+t;
    if (R[t] != n) ++t, L[t] = R[t-1]+1, R[t] = n;
    rep(i, 1, t) {
        mx[i] = a[R[i]].m;
        std::sort(a+L[i], a+R[i]+1);
    }
    int ans = 0;
    while(q.size()){
        p = q.front().first, r = q.front().second; q.pop();
        for(int i = 1; i <= t; ++i){
            if (mx[i] <= p){
                rep(j, L[i], R[i])
                    if (a[j].d <= r){
                        if (!del[j]) q.push({a[j].p, a[j].r}), ans++;
                        L[i] = j+1;
                    } else break;
            } else {
                rep(j, L[i], R[i])
                    if (a[j].m <= p && a[j].d <= r && !del[j]){
                        del[j] = 1,
                        q.push({a[j].p, a[j].r}), ans++;
                    }
                break;
            }
        }
    }
    cout << ans;
    return 0;
}