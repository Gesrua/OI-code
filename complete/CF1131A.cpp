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
int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int w1, h1, w2, h2;
    cin >> w1 >> h1 >> w2 >> h2;
    cout << (std::max(w1, w2) + h1 + h2) * 2 + 4;
    // if (w1 == w2) {
    //     cout << (w1 + h1 + h2) * 2 + 4;
    // }
    // else cout << ()
    return 0;
}
