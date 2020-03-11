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
    int x;
    cin >> x;
    if (x % 4 == 0) {
        cout << "1 A";
    } else if (x % 4 == 1) {
        cout << "0 A";
    } else if (x % 4 == 2) {
        cout << "1 B";
    } else if (x % 4 == 3) {
        cout << "2 A";
    }
    return 0;
}
