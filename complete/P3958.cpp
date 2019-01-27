#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define rep(i, l, r) for (register int i = (l); i <= (r); ++i)
#define per(i, l, r) for (register int i = (l); i >= (r); --i)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
typedef pair<int, int> pii;
long long lim;
struct node {
    long long x, y, z;
    inline bool tunnel(node& b) { return (b.x - x) * (b.x - x) + (b.y - y) * (b.y - y) + (b.z - z) * (b.z - z) <= lim; }
} p[1009];
struct edge {
    int v;
    edge* nxt;
    edge() { nxt = nullptr; }
} e[2000009];
int tot = 0, stcnt, endcnt;
edge* head[1009];
int start[1009], end[1009], vis[1009];
inline void _addedge(int u, int v) { e[tot].nxt = head[u], e[tot].v = v, head[u] = &e[tot++]; }
int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        tot = 0;
        int n, h;
        long long r;
        cin >> n >> h >> r;
        lim = 4 * r * r;
        stcnt = 0;
        endcnt = 0;
        rep(i, 1, n) {
            vis[i] = 0;
            head[i] = nullptr;
            cin >> p[i].x >> p[i].y >> p[i].z;
            if (p[i].z + r >= h)
                end[i] = 1;
            else
                end[i] = 0;
            if (p[i].z <= r) start[stcnt++] = i;
            rep(j, 1, i - 1) {
                if (p[j].tunnel(p[i])) {
                    // cerr << i << ' ' << j << ' ';
                    _addedge(i, j);
                    _addedge(j, i);
                }
            }
        }
        std::queue<int> q;
        for (int i = 0; i < stcnt; ++i) {
            q.push(start[i]);
            vis[start[i]] = true;
            // cout << start[i] << ' ';
        }
        while (!q.empty()) {
            if (end[q.front()]) {
                cout << "Yes\n";
                goto nxt;
            }
            for (edge* i = head[q.front()]; i != nullptr; i = i->nxt) {
                if (vis[i->v]) continue;
                q.push(i->v);
                vis[i->v] = true;
                if (end[i->v]) {
                    cout << "Yes\n";
                    goto nxt;
                }
            }
            q.pop();
        }
        // cout << "dbg " << vis[2];
        cout << "No\n";
    nxt:
        233;
    }
    return 0;
}