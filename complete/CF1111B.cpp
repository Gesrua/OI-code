#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
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

ll a[100100];

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    ll n, k, m;
    cin >> n >> k >> m;
    double l, r;
    rep(i, 1, n) cin >> a[i];
    std::sort(a + 1, a + 1 + n, std::greater<int>());
    double sum = 0, ans = 0;
    rep(i, 1, n) {
        sum += a[i];
        if (m >= (n - i))
            ans = std::max(ans, (sum + std::min((m - (n - i)), i * k)) / i);
    }
    cout.setf(std::ios::fixed);
    cout << std::setprecision(14) << ans;
    return 0;
}
