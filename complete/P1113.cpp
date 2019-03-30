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
int n, dis[10100];
int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n;
    int ans = 0;
    rep(i, 1, n) {
        int x, j, len;
        cin >> j >> len;
        dis[i] = len;
        for (cin >> j; j != 0; cin >> j) {
            dis[i] = std::max(dis[i], dis[j] + len);
        }
        ans = std::max(ans, dis[i]);
    }
    cout << ans;
    return 0;
}