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
const int N = 1000010;

int n, a[N], deg[N], q[N], l, r, vis[N];

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n;
    rep(i, 1, n) {
        cin >> a[i];
        deg[a[i]]++;
    }
    l = 1, r = 0;
    rep(i, 1, n) if (deg[i] == 0) q[++r] = i;
    int ans = 0;
    while (l <= r) {
        int u = q[l++], v = a[u];
        if (!vis[u] && !vis[a[u]]) {
            vis[v] = 1;
            ans++;
            deg[a[a[u]]]--;
            if (deg[a[a[u]]] == 0) q[++r] = a[a[u]];
        }
        vis[u] = 1;
    }
    rep(i, 1, n) {
        if (!vis[i]) {
            int u = i;
            int cnt = 0;
            do {
                vis[u] = 1, cnt++, u = a[u];
            } while (u != i);
            ans += (cnt) / 2;
        }
    }
    cout << ans << endl;
    return 0;
}