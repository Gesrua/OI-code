#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;

const int M = 200100, N = 1009;

struct Edge{
    int v;
    Edge* nxt;
} e[M]; int tot = 0, num = 0;
Edge* p[N];
int hate[N][N];
inline void addedge(int u, int v){
    e[tot].v = v, e[tot].nxt = p[u], p[u] = &e[tot++];
}

std::vector<int> dcc[N]; int cnt = 0;
int dfn[N], low[N], stack[N], top;

void tarjan(int u){
    dfn[u] = low[u] = ++num;
    stack[++top] = u;
    for(auto i = p[u]; i; i = i->nxt){
        if (!dfn[i->v]){
            tarjan(i->v);
            low[u] = std::min(low[u], low[i->v]);
            if (low[i->v] >= dfn[u]){
                ++cnt;
                int z;
                dcc[cnt].clear();
                do{
                    z = stack[top--];
                    dcc[cnt].push_back(z);
                } while(z != i->v);
                dcc[cnt].push_back(u);
            }
        } else low[u] = std::min(low[u], dfn[i->v]);
    }
}

int c[N], blg[N], blk, ex; bool tag[N];

void dfs(int u){
    // cerr << blk << ' ' << u << ' ' << c[u] << endl;
    for(auto i = p[u]; i && !ex; i = i->nxt){
        // cerr << u << " -> " << i->v << endl;
        if (blg[i->v] != blk) continue;
        if (c[u] == c[i->v]) {ex = 1; return; }
        if (!c[i->v]) c[i->v] = (1^c[u]), dfs(i->v);
    }
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int n, m;
    while(cin >> n >> m && n){
        std::memset(p, 0, sizeof(p)); tot = 0;
        std::memset(hate, 0, sizeof(hate));
        std::memset(dfn, 0, sizeof(dfn));
        std::memset(blg, 0, sizeof(blg));
        std::memset(tag, 0, sizeof(tag));
        num = 0; cnt = 0; top = 0;
        rep(i, 1, m){
            int u, v; cin >> u >> v;
            hate[u][v] = hate[v][u] = 1;
        }
        rep(u, 1, n) rep(v, 1, n) if (!hate[u][v] && u != v) addedge(u, v);

        rep(i, 1, n) if (!dfn[i]) tarjan(i);

        rep(i, 1, cnt){
            ex = 0, blk = i;
            for(auto u : dcc[i]) blg[u] = i, c[u] = 0;
            c[dcc[i][0]] = 2; dfs(dcc[i][0]);
            if (ex) for(auto u : dcc[i]) tag[u] = 1;
        }

        int ans = 0;
        rep(i, 1, n) ans += tag[i];
        cout << n - ans << endl;
    }
    return 0;
}
