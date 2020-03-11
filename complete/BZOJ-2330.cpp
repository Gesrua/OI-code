#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;

const int N = 100010, M = 200010;

struct Edge{
    int u, v, w; Edge* nxt;
} e[M]; int tot; Edge* p[N];
inline void addedge(int u, int v, int w){
    e[tot].u = u, e[tot].v = v, e[tot].w = w, e[tot].nxt = p[u], p[u] = &e[tot++];
}

int dfn[N], low[N], clr[N], num = 0, stack[N], top = 0, cnt = 0, ins[N], siz[N];
void tarjan(int u){
    dfn[u] = low[u] = ++num;
    stack[++top] = u, ins[u] = 1;
    for(auto i = p[u]; i; i = i->nxt){
        if (!dfn[i->v]){
            tarjan(i->v);
            low[u] = std::min(low[u], low[i->v]);
        } else if (ins[i->v]) low[u] = std::min(low[u], dfn[i->v]);
    }
    if (dfn[u] == low[u]){
        ++cnt; int z;
        do{
            z = stack[top--], ins[z] = 0;
            clr[z] = cnt;
            siz[cnt]++;
        } while(z != u);
    }
}

std::vector<pii> g[N]; int deg[N];
int d[N];

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    rep(i, 1, m){
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) addedge(a, b, 0), addedge(b, a, 0);
        else if (t == 2) addedge(a, b, 1);
        else if (t == 3) addedge(b, a, 0);
        else if (t == 4) addedge(b, a, 1);
        else addedge(a, b, 0);
    }
    // rep(u, 1, n)
        // for(auto i = p[u]; i; i = i->nxt) cout << u << " -> " << i->v << ' ' << i->w << endl;
    rep(i, 1, n) if (!dfn[i]) tarjan(i);
    for(int i = 0; i < tot; ++i)
        if (clr[e[i].u] == clr[e[i].v]){
            if (e[i].w > 0){
                cout << -1;
                return 0;
            }
        } else {
            g[clr[e[i].u]].push_back({clr[e[i].v], e[i].w});
            deg[clr[e[i].v]]++;
        }

    std::queue<int> q;
    rep(i, 1, cnt) if(deg[i] == 0) q.push(i), d[i] = 1;
    while(q.size()){
        int u = q.front(); q.pop();
        for(auto i : g[u]){
            int v = i.first, w = i.second;
            --deg[v];
            d[v] = std::max(d[v], d[u] + w);
            if (deg[v] == 0) q.push(v);
        }
    }
    ll ans = 0;
    rep(i, 1, cnt)
        ans += (ll)siz[i] * d[i];
    cout << ans;
    return 0;
}
