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
using std::pair;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int ui;

const int N = 3010;

int a[N], b[N], f[N][N], n, m;

pii path[N][N];

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    cin >> m;
    rep(i, 1, m) cin >> b[i];
    rep(i, 1, n) {
        int v = 0;
        pii p = pii(0, 0);
        rep(j, 1, m) {
            if (a[i] == b[j]) {
                f[i][j] = v + 1, path[i][j] = p;
            } else {
                f[i][j] = f[i - 1][j], path[i][j] = pii(i - 1, j);
            }
            if (b[j] < a[i] && v < f[i - 1][j])
                v = f[i - 1][j], p = pii(i - 1, j);
        }
    }
    int ans = 0;
    pii p;
    rep(j, 1, m) if (f[n][j] > ans) ans = f[n][j], p = pii(n, j);
    cout << ans << endl;
    std::vector<int> arr;
    while (p.first != 0 || p.second != 0) {
        pii nxt = path[p.first][p.second];
        if (f[p.first][p.second] != f[nxt.first][nxt.second])
            arr.push_back(b[p.second]);
        p = nxt;
    }
    per(i, arr.size() - 1, 0) cout << arr[i] << ' ';
    return 0;
}
