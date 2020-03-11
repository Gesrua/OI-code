#include <algorithm>
#include <cassert>
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
using std::max;
using std::pair;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int ui;

int a[400], f[400][400], trs[400][400];

std::priority_queue<pii, std::vector<pii>, std::greater<pii>> q;

void out(int p, int l, int r) {
    if (l == r) return;
    // cout << trs[l][r] << ' ';
    q.push(pii(p, trs[l][r]));
    out(p + 1, l, trs[l][r]);
    out(p + 1, trs[l][r] + 1, r);
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n;
    cin >> n;
    rep(i, 1, n) cin >> a[i];

    rep(len, 2, n) {
        rep(i, 1, n) {
            int j = i + len - 1;
            if (j > n) break;
            rep(k, i, j - 1) {
                int t = f[i][k] + f[k + 1][j] + (a[i] + a[j]) * a[k];
                if (f[i][j] < t) f[i][j] = t, trs[i][j] = k;
            }
        }
    }
    cout << f[1][n] << endl;
    out(1, 1, n);
    while (!q.empty()) {
        cout << q.top().second << ' ';
        q.pop();
    }
    return 0;
}