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
typedef unsigned long long ull;

const int p[] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441};

const int N = 101, M = 11;
int g[N], f[2][531441];
std::vector<int> s;
int *cur;
int n, m, prev, v[M];
// #define dbg(...) fprintf(stderr, __VA_ARGS__);
#define dbg(...)

void dfs(int status, int i, int lst, int cnt) {
    if (i == m) {
        dbg("reach\n");
        cur[status] = std::max(cur[status], cnt + prev);
        return;
    }
    if (v[i] == 1 || v[i] == 0)
        dfs(status + v[i] * p[i], i + 1, lst, cnt);
    else if (lst + 2 < i) {
        dfs(status + 2 * p[i], i + 1, i, cnt + 1);
        dfs(status, i + 1, lst, cnt);
    } else {
        dfs(status, i + 1, lst, cnt);
    }
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n >> m;
    std::memset(f, -1, sizeof(f));
    f[0][0] = 0;
    for (int i = 0; i < p[m]; ++i) {
        int valid = 1;
        for (int x = i, j = 0, lst = -5; j < m; ++j, x /= 3)
            if (x % 3 == 2) {
                if (lst + 2 < j)
                    lst = j;
                else {
                    valid = 0;
                    break;
                }
            }
        if (valid) s.push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            g[j] = (c == 'H');
        }
        cur = f[(i + 1) & 1];
        std::memset(cur, -1, sizeof(f) / 2);
        for (auto j : s) {
            if (f[i & 1][j] == -1) continue;
            prev = f[i & 1][j];
            for (int k = 0, x = j; k < m; ++k, x /= 3) {
                if (x % 3 == 2)
                    v[k] = 1;
                else if (x % 3 == 1 || g[k])
                    v[k] = 0;
                else
                    v[k] = -1;
                dbg("%3d", v[k]);
            }
            dbg("\n");
            dfs(0, 0, -5, 0);
        }
    }
    int ans = -1;
    for (auto j : s) ans = std::max(ans, f[n & 1][j]);
    cout << ans;
    return 0;
}