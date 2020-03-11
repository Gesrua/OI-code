#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;
const int N = 40010, T = 1000;
int a[N], de[N], L[N], R[N], pos[N], f[T][T], cnt[N];
std::map<int, int> dec;
std::vector<int> c[N];

int query(int l, int r, int x){
    return std::upper_bound(c[x].begin(), c[x].end(), r) - std::lower_bound(c[x].begin(), c[x].end(), l);
}

int ask(int l, int r){
    int p = pos[l], q = pos[r], cnt = 0, ans = 0;
    // cerr << l << ' ' << r << ' ' << R[p] << ' ' << L[q] << endl;
    if (p == q){
        rep(i, l, r){
            int t = query(l, r, a[i]);
            if (t > cnt || (t == cnt && a[i] < ans)) ans = a[i], cnt = t;
        }
        return ans;
    }
    ans = f[p+1][q-1], cnt = query(l, r, f[p+1][q-1]);
    // cerr << de[ans] << ' ' << cnt << endl;
    rep(i, l, R[p]){
        int t = query(l, r, a[i]);
        // cerr << de[a[i]] << ' ' << t<<endl;
        if (t > cnt || (t == cnt && a[i] < ans)) ans = a[i], cnt = t;
    }
    rep(i, L[q], r){
        int t = query(l, r, a[i]);
        // cerr << de[a[i]] << ' ' << t<<endl;
        if (t > cnt || (t == cnt && a[i] < ans)) ans = a[i], cnt = t;
    }
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false); cout.tie(0);
    int n, q, tot = n;
    cin >> n >> q;
    rep(i, 1, n) {cin >> a[i]; de[i] = a[i];}
    std::sort(de+1, de+1+n);
    tot = std::unique(de+1, de+1+n) - de - 1;
    rep(i, 1, tot) dec[de[i]] = i;
    rep(i, 1, n) c[a[i]=dec[a[i]]].push_back(i);
    int t = sqrt(n*log2(n)), l = n/t;
    rep(i, 1, t) L[i] = R[i-1] + 1, R[i] =R[i-1] + l;
    if (R[t] != n){ ++t; L[t] = L[t-1]+1, R[t] = n; }
    rep(i, 1, t) rep(j, L[i], R[i]) pos[j] = i;
    rep(i, 1, t){
        std::memset(cnt, 0, sizeof(cnt));
        int ans = 0;
        rep(j, L[i], n){
            cnt[a[j]]++;
            if (cnt[a[j]] > cnt[ans] || (cnt[a[j]] == cnt[ans] && a[j] < ans)) ans = a[j];
            f[i][pos[j]] = ans;
        }
    }
    // rep(i, 1, t){
    //     rep(j, i, t){
    //         cerr << L[i] << ' '<< R[j] <<' '<< f[i][j] << endl;
    //     }
    // }
    // cerr << t << ' ' << l << endl;
    // rep(i, 1, t) cerr << L[i] << ' ' << R[i] << endl;
    // rep(i, 1, n) cerr<<pos[i]<<' '; cerr<<endl;
    int x = 0;
    while(q--){
        int l, r;
        cin >> l >> r;
        l = (l+x-1)%n+1, r = (r+x-1)%n+1;
        if (l > r) std::swap(l, r);
        // cerr << l << ' ' << r << endl;
        cout << (x=de[ask(l, r)]) << endl;
    }
    return 0;
}