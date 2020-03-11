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

const int N = 100009, mod = int(1e9 + 7);

std::vector<int> G[N];
int n;
ll dp[N];

ll solve(int fa, int x) {
    dp[x] = 1;
    for (auto i : G[x]) {
        if (i == fa) continue;
        dp[x] = (dp[x] * (solve(x, i) + 1)) % mod;
    }
    return dp[x];
}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        rep(i, 2, n) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        solve(1, 1);
        ll ans = 0;
        rep(i, 1, n)(ans += dp[i]) %= mod;
        cout << ans << endl;
        rep(i, 1, n) G[i].clear();
    }
    return 0;
}