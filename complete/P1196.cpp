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

const int n = 30000, N = 30100;

int dep[N], fa[N], lst[N];

pii getf(int x) {
    if (x == fa[x]) return pii(x, 0);
    auto upd = getf(fa[x]);
    return pii(fa[x] = upd.first, dep[x] += upd.second);
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int T;
    cin >> T;
    rep(i, 1, n) fa[i] = lst[i] = i;
    while (T--) {
        char c;
        cin >> c;
        int i, j;
        cin >> i >> j;
        if (c == 'M') {
            auto chg = getf(j);
            int rt = getf(i).first;
            fa[chg.first] = lst[rt];
            dep[chg.first] = 1;
            lst[rt] = lst[chg.first];
        } else {
            getf(i), getf(j);
            cout << (fa[i] == fa[j] ? std::abs(dep[j] - dep[i]) - 1 : -1)
                 << endl;
        }
    }
    return 0;
}