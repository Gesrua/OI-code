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

const int N = 300100;

struct node {
    int b, t;
    bool operator<(const node& rhs) const { return b < rhs.b; }
} a[N];

ll len[N];

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    rep(i, 1, n) cin >> a[i].t >> a[i].b;
    std::sort(a + 1, a + 1 + n);
    // std::priority_queue<int> q;
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    ll sum = a[n].t;
    len[n] = a[n].t;
    q.push(a[n].t);
    per(i, n - 1, 1) {
        if (q.size() < k) {
            sum += a[i].t;
            len[i] = sum;
            q.push(a[i].t);
        } else if (a[i].t > q.top()) {
            len[i] = sum - q.top() + a[i].t;
            sum += a[i].t - q.top();
            q.pop();
            q.push(a[i].t);
        }
    }
    ll ans = 0;
    rep(i, 1, n) { ans = std::max(ans, len[i] * a[i].b); }
    cout << ans;
    return 0;
}
