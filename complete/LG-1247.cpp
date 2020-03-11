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

const int N = 500010;
int a[N];

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, x = 0;
    cin >> n;
    rep(i, 1, n) {
        cin >> a[i];
        x ^= a[i];
    }
    if (x != 0) {
        rep(i, 1, n) if (a[i] >= (x ^ a[i])) {
            cout << (a[i] - (x ^ a[i])) << ' ' << i << endl;
            a[i] = x ^ a[i];
            break;
        }
        rep(i, 1, n) cout << a[i] << ' ';
    } else
        cout << "lose";
    return 0;
}