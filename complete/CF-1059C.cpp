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
    int n, left, out = 1, base = 1, k = 2;
    cin >> n;
    left = n;
    if (n == 3) {
        cout << "1 1 3";
        return 0;
    }
    while (left) {
        k = 2;
        // cerr << "qwq\n";
        while (n / (base * k) != 0 && n / (base * k) <= n / (base * (k + 1)))
            ++k;
        // cerr << "qaq\n";
        base *= k;
        rep(i, 1, left - n / base) cout << out << ' ';
        out = base;
        left = n / base;
    }
    return 0;
}
