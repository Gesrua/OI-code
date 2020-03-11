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

ll a[100010];

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    ll fix = 0, ans = 0, cnt = 0, block = -1;
    rep(i, 1, m) {
        cin >> a[i];
        a[i]--;
        if ((a[i] - fix) / k != block) {
            ans += 1;
            fix += cnt;
            block = (a[i] - fix) / k;
            cnt = 1;
        } else
            cnt++;
    }
    cout << ans;
    return 0;
}
