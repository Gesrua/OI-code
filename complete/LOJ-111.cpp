#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl; using std::make_pair; using std::pair;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull; typedef pair<int, int> pii;

const int N = 1e6+10;

char s[N];
int sa[N], rk[N*2], buk[N], fir[N], sec[N], oldrk[N*2];

bool cmp(int x, int y, int w) {
    return oldrk[x] == oldrk[y] && oldrk[x + w] == oldrk[y + w];
}

void GetSA(char* s, int n){
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

int height[N];

void GetHeight(char* s, int n){
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

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> (s+1);
    int n = strlen(s+1);
    GetSA(s, n);
    GetHeight(s, n);
    rep(i, 1, n) cout << sa[i] << ' ';
    // rep(i, 1, n){
    //     cout << height[i] << ' ' << s+sa[i] << endl;
    // }
    return 0;
}