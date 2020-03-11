#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int ui;

const ll INF = 1e14;
const int N = 1e5 + 9;

ll dp[N][5];
int col[N];
ll a[N];

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int T;
    cin >> T;
    int c[5];
    while (T--) {
        ll ans = INF;
        int n;
        cin >> n;
        rep(i, 1, n) {
            char c;
            cin >> c;
            if (c == 'R')
                col[i] = 1;
            else if (c == 'G')
                col[i] = 2;
            else
                col[i] = 3;
        }
        rep(i, 1, n) cin >> a[i];
        // rep(i, 1, n) cerr << col[i] << ' ';
        // cerr << endl;
        for (c[1] = 1; c[1] <= 3; ++c[1]) {
            for (c[2] = 1; c[2] <= 3; ++c[2]) {
                for (c[3] = 1; c[3] <= 3; ++c[3]) {
                    if (c[1] == c[3] || c[1] == c[2] || c[2] == c[3]) continue;
                    rep(i, 1, n) dp[i][0] = dp[i][1] = dp[i][2] = dp[i][3] = INF;
                    dp[0][0] = 0;
                    rep(i, 1, n) {
                        rep(j, 1, 3) {
                            // if (col[i]==c[j])
                            // dp[i][j]=std::min(dp[i-1][j],dp[i-1][j-1]); else
                            // dp[i][j]=
                            // std::min(dp[i-1][j]+a[i],dp[i-1][j-1]+a[i]);
                            dp[i][j] = std::min(dp[i - 1][j], dp[i - 1][j - 1]);
                            if (col[i] != c[j]) dp[i][j] += a[i];
                        }
                    }
                    ans = std::min(ans, dp[n][3]);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}