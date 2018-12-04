#include <cstdio>
#include <iostream>
#include <utility>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#define rep(i, l, r) for (register int i = (l); i <= (r); ++i)
#define per(i, l, r) for (register int i = (l); i >= (r); --i)
using std::cin; using std::cout; using std::cerr; using std::endl;
using std::make_pair; using std::pair;
typedef pair< int, int > pii;
typedef long long ll;

const int N = 59, mod = 1000000007;

ll dp[N][N][N][N], orip[N];
ll *pw = orip+3;

void init(){
    pw[-1] = 1;
    pw[0] = 1;
    dp[0][0][0][0] = 1;
    rep(i, 1, 50) (pw[i] = pw[i-1]*2) %= mod;
}
int main(){
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    init();
    ll ans = 0;
    int n, p;
    int c[60];
    cin >> n >> p;
    rep(i, 1, n) cin >> c[i]; // dp[i][ob][eb][ow][ew]
    rep(i, 1, n) rep(ob, 0, i) rep(eb, 0, i - ob) rep(ow, 0, i - ob - eb){
        int ew = i - ob - eb - ow;
        ll& cur = dp[i][ob][eb][ow];
        cur = 0;
        if (c[i] != 1){ // black
            ll t = pw[ob+eb-1+ew]*pw[ow-1]%mod;
            if (ob > 0) (cur += dp[i-1][ob-1][eb][ow]*t%mod) %= mod;
            if (eb > 0 && ow != 0) (cur += dp[i-1][ob][eb-1][ow]*t%mod) %= mod;
        }
        if (c[i] != 0){ // white
            ll t = pw[ow+ew+eb-1]*pw[ob-1]%mod;
            if (ow > 0) (cur += dp[i-1][ob][eb][ow-1]*t%mod)%mod;
            if (ew > 0 && ob != 0) (cur += dp[i-1][ob][eb][ow]*t%mod)%mod;
        }
        if (i == n && (ow+ob)%2 == p) (ans += cur) %= mod;
    }
    cout << ans;
    return 0;
}