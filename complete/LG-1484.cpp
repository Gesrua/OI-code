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

ll a[N];
int l[N], r[N], vis[N];

typedef std::pair<long long, int> pli;

std::priority_queue<pli> q;

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    rep(i, 1, n) {
        cin >> a[i];
        l[i] = i - 1, r[i] = i + 1;
        q.push({a[i], i});
    }
    l[0] = 0, r[0] = 1, l[n + 1] = n, r[n + 1] = n + 1;
    ll ans = 0;
    while (k--) {
        while (vis[q.top().second]) q.pop();
        ll val = q.top().first;
        int id = q.top().second;
        q.pop();
        if (val < 0) break;

        ans += val;

        a[id] = a[l[id]] + a[r[id]] - a[id];
        q.push({a[id], id});
        vis[l[id]] = vis[r[id]] = 1;

        l[id] = l[l[id]], r[id] = r[r[id]], r[l[id]] = id, l[r[id]] = id;
    }
    cout << ans;
    return 0;
}