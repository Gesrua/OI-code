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

bool chk[519];

int a[2020], ans[1020], n;

bool vaild(int x) { return (x >= 1 && x <= 500 && chk[x]); }

void dfs(int p, int l, int r, int ls, int rs) {
    if (l == r) {
        int k = a[n * 2] - ls - rs;
        if (vaild(k)) {
            ans[l] = k;
            rep(i, 1, n) cout << ans[i] << ' ';
            exit(0);
        }
        return;
    }
    int k = a[p] - ls;
    if (vaild(k)) {
        ans[l] = k;
        dfs(p + 1, l + 1, r, ls + k, rs);
    }
    k = a[p] - rs;
    if (vaild(k)) {
        ans[r] = k;
        dfs(p + 1, l, r - 1, ls, rs + k);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n;
    rep(i, 1, 2 * n) cin >> a[i];
    std::sort(a + 1, a + 1 + n * 2);
    int m;
    cin >> m;
    rep(i, 1, m) {
        int t;
        cin >> t;
        chk[t] = 1;
    }
    dfs(1, 1, n, 0, 0);
    return 0;
}