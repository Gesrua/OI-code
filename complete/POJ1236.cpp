#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;

const int N = 10010;

std::vector<int> g[N];
int clr[N], dfn[N], low[N], num, cnt;
int stack[N], top = 0, ins[N];

void tarjan(int u){
    dfn[u] = low[u] = ++num;
    stack[++top] = u, ins[u] = 1;
    for(auto v : g[u]){
        if (!dfn[v]){
            tarjan(v);
            low[u] = std::min(low[u], low[v]);
        } else if (ins[v]) low[u] = std::min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u]){
        cnt++;
        int z;
        do{
            z = stack[top--], ins[z] = 0;
            clr[z] = cnt;
            // cerr << cnt << ' ' << z << endl;
        } while(z != u);
    }
}

int in_deg[N], out_deg[N];

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int n; cin >> n;
    rep(u, 1, n){
        int v;
        while(cin >> v && v) g[u].push_back(v);
    }
    rep(i, 1, n) if(!dfn[i]) tarjan(i);
    if (cnt == 1){ cout << "1\n0"; return 0; }
    rep(u, 1, n){
        for(auto v : g[u]){
            if (clr[u] != clr[v])
                out_deg[clr[u]]++, in_deg[clr[v]]++;
        }
    }
    int p = 0, q = 0;
    rep(i, 1, cnt){
        if (!in_deg[i]) ++p;
        if (!out_deg[i]) ++q;
    }
    cout << p << endl << std::max(p, q);
    return 0;
}
