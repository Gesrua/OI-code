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

int f[202][9000], a[202], b[202], path[202][9000];

const int fix = 4500;

struct Node {
    int prev, i;
} p[10000000];
int cnt = 1;

void output(int id) {
    if (p[id].i == 0) return;
    output(p[id].prev);
    cout << ' ' << p[id].i;
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, m;
    // clang-format off
    int T = 0;
    while (cin >> n >> m) {
        ++T;
        cnt = 1;
        if (n == 0 && m == 0) break;
        rep(i, 1, n) cin >> a[i] >> b[i];
        rep(i, 0, 201) rep(j, 0, 8999) f[i][j] = -1000000, path[i][j] = 0;
        f[0][0 + fix] = 0;
        rep(i, 1, n) per(v, m, 0) rep(x, -4000, 4000) {
            if (f[v][x + fix] + a[i] + b[i] > f[v + 1][x + a[i] - b[i] + fix]) {
                f[v + 1][x + a[i] - b[i] + fix] = f[v][x + fix] + a[i] + b[i],
                // path[v + 1][x + a[i] - b[i] + fix] = i;
                path[v + 1][x + a[i] - b[i] + fix] = cnt;
                p[cnt].i = i, p[cnt++].prev = path[v][x + fix];
            }
        }
        // clang-format on

        rep(i, 0, 4000) {
            if (f[m][i + fix] >= 0 || f[m][-i + fix] >= 0) {
                cout << "Jury #" << T << endl;
                if (f[m][i + fix] > f[m][-i + fix]) {
                    cout << "Best jury has value " << (f[m][i + fix] + i) / 2
                         << " for prosecution and value "
                         << (f[m][i + fix] - i) / 2 << " for defence:" << endl;
                    // cout << f[m][i + fix] << endl;
                    output(path[m][i + fix]);
                } else {
                    cout << "Best jury has value " << (f[m][fix - i] - i) / 2
                         << " for prosecution and value "
                         << (f[m][fix - i] + i) / 2 << " for defence:" << endl;

                    // cout << f[m][-i + fix] << endl;

                    output(path[m][fix - i]);
                }
                cout << endl << endl;
                break;
            }
        }
    }
    return 0;
}