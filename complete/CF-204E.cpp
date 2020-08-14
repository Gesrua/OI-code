#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl; using std::make_pair; using std::pair;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull; typedef pair<int, int> pii;

const int N = 1e6+10;

char tmp[N];
int s[N];
int sa[N], rk[N*2], oldrk[N*2], k, tot;

bool cmp(int x, int y, int w) {
    return oldrk[x] == oldrk[y] && oldrk[x + w] == oldrk[y + w];
}

void GetSA(int* s, int n){
    rep(i, 1, n) sa[i] = i, rk[i] = s[i];
    for(int w = 1; w < n; w <<= 1){
        std::sort(sa+1, sa+1+n, [&](int x, int y){
            return rk[x] != rk[y] ?
                rk[x] < rk[y] :
                rk[x+w] < rk[y+w];
        });
        std::memcpy(oldrk, rk, sizeof(rk));
        for(int p = 0, i = 1; i <= n; ++i){
            rk[sa[i]] = cmp(sa[i], sa[i-1], w) ? p : ++p;
        }
    }
}

int height[N], belong[N];

void GetHeight(int* s, int n){
    int k = 0;
    rep(i, 1, n){
        if (rk[i] == 1) k = 0;
        else {
            if (k > 0) k--;
            int j = sa[rk[i]-1];
            while(i+k <= n && j+k <= n && s[i+k] == s[j+k]) ++k;
        }
        height[rk[i]] = k;
    }
}

int a[N], order[N];

std::map<int, int> buk[N];
int fa[N];

int getf(int x){ return x == fa[x] ? x : (fa[x] = getf(fa[x])); }

ll ans[N];

void upd(int x, int r){
    for(auto i : buk[x]){
        // cerr << i.first << " += " << i.second*r << endl;
        ans[i.first] += 1ll*i.second * r;
    }
}

void merge(int x, int y, int r){
    x = getf(x); y = getf(y);
    if (x == y) return;
    if (buk[x].size() >= k && buk[y].size() >= k) ;
    else if (buk[x].size() < k && buk[y].size() < k){
        if (buk[x].size() < buk[y].size()) std::swap(x, y);

        for(auto i : buk[y]) buk[x][i.first] += i.second;

        if (buk[x].size() >= k) upd(x, r);
    } else {
        if (buk[x].size() < k) std::swap(x, y);
        upd(y, r);
    }
    fa[y] = x;
}

void print(int i){
    for(; i <= tot; ++i){
        // cerr << s[i] << ' ';
        if (s[i] <= 25) cerr << char(s[i]+'a');
        else cout << '#';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n; cin >> n >> k;
    rep(i, 1, n){
        cin >> tmp;
        for(int j = 0; tmp[j]; ++j){
            s[++tot] = tmp[j]-'a';
        }
        s[++tot] = i+25;
        a[i] = tot;
    }

    GetSA(s, tot);
    GetHeight(s, tot);

    std::iota(order+1, order+1+tot, 1);
    rep(i, 1, tot){
        belong[i] = std::lower_bound(a+1, a+1+n, i) - a;
        fa[i] = i;
        buk[i][belong[i]] = 1;
        if (buk[i].size() >= k) upd(i, a[belong[i]]-i);
    }

    std::sort(order+2, order+1+tot, [&](int x, int y){
        return height[x] > height[y];
    });
    rep(i, 2, tot){
        if (height[order[i]] == 0) break;
        // print(sa[order[i]-1]); cerr << ' '; print(sa[order[i]]); cerr << endl;
        merge(sa[order[i]-1], sa[order[i]], height[order[i]]);
    }
    rep(i, 1, n) cout << ans[i] << ' ';
    return 0;
}