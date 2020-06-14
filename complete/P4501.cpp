#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl; using std::make_pair; using std::pair;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull; typedef pair<int, int> pii; 

const int N = 2e5 + 10;

ll w[N]; int n, m;
struct s1 { int a; ll l; int id; } a[N];
ll st1[19][N], st2[19][N], pre[N]; int STM;

bool cmp(const s1& a, const s1& b){ return a.a < b.a; }

// first >= x
int query(int l, int r, int x){
    while(l < r){
        int mid = (l+r)/2;
        if (a[mid].a < x) l = mid+1;
        else r = mid;
    }
    return a[l].a >= x ? l : r + 1;
}

// first <= x
int query2(int l, int r, int x){
    while(l < r){
        int mid = (l+r+1)/2;
        if (a[mid].a <= x) l = mid;
        else r = mid-1;
    }
    return a[l].a <= x ? l : l - 1;
}

ll st1_query(int l, int r){
    int k = std::log2(r-l+1);
    return std::min(st1[k][l], st1[k][r-(1<<k)+1]);
}

ll st2_query(int l, int r){
    int k = std::log2(r-l+1);
    return std::min(st2[k][l], st2[k][r-(1<<k)+1]);
}

bool L_check(int L, int i){
    int p = 1 + std::abs(L - a[i].a);
    ll q = a[i].l + std::abs(pre[L] - pre[a[i].a]);
    int j = query(1, i-1, 1+L-p); int k;
    if (1 <= j && j <= i-1 && a[j].a == 1+L-p && a[j].l + pre[L] - pre[a[j].a] == q){
        return false;
    }
    if (1 <= j && j <= i-1 && a[j].a < L){
        k = query2(1, i-1, L-1);
        assert(a[k].a < L); assert(j <= k);
        if (st1_query(j ,k) <= q - pre[L]) return false;
    }
    j = query(1, i, L); k = i-1;
    if (j <= k){
        if (st2_query(j, k) <= a[i].l + pre[a[i].a]) return false;
    }
    return true;
}

bool R_check(int R, int i, int n){
    int p = 1 + std::abs(R - a[i].a);
    ll q = a[i].l + std::abs(pre[R] - pre[a[i].a]);
    int j = query2(i+1, n, R+p-1); int k;
    if (i+1 <= j && j <= n && a[j].a == R+p-1 && a[j].l + pre[a[j].a] - pre[R] == q){
        --j;
    }
    if (i+1 <= j && j <= n && R < a[j].a){
        k = query(i+1, n, R+1);
        if (st2_query(k, j) <= q + pre[R]) return false;
    }
    j = i+1; k = query2(i, n, R);
    if (j <= k){
        if (a[i].l - pre[a[i].a] >= st1_query(j, k)) return false;
    }
    return true;
}

void solve(){
    int k; cin >> k;
    rep(i, 1, k){
        a[i].id = i;
        cin >> a[i].a >> a[i].l;
    }
    std::sort(a+1, a+1+k, cmp);
    STM = k;
    rep(i, 1, k) st1[0][i] = a[i].l - pre[a[i].a], st2[0][i] = a[i].l + pre[a[i].a];
    rep(j, 1, 18) rep(i, 1, k){
        st1[j][i] = std::min(st1[j-1][i], st1[j-1][std::min(i+(1<<(j-1)), STM)]);
        st2[j][i] = std::min(st2[j-1][i], st2[j-1][std::min(i+(1<<(j-1)), STM)]);
    }
    ll ans = 0;
    rep(i, 1, k){
    // rep(i, 2, 2){
        int L, R, l = 1, r = a[i].a; int p; ll q;
        while(l < r){
            int mid = (l+r)/2;
            if (L_check(mid, i)) r = mid;
            else l = mid+1;
        }
        L = l;
        l = a[i].a, r = n;
        while(l < r){
            int mid = (l+r+1)/2;
            if (R_check(mid, i, k)) l = mid;
            else r = mid-1;
        }
        R = l;
        // cerr << a[i].a << ' ' <<  L << ' ' << R << ' ' << R - L + 1 << endl;
        ans += (R-L+1);
    }
    cout << ans << endl;
}

int main() {
    // freopen("input", "r", stdin);
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n >> m;
    rep(i, 2, n){
        cin >> w[i];
        pre[i] = pre[i-1] + w[i];
    }
    while(m--) solve();
    return 0;
}