#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("inline")
// #pragma GCC optimize("-fgcse")
// #pragma GCC optimize("-fgcse-lm")
// #pragma GCC optimize("-fipa-sra")
// #pragma GCC optimize("-ftree-pre")
// #pragma GCC optimize("-ftree-vrp")
// #pragma GCC optimize("-fpeephole2")
// #pragma GCC optimize("-ffast-math")
// #pragma GCC optimize("-fsched-spec")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("-falign-jumps")
// #pragma GCC optimize("-falign-loops")
// #pragma GCC optimize("-falign-labels")
// #pragma GCC optimize("-fdevirtualize")
// #pragma GCC optimize("-fcaller-saves")
// #pragma GCC optimize("-fcrossjumping")
// #pragma GCC optimize("-fthread-jumps")
// #pragma GCC optimize("-funroll-loops")
// #pragma GCC optimize("-fwhole-program")
// #pragma GCC optimize("-freorder-blocks")
// #pragma GCC optimize("-fschedule-insns")
// #pragma GCC optimize("inline-functions")
// #pragma GCC optimize("-ftree-tail-merge")
// #pragma GCC optimize("-fschedule-insns2")
// #pragma GCC optimize("-fstrict-aliasing")
// #pragma GCC optimize("-fstrict-overflow")
// #pragma GCC optimize("-falign-functions")
// #pragma GCC optimize("-fcse-skip-blocks")
// #pragma GCC optimize("-fcse-follow-jumps")
// #pragma GCC optimize("-fsched-interblock")
// #pragma GCC optimize("-fpartial-inlining")
// #pragma GCC optimize("no-stack-protector")
// #pragma GCC optimize("-freorder-functions")
// #pragma GCC optimize("-findirect-inlining")
// #pragma GCC optimize("-fhoist-adjacent-loads")
// #pragma GCC optimize("-frerun-cse-after-loop")
// #pragma GCC optimize("inline-small-functions")
// #pragma GCC optimize("-finline-small-functions")
// #pragma GCC optimize("-ftree-switch-conversion")
// #pragma GCC optimize("-foptimize-sibling-calls")
// #pragma GCC optimize("-fexpensive-optimizations")
// #pragma GCC optimize("-funsafe-loop-optimizations")
// #pragma GCC optimize("inline-functions-called-once")
// #pragma GCC optimize("-fdelete-null-pointer-checks")
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr;
using std::endl;
using std::make_pair;
using std::pair;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int ui;

const int BUF = 50000000;
struct IOStream {
    char ibuf[BUF], *s;
    char obuf[BUF], *oh;
    IOStream() : s(ibuf), oh(obuf) { ibuf[fread(ibuf, 1, BUF, stdin)] = '\0'; }
    ~IOStream() { fwrite(obuf, 1, oh - obuf, stdout); }
    template <typename T>
    inline IOStream &operator>>(T &x) {
        while (!isdigit(*s)) s++;
        for (x = 0; isdigit(*s); s++) x = x * 10 + (*s ^ '0');
        return *this;
    }
} cin;
using std::cout;

const int N = 100010;
const int M = 200010;
int P, n, m, k;
struct Graph {
    struct Edge {
        int v, w;
        Edge *nxt;
    } e[M];
    int cnt = 0;
    Edge *p[N];
    void clear() {
        std::memset(p, 0, sizeof(p));
        cnt = 0;
    }
    void addedge(int u, int v, int w) {
        e[cnt].v = v, e[cnt].w = w, e[cnt].nxt = p[u], p[u] = &e[cnt++];
    }
} g, fg;

int dis[N], flg[N];
std::priority_queue<pii, std::vector<pii>, std::greater<pii> > q;
void dijkstra(int s) {
    std::memset(dis, -1, sizeof(dis));
    std::memset(flg, 0, sizeof(flg));
    dis[s] = 0;
    q.push({0, s});
    while (q.size()) {
        pii cur = q.top();
        q.pop();
        if (flg[cur.second]) continue;
        flg[cur.second] = 1;
        for (Graph::Edge *i = g.p[cur.second]; i != nullptr; i = i->nxt) {
            if (!flg[i->v] &&
                (dis[i->v] == -1 || dis[i->v] > cur.first + i->w)) {
                dis[i->v] = cur.first + i->w;
                q.push({dis[i->v], i->v});
            }
        }
    }
}

int f[N][52], vis[N][52];
int now = 0;
bool zp = 0;
int work(int u, int lk) {
    // cerr << u << ' ' << lk << endl;
    if (zp) return 0;
    if (f[u][lk] != -1) return f[u][lk];
    vis[u][lk] = 1;
    f[u][lk] = 0;
    for (Graph::Edge *i = fg.p[u]; i != NULL && !zp; i = i->nxt) {
        // cerr << u << "->" << i->v << endl;
        int nk = lk + dis[u] - i->w - dis[i->v];
        if (nk > k || nk < 0 || dis[i->v] == -1) continue;
        if (vis[i->v][nk]) {
            zp = 1;
            return 0;
        }
        f[u][lk] = (f[u][lk] + work(i->v, nk)) % P;
    }
    vis[u][lk] = 0;
    return f[u][lk];
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--) {
        g.clear(), fg.clear();
        std::memset(f, -1, sizeof(f));
        std::memset(vis, 0, sizeof(vis));
        zp = 0;
        int t_t = clock();
        cin >> n >> m >> k >> P;
        rep(i, 1, m) {
            int u, v, w;
            cin >> u >> v >> w;
            g.addedge(u, v, w), fg.addedge(v, u, w);
        }
        g.addedge(0, 1, 0), fg.addedge(1, 0, 0);
        dijkstra(0);
        cerr << "dij " << ((double)clock() - t_t) / CLOCKS_PER_SEC << endl;
        // rep(i, 1, n) cerr << dis[i] << ' ';
        // cerr << endl;
        t_t = clock();
        int ans = 0;
        f[0][0] = 1;
        rep(i, 0, k) {
            now = i;
            ans = (ans + work(n, i)) % P;
        }
        if (zp)
            printf("-1\n");
        else
            printf("%d\n", ans);
        cerr << "work " << ((double)clock() - t_t) / CLOCKS_PER_SEC << endl;
    }

    return 0;
}