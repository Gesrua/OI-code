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
int ksm(ll a, int n, int p) {
    ll ret = 1;
    while (n) {
        if (n & 1) (ret *= a) %= p;
        (a *= a) %= p;
        n >>= 1;
    }
    return ret;
}
int inv(int a, int p) { return ksm(a, p - 2, p); }
struct Hash {
    int p, ratio;
    Hash() : p(998244353), ratio(127) {}
    Hash(int _p, int _r) : p(_p), ratio(_r) {}
    int calc(std::string& s) {
        ll ret = 0;
        rep(i, 0, s.size() - 1) ret = (ret * ratio + s[i]) % p;
        return ret;
    }
    int solve(std::string& s) {
        int g = calc(s), ls = s.size();
        int ret = 0;
        ll cur = 0;
        rep(r, 0, ls - 1) {
            cur = (cur * ratio + s[r]) % p;
            int len = r + 1;
            if (ls % len != 0) continue;
            // cerr << ksm(ratio, ls, p) - 1 << endl;
            // cerr << cur * (ksm(ratio, ls, p) - 1) %p * inv(ksm(ratio, len, p) - 1, p) % p << endl;
            if (cur * (ksm(ratio, ls, p) - 1) %p * inv(ksm(ratio, len, p) - 1, p) % p == g) {
                return ls/len;
            }
        }
    }
} h1;
int main() {
#ifdef LOCAL
    freopen("/tmp/download/data/power1.in", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    std::string s;
    while (cin >> s) {
        if (s[0] == '.') break;
        cout << h1.solve(s) << endl;
    }
    return 0;
}