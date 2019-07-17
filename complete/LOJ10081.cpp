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

const int N = 25030, inf = 0x3f3f3f3f;

std::vector<pii> g[N];
std::vector<pii> ng[N];
std::vector<int> gg[N];
std::vector<int> block[N];
int color[N], cnt = 0, deg[N], able[N], dis[N], vis[N];

void dfs(int u) {
    block[color[u]].push_back(u);
    for (auto i : g[u]) {
        int v = i.first;
        if (!color[v]) color[v] = color[u], dfs(v);
    }
}

void dfs_gg(int u) {
    able[u] = 1;
    for (auto v : gg[u]) {
        if (!able[v]) dfs_gg(v);
    }
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::memset(dis, 0x3f, sizeof(dis));
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, r, p, s;
    cin >> n >> r >> p >> s;
    rep(i, 1, r) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(pii(v, w));
        g[v].push_back(pii(u, w));
    }
    rep(i, 1, n) if (!color[i]) color[i] = ++cnt, dfs(i);  // 连通块划分

    rep(i, 1, p) {
        int u, v, w;
        cin >> u >> v >> w;
        ng[u].push_back(pii(v, w));
        gg[color[u]].push_back(color[v]);
    }
    int ss = color[s];
    dfs_gg(ss);
    // cerr << "connectable divided" << endl;
    rep(u, 1, cnt) {
        if (!able[u]) continue;
        for (auto v : gg[u]) deg[v]++;
    }
    // cerr << "degree calced" << endl;

    dis[s] = 0;
    std::queue<int> q;
    q.push(ss);
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> heap;
    while (q.size()) {
        int block_id = q.front();
        q.pop();

        for (auto i : block[block_id])
            if (dis[i] < inf) heap.push(pii(dis[i], i));

        while (heap.size()) {
            int u = heap.top().second;
            heap.pop();
            if (vis[u]) continue;
            vis[u] = 1;
            for (auto i : g[u]) {
                int v = i.first, w = i.second;
                if (dis[v] > dis[u] + w)
                    dis[v] = dis[u] + w, heap.push(pii(dis[v], v));
            }
            for (auto i : ng[u]) {
                int v = i.first, w = i.second;
                if (!able[color[v]]) continue;
                deg[color[v]]--;
                if (deg[color[v]] == 0) q.push(color[v]);
                dis[v] = std::min(dis[v], dis[u] + w);
            }
        }
    }

    rep(i, 1, n) {
        if (dis[i] == inf)
            cout << "NO PATH" << endl;
        else
            cout << dis[i] << endl;
    }
    return 0;
}