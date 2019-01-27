#pragma GCC optimize(2)
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
#define rep(i, l, r) for (register int i = (l); i <= (r); ++i)
#define per(i, l, r) for (register int i = (l); i >= (r); --i)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
typedef pair<int, int> pii;
unsigned int dp[20][1048576];
bool vis[20][1048576];
int g[21][21];
int target, n;
struct que {
    unsigned int a[6048576], l = 0, r = 0;
    unsigned int front() { return a[l]; }
    void pop() { ++l; }
    bool empty() { return l >= r; }
    void push(unsigned int x) {
        a[r % 6048576] = x;
        ++r;
    }
} f, q;
int main() {
    std::memset(dp, 0x3f, sizeof(dp));
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n;
    target = (1 << n) - 1;
    rep(i, 0, n - 1) rep(j, 0, n - 1) cin >> g[i][j];
    // std::queue < int > q, f;
    q.push(1);
    f.push(0);
    dp[0][1] = 0;
    int ans = 0;
    while (!q.empty()) {
        int cur = q.front(), from = f.front();
        q.pop();
        f.pop();
        // cerr << cur << ' ' << from << endl;
        // vis[from] = 0;
        vis[from][cur] = 0;
        rep(i, 0, n - 1) {
            if ((cur >> i) & 1) continue;
            int to = cur | (1 << i);
            if (dp[i][to] > dp[from][cur] + g[from][i]) {
                if (!vis[i][to]) {
                    f.push(i);
                    q.push(to);
                    vis[i][to] = 1;
                }
                dp[i][to] = dp[from][cur] + g[from][i];
            }
        }
    }
    cout << dp[n - 1][target];
    return 0;
}