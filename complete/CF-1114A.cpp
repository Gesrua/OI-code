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
#define fail            \
    {                   \
        cout << "NO\n"; \
        return 0;       \
    }
#define succ             \
    {                    \
        cout << "YES\n"; \
        return 0;        \
    }
int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int x, y, z, a, b, c;
    cin >> x >> y >> z;
    cin >> a >> b >> c;
    if (a < x) fail;
    b += a - x;
    if (b < y) fail;
    c += b - y;
    if (c < z) fail;
    succ;
    return 0;
}
