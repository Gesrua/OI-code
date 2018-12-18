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
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cin; using std::cout; using std::cerr; using std::endl;
using std::make_pair; using std::pair;
typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned int ui;

const int N = 5009, A = 100009;

int dp[N][N], a[N], maxn[A], maxm[10];

int main(){
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n;
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    int ans = 0;
    rep(x, 0, n){
        std::memset(maxn, 0, sizeof(maxn));
        std::memset(maxm, 0, sizeof(maxm));
        rep(y, 0, n){
            if (x == y) dp[x][y] = 0;
            else if (x < y){
                dp[x][y] = 1 + std::max(
                    std::max(
                        maxn[a[y]-1],
                        maxn[a[y]+1]
                    ),
                    std::max(
                        maxm[a[y]%7],
                        dp[x][0]
                    )
                );
                dp[y][x] = dp[x][y];
            }
            maxn[a[y]] = std::max(maxn[a[y]], dp[x][y]);
            maxm[a[y]%7] = std::max(maxm[a[y]%7], dp[x][y]);
            ans = std::max(dp[x][y], ans);
        }
    }
    cout << ans;
    return 0;
}