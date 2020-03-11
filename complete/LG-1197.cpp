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
std::vector<int> g[400010];
int a[400010], att[400010], f[400010], ans[400010];

int getf(int x) { return x == f[x] ? x : (f[x] = getf(f[x])); }

inline void merge(int x, int y) { f[getf(y)] = getf(x); }

inline bool same(int x, int y) { return getf(x) == getf(y); }

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    rep(i, 0, n - 1) f[i] = i;
    rep(i, 1, m) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int k;
    cin >> k;
    rep(i, 1, k) cin >> a[i], att[a[i]] = 1;
    rep(i, 0, n - 1) if (!att[i]) ans[k + 1]++;
    ans[k] = ans[k + 1];
    rep(i, 0, n - 1) {
        if (!att[i])
            for (auto v : g[i])
                if (!att[v] && !same(i, v)) {
                    merge(i, v);
                    ans[k]--;
                }
    }
    per(i, k, 1) {
        ans[i - 1] = ans[i] + 1;
        int u = a[i];
        att[u] = 0;
        for (auto v : g[u]) {
            if (!att[v] && !same(u, v)) {
                merge(u, v);
                ans[i - 1]--;
            }
        }
    }
    rep(i, 0, k) cout << ans[i] << endl;
    return 0;
}