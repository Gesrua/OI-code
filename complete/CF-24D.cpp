#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
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
typedef unsigned long long ull;
int n, m, x, y;
const int N = 1009;
double f[N][N], a[N][N];
const double ot = double(1) / 3;
const double tf = double(3) / 4;
const double of = double(1) / 4;

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n >> m;
    cin >> x >> y;
    if (m == 1) {
        cout << (n - x) * 2;
        return 0;
    }
    per(i, n - 1, x) {
        a[1][1] = a[m][m] = 2 / 3.0, a[1][m + 1] = 1 + f[i + 1][1] / 3;
        a[1][2] = a[m][m - 1] = -1 / 3.0, a[m][m + 1] = 1 + f[i + 1][m] / 3;
        rep(j, 2, m - 1) a[j][j - 1] = a[j][j + 1] = -1 / 4.0, a[j][j] = 3 / 4.0, a[j][m + 1] = 1 + f[i + 1][j] / 4;
        rep(i, 1, m) {
            double rate = a[i + 1][i] / a[i][i];
            a[i + 1][i] = 0, a[i + 1][i + 1] -= rate * a[i][i + 1], a[i + 1][m + 1] -= rate * a[i][m + 1];
        }
        per(j, m, 1) {
            double rate = a[j - 1][j] / a[j][j];
            a[j - 1][j] = 0, a[j - 1][m + 1] -= a[j][m + 1] * rate;
            f[i][j] = a[j][m + 1] / a[j][j];
        }
    }
    cout.setf(std::ios::fixed);
    // cout << std::setprecision(4) << f[x][y];
    cout << f[x][y];
    return 0;
}