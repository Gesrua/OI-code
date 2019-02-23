#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define rep(i, l, r) for (register int i = (l); i <= (r); ++i)
#define per(i, l, r) for (register int i = (l); i >= (r); --i)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
typedef pair<int, int> pii;
int n, l[100009], r[100009];
int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> l[i] >> r[i];
    std::sort(l + 1, l + 1 + n);
    std::sort(r + 1, r + 1 + n);
    long long ans = 0;
    rep(i, 1, n) { ans += std::max(l[i], r[i]); }
    cout << ans + n;
    return 0;
}
