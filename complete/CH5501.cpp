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

const int N = 1e6 + 10;
struct deque {
    pii q[N * 2];
    int l, r;
    // [l, r)
    void clear() { l = r = 1; }
    pii& end() { return q[r - 1]; }
    int size() { return r - l; }
    pii& front() { return q[l]; }
    void push_back(pii x) { q[r++] = x; }
    void pop_back() { --r; }
    void pop_front() { ++l; }
    deque() { clear(); }
} q;
int a[N * 2];

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n;
    int ans = 0;
    cin >> n;
    int half = n / 2;
    rep(i, 1, n) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    q.push_back({1, a[1] - 1});
    rep(i, 2, n + half + 1) {
        while (i - q.front().first > half) q.pop_front();
        ans = std::max(ans, q.front().second + a[i] + i);
        while (q.size() && q.end().second < a[i] - i) q.pop_back();
        q.push_back({i, a[i] - i});
    }
    cout << ans;
    return 0;
}