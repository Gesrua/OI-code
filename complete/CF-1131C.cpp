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
using std::abs;
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int ui;
#define chkmax(ori, x) \
    if (ori < x) ori = x;
int n;
int a[200];
std::deque<int> q;
int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    std::sort(a + 1, a + 1 + n);
    int f = 0;
    per(i, n, 1) {
        if (f)
            q.push_back(a[i]);
        else
            q.push_front(a[i]);
        f ^= 1;
    }
    // int ans = 0;
    rep(i, 1, n) {
        cout << q.front() << ' ';
        q.pop_front();
    }
    return 0;
}
