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
using std::min;
using std::pair;
typedef pair<int, int> pii;
int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n;
    int g[300][300];
    unsigned int f[300];
    std::memset(f, 0x3f, sizeof(f));
    cin >> n;
    f[1] = 0;
    int x;
    rep(i, 1, n) rep(j, i + 1, n) {
        cin >> x;
        f[j] = min(f[j], f[i] + x);
    }
    cout << f[n];
    // cin >> g[i][j];
    return 0;
}