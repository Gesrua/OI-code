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
int a[1000005];
ll p[1000005];
int l[1000005];
pii s[1000005];
int top = 0;

inline int read() {
    int x = 0, flag = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') flag = -1;
        ch = getchar();
    }
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return x * flag;
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    cout.tie(0);
    int n = read();
    rep(i, 1, n) p[i] = p[i - 1] + (a[i] = read());
    rep(i, 1, n) {
        while (top && s[top].first >= a[i]) --top;
        l[i] = top ? s[top].second + 1 : 1;
        s[++top].first = a[i], s[top].second = i;
    }
    top = 0;
    ll ans = 0;
    int al = 1, ar = 1;
    per(i, n, 1) {
        while (top && s[top].first >= a[i]) --top;
        int r = top ? s[top].second - 1 : n;
        s[++top].first = a[i], s[top].second = i;
        ll calc = (p[r] - p[l[i] - 1]) * a[i];
        if (calc > ans) ans = calc, al = l[i], ar = r;
    }
    cout << ans << '\n' << al << ' ' << ar;
    return 0;
}