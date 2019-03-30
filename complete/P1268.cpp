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

const int inf = 1e8;

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int T, n, dis[40][40];
    // cin >> T;
    while (cin >> n) {
        // cin >> n;
        if (n == 0) break;
        rep(i, 1, n) rep(j, i + 1, n) {
            cin >> dis[i][j];
            dis[j][i] = dis[i][j];
        }
        int ans = dis[1][2];
        rep(i, 3, n) {
            int t = inf;
            rep(j, 1, i - 1) {
                rep(k, j + 1, i - 1) {
                    t = std::min(t, (dis[i][j] + dis[i][k] - dis[j][k]) / 2);
                }
            }
            ans += t;
        }
        cout << ans << endl;
    }
    return 0;
}