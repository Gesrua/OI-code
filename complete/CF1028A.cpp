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
char a[120][120];
int ans_x = 0, ans_y = 0;
int main() {
    std::ios::sync_with_stdio(false);
    int m, n, t;
    cin >> m >> n;
    rep(i, 1, m) cin >> a[i] + 1;
    rep(i, 1, m) {
        rep(j, 1, n) {
            if (a[i][j] == 'B') {
                t = 0;
                // cerr << i << ' ' << j << endl;
                int x = j;
                while (a[i][j] == 'B') ++t, ++j;
                cout << i + t / 2 << ' ' << x + t / 2;
                return 0;
            }
        }
    }
    return 0;
}
