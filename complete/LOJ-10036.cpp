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
int ksm(ll a, int n, const int p) {
    ll ret = 1;
    while (n) {
        if (n & 1) (ret *= a) %= p;
        (a *= a) %= p, n >>= 1;
    }
    return ret;
}

const int p = 998244353, ratio = 127;

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    std::string s;
    while (cin >> s) {
        ll pre = 0, suc = 0;
        for (int i = 0, j = s.size() - 1; i < s.size(); ++i, --j) {
            pre = (pre * ratio + s[i]) % p;
            suc = ((ll)s[j] * ksm(ratio, s.size() - j - 1, p) + suc) % p;
            if (pre == suc) cout << i + 1 << ' ';
        }
        cout << endl;
    }
    return 0;
}