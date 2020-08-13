#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl; using std::make_pair; using std::pair;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull; typedef pair<int, int> pii; 

const int N = 1.5e5, M = 1e5+10;

int tr[N][26], pos[N], fail[N], fa[N], tot = 1, dfn[N], sz[N]; int dfn_tag = 0;
std::vector<int> g[N];
struct Q{ int id, x; };
std::vector<Q> query[N]; int ans[M];

void build(){
    std::queue<int> q;
    rep(c, 0, 25) if (tr[0][c]) q.push(tr[0][c]);
    while(q.size()){
        int u = q.front(); q.pop();
        rep(c, 0, 25)
            if (tr[u][c]){
                fail[tr[u][c]] = tr[fail[u]][c];
                q.push(tr[u][c]);
            } else {
                tr[u][c] = tr[fail[u]][c];
            }
    }
    rep(u, 1, tot-1) g[fail[u]].push_back(u);
}

char s[N];

struct BIT{
    int c[N], n;
    void add(int i, int x){
        // cout << "add " << i << ' ' << x << endl;
        for(; i <= n; i += (i&(-i))) c[i] += x;
    }
    int query(int i){
        int ret = 0;
        for(; i >= 1; i -= (i&(-i))) ret += c[i];
        return ret;
    }
    int query(int l, int r){
        return query(r) - query(l-1);
    }
} bit;

void dfs_fail(int u){
    sz[u] = 1;
    dfn[u] = ++dfn_tag;
    for(auto v : g[u]){
        dfs_fail(v);
        sz[u] += sz[v];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> s;
    int u = 0; int n = 0;
    for(int i = 0; s[i]; ++i){
        if (s[i] == 'P'){
            pos[++n] = u;
        } else if (s[i] == 'B'){
            u = fa[u];
        } else {
            char c = s[i] - 'a';
            if (!tr[u][c]) tr[u][c] = tot++, fa[tr[u][c]] = u;
            u = tr[u][c];
        }
    }
    bit.n = tot;
    build();
    int m; cin >> m;
    rep(i, 1, m){
        int x, y;
        cin >> x >> y;
        query[y].push_back({i, x});
    }

    dfs_fail(0); n = 0;

    u = 0;
    for(int i = 0; s[i]; ++i){
        if (s[i] == 'P'){
            ++n;
            for(auto qwq : query[n]){
                int id = qwq.id, x = qwq.x;
                // cerr << dfn[pos[x]] << ' ' << dfn[pos[x]] - 1 + sz[pos[x]] << endl;
                ans[id] = bit.query(dfn[pos[x]], dfn[pos[x]] - 1 + sz[pos[x]]);
            }
        } else if (s[i] == 'B'){
            bit.add(dfn[u], -1);
            u = fa[u];
        } else {
            char c = s[i] - 'a';
            u = tr[u][c];
            bit.add(dfn[u], 1);
        }
    }

    rep(i, 1, m) cout << ans[i] << endl;
    return 0;
}