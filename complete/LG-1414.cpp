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

const int N = 10010, inf = 1e6;

struct F {
    int num, id;
    bool operator<(const F& b) const { return num != b.num ? num < b.num : id > b.id; }
    bool operator==(const F& b) const { return num == b.num; }
} factor[inf + 10];

int ret[N];

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n;
    cin >> n;
    rep(i, 0, inf) factor[i].id = i;
    rep(i, 1, n) {
        int x;
        cin >> x;
        int lim = std::sqrt(x);
        rep(f, 1, lim) {
            if (x % f == 0) factor[f].num++, factor[x / f].num++;
        }
        if (lim * lim == x) factor[lim].num--;
    }
    std::sort(factor, factor + inf + 1);
    int p = inf, ans = 0;
    per(i, n, 1) {
        while (factor[p].num >= i) ans = std::max(factor[p].id, ans), p--;
        ret[i] = ans;
    }
    rep(i, 1, n) cout << ret[i] << endl;
    return 0;
}