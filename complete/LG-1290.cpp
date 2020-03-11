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

bool gcd(ll a, ll b) {
    if (a < b) return gcd(b, a);
    if (b == 0) return 0;
    if (a / b == 1) return !gcd(b, a % b);
    return 1;
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int T;
    cin >> T;
    ll a, b;
    while (cin >> a >> b) cout << (gcd(a, b) ? "Stan wins\n" : "Ollie wins\n");
    return 0;
}