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

const int N = 10100;

const int inf = 100000000;

std::vector<pii> g[N];

int dis[N], cnt[N];

bool vis[N];

bool spfa(int u) {
    vis[u] = 1;
    for (auto i : g[u]) {
        if (dis[i.first] > dis[u] + i.second) {
            dis[i.first] = dis[u] + i.second;
            if (vis[i.first]) return 0;
            if (!spfa(i.first)) return 0;
        }
    }
    vis[u] = 0;
    return 1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("/tmp/input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    while (m--) {
        int opt, x, y, k;
        cin >> opt >> x >> y;
        if (opt == 3)
            g[x].push_back(pii(y, 0)), g[y].push_back(pii(x, 0));
        else {
            cin >> k;
            if (opt == 1)
                g[x].push_back(pii(y, -k));
            else
                g[y].push_back(pii(x, k));
        }
    }
    rep(i, 1, n) g[0].push_back(pii(i, 0)), dis[i] = inf;
    if (!spfa(0))
        cout << "No";
    else
        cout << "Yes";
    return 0;
}