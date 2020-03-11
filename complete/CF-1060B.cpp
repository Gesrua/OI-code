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
int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    long long n;
    cin >> n;
    int ans = 0;
    while (n) {
        if (n < 9) {
            ans += n;
            n = 0;
        } else {
            n -= 9;
            ans += 9 + n % 10;
            n /= 10;
        }
    }
    cout << ans;
    return 0;
}
