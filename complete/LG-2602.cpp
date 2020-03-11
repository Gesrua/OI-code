#include <algorithm>
#include <cassert>
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

ll pow[13], f[13], g[13];

ll* cnt;

ll cnta[10], cntb[10];

void init() {
    pow[0] = 1;
    rep(i, 1, 12) pow[i] = pow[i - 1] * 10;
    f[1] = 1;
    rep(i, 2, 12) f[i] = 10 * f[i - 1] + pow[i - 1];
    g[1] = 0;
    rep(i, 2, 12) g[i] = g[i - 1] + pow[i - 1];
}

void add_all(ll k) {
    // cerr << "aa " << k << endl;
    rep(i, 0, 9) cnt[i] += k;
}

void calc(ll n, int k) {
    if (k == 1) {
        rep(i, 0, n) cnt[i]++;
        return;
    }
    int hi = n / pow[k - 1];
    ll block = pow[k - 1] - 1;
    rep(i, 0, hi) {
        if (n >= i * pow[k - 1] + block) {
            cnt[i] += pow[k - 1];
            add_all(f[k - 1]);
        } else {
            cnt[i] += n - i * pow[k - 1] + 1;
            calc(n % pow[k - 1], k - 1);
        }
    }
}

void solve(ll n) {
    if (n == 0) {
        cnt[0] = 1;
        return;
    }
    if (n < 0) return;
    int k = 0;
    ll t = n;
    while (t) ++k, t /= 10;
    // cerr << "k = " << k << endl;
    calc(n, k);
    cnt[0] -= g[k];
    // rep(i, 0, 9) cout << cnt[i] << ' ';
    // cout << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    init();
    ll l, r;
    cin >> l >> r;
    cnt = cnta;
    solve(l - 1);
    cnt = cntb;
    solve(r);
    rep(i, 0, 9) { cout << cntb[i] - cnta[i] << ' '; }
    return 0;
}