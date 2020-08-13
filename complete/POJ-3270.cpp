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

const int N = 10100;
int a[N], un[N], n, val[N], vis[N];

int get(int x) { return std::lower_bound(un + 1, un + 1 + n, x) - un; }

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n;
    int gm = 10000000;
    rep(i, 1, n) {
        cin >> a[i];
        val[i] = un[i] = a[i];
        gm = std::min(gm, val[i]);
    }
    std::sort(un + 1, un + 1 + n);
    rep(i, 1, n) a[i] = get(a[i]);
    // rep(i, 1, n) cerr << a[i] << ' ';
    int ans = 0;
    rep(i, 1, n) {
        if (vis[i] || i == a[i]) continue;
        int s = 0, c = i, lm = 10000000, len = 0;
        do {
            vis[c] = 1;
            len++;
            s += val[c];
            lm = std::min(lm, val[c]);
            c = a[c];
        } while (c != i);
        ans += std::min(s + (len - 2) * lm, s + (len + 1) * gm + lm);
    }
    cout << ans;
    return 0;
}