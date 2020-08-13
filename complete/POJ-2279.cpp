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

uint f[31][16][11][9][7];

uint a[31];

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n;
    while (cin >> n) {
        if (n == 0) break;
        std::memset(f, 0, sizeof(f));
        std::memset(a, 0, sizeof(a));
        f[1][0][0][0][0] = 1;
        rep(i, 1, n) cin >> a[i];
        for (int x1 = 1; x1 <= a[1]; ++x1) {
            for (int x2 = 0; x2 <= a[2] && x2 <= x1; ++x2) {
                for (int x3 = 0; x3 <= a[3] && x3 <= x2; ++x3) {
                    for (int x4 = 0; x4 <= a[4] && x4 <= x3; ++x4) {
                        for (int x5 = 0; x5 <= a[5] && x5 <= x4; ++x5) {
                            int c = f[x1][x2][x3][x4][x5];
                            if (x1 < a[1]) f[x1 + 1][x2][x3][x4][x5] += c;
                            if (x2 < a[2] && x2 < x1)
                                f[x1][x2 + 1][x3][x4][x5] += c;
                            if (x3 < a[3] && x3 < x2)
                                f[x1][x2][x3 + 1][x4][x5] += c;
                            if (x4 < a[4] && x4 < x3)
                                f[x1][x2][x3][x4 + 1][x5] += c;
                            if (x5 < a[5] && x5 < x4)
                                f[x1][x2][x3][x4][x5 + 1] += c;
                        }
                    }
                }
            }
        }
        cout << f[a[1]][a[2]][a[3]][a[4]][a[5]] << endl;
    }
    return 0;
}