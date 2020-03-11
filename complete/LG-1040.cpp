#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
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
struct node {
    int a[40][40];
    inline int* operator[](int x) { return a[x]; }
};
int n, d[40], dp[40][40], root[40][40];
using std::max;
void print(int l, int r) {
    if (l > r) return;
    cout << root[l][r] << ' ';
    print(l, root[l][r] - 1);
    print(root[l][r] + 1, r);
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 1, n) {
        cin >> d[i];
        dp[i][i] = d[i];
        root[i][i] = i;
    }
    for (int j = 1; j < n; ++j) {
        rep(l, 1, n - j) {
            register int r = l + j;
            dp[l][r] = d[l] + dp[l + 1][r];
            root[l][r] = l;
            if (dp[l][r] < d[r] + dp[l][r - 1]) dp[l][r] = d[r] + dp[l][r - 1], root[l][r] = r;
            for (register int k = l + 1; k < r; ++k)
                if (dp[l][r] < d[k] + dp[l][k - 1] * dp[k + 1][r]) dp[l][r] = d[k] + dp[l][k - 1] * dp[k + 1][r], root[l][r] = k;
        }
    }
    cout << dp[1][n] << endl;
    print(1, n);
    return 0;
}