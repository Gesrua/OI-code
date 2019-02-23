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
int n, m, tg[1009][1009], s[1009][1009];
inline bool legal(int x, int y) {
    if (x <= 1 || y <= 1 || x >= n || y >= m) return false;
    if (tg[x - 1][y - 1] != 1 || tg[x - 1][y] != 1 || tg[x - 1][y + 1] != 1 ||
        tg[x][y - 1] != 1 || tg[x][y + 1] != 1 || tg[x + 1][y - 1] != 1 ||
        tg[x + 1][y] != 1 || tg[x + 1][y + 1] != 1)
        return false;
    return true;
}
inline bool color(int x, int y) {
    if (!legal(x, y)) return false;
    s[x - 1][y - 1] = 1;
    s[x - 1][y] = 1;
    s[x - 1][y + 1] = 1;

    s[x][y - 1] = 1;
    s[x][y + 1] = 1;

    s[x + 1][y - 1] = 1;
    s[x + 1][y] = 1;
    s[x + 1][y + 1] = 1;
    return true;
}
int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n >> m;
    rep(i, 1, n) rep(j, 1, m) {
        char c;
        cin >> c;
        tg[i][j] = (c == '#');
    }
    rep(i, 1, n) rep(j, 1, m) {
        if (tg[i][j]) {
            if (!(legal(i - 1, j - 1) || legal(i - 1, j) ||
                  legal(i - 1, j + 1) || legal(i, j - 1) || legal(i, j + 1) ||
                  legal(i + 1, j - 1) || legal(i + 1, j) ||
                  legal(i + 1, j + 1))) {
                cerr << i << ' ' << j << endl;
                cout << "no";
                return 0;
            }
        }
    }
    cout << "yes";
    return 0;
}
