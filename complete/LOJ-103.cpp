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

const int N = 1000100;

char s[N], sub[N];
int l1, l2;

int ksm(ll a, int n, int p) {
    ll ret = 1;
    while (n) {
        if (n & 1) (ret *= a) %= p;
        (a *= a) %= p;
        n >>= 1;
    }
    return ret % p;
}

inline int mod(ll a, int p) { return (a % p + p) % p; }

struct Hash {
    int p, ratio, tot;
    int a[N];
    Hash() : p(998244353), ratio(256), tot(0) {}
    Hash(int _p, int _r) : p(_p), ratio(_r), tot(0) {}
    void load(char s[], int len) {
        rep(i, 1, len) { add(s[i]); }
    }
    void add(int x) {
        a[tot + 1] = ((ll)a[tot] * ratio + x) % p;
        tot++;
    }
    // (l, r]
    int calc(int l, int r) {
        return mod((ll)a[r] - (ll)a[l] * ksm(ratio, r - l, p), p);
    }
    int calc(char s[], int len) {
        ll ret = 0;
        rep(i, 1, len)(ret = ret * ratio + s[i]) %= p;
        return ret;
    }
} a(1000000007, 256), b(1000000009, 256);

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> s + 1 >> sub + 1;
    l1 = strlen(s + 1), l2 = strlen(sub + 1);
    a.load(s, l1), b.load(s, l1);
    int ga = a.calc(sub, l2), gb = b.calc(sub, l2);
    int ans = 0;
    rep(r, l2, l1) ans += (ga == a.calc(r - l2, r) && gb == b.calc(r - l2, r));
    cout << ans;
    return 0;
}