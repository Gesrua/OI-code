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

int sg[210][210];

int calc(int x, int y) {
    if (x > y) std::swap(x, y);
    if (sg[x][y] != -1) return sg[x][y];
    std::set<int> s;
    rep(i, 2, x - 2) s.insert(calc(i, y) ^ calc(x - i, y));
    rep(i, 2, y - 2) s.insert(calc(x, i) ^ calc(x, y - i));
    int lst = 0;
    while (s.count(lst)) lst++;
    return sg[x][y] = lst;
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    std::memset(sg, -1, sizeof(sg));
    sg[1][1] = 0;
    int x, y;
    while (cin >> x >> y) {
        cout << (calc(x, y) ? "WIN" : "LOSE") << endl;
    }
    return 0;
}