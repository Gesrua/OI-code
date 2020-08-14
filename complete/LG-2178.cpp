#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl; using std::make_pair; using std::pair;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull; typedef pair<int, int> pii; 

const int N = 301000;

int n;
char s[N]; ll a[N];
int sa[N], rk[N*2], oldrk[N*2], height[N];

void GetSA(){
    rep(i, 1, n) sa[i] = i, rk[i] = s[i];
    for(int w = 1; w < n; w <<= 1){
        std::sort(sa+1, sa+1+n, [&](int x, int y){
            return rk[x] != rk[y] ?
                rk[x] < rk[y]:
                rk[x+w] < rk[y+w];
        });
        std::memcpy(oldrk, rk, sizeof(sa));
        int p = 0;
        rep(i, 1, n){
            if (oldrk[sa[i]] == oldrk[sa[i-1]] && oldrk[sa[i]+w] == oldrk[sa[i-1]+w])
                rk[sa[i]] = p;
            else
                rk[sa[i]] = ++p;
        }
    }
}

void GetHeight(){
    int k = 0;
    rep(i, 1, n){
        if (rk[i] == 1) k = 0;
        else {
            if (k > 0) --k;
            int j = sa[rk[i]-1];
            while(i+k <= n && j+k <= n && s[i+k] == s[j+k]) ++k;
        }
        height[rk[i]] = k;
    }
}

int order[N]; ll mx[N], mn[N], ans1[N], ans2[N], siz[N];
int fa[N];

int getf(int x){ return x == fa[x] ? x : (fa[x] = getf(fa[x])); }

void merge(int x, int y, int r){
    x = getf(x);
    y = getf(y);
    if (x == y) return;
    ans1[r] += siz[x] * siz[y];
    ans2[r] = std::max(ans2[r], mx[x] * mx[y]);
    ans2[r] = std::max(ans2[r], mn[x] * mn[y]);

    siz[x] += siz[y];
    mn[x] = std::min(mn[x], mn[y]);
    mx[x] = std::max(mx[x], mx[y]);
    fa[y] = x;
}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n;
    cin >> (s+1);
    rep(i, 1, n){
        cin >> a[i];
        mn[i] = mx[i] = a[i]; fa[i] = i;
        siz[i] = 1;
    }
    rep(i, 0, n) ans2[i] = -1e18;
    GetSA();
    GetHeight();
    rep(i, 1, n) order[i] = i;
    std::sort(order+2, order+n+1, [&](int x, int y){
        return height[x] > height[y];
    });
    rep(i, 2, n){
        merge(sa[order[i]], sa[order[i]-1], height[order[i]]);
    }
    per(i, n-2, 0){
        ans1[i] += ans1[i+1];
        ans2[i] = std::max(ans2[i], ans2[i+1]);
    }
    rep(i, 0, n-1){
        if (ans1[i] == 0) cout << "0 0\n";
        else cout << ans1[i] << ' ' << ans2[i] << '\n';
    }
    return 0;
}