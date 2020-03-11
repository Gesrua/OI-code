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
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
    std::ios::sync_with_stdio(false);
    int t, n, m, k, orin, orim;
    cin >> n >> m >> k;
    orin = n;
    orim = m;
    t = gcd(n, k);
    n /= t;
    k /= t;
    t = gcd(m, k);
    m /= t;
    k /= t;
    if (k != 2 && k != 1) {
        cout << "NO";
        return 0;
    }
    if (k == 1) {
        if (n * 2 > orin)
            m *= 2;
        else
            n *= 2;
    }
    cout << "YES\n0 0\n"
         << n << " 0\n"
         << "0 " << m;
    return 0;
}
