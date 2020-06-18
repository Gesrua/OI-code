#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl; using std::make_pair; using std::pair;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull; typedef pair<int, int> pii; 

const int N = 1e5+10, inf = 1e8;

std::vector<int> gra[N];

int n;

int fa[N], top[N], dfn[N], siz[N], dep[N], dfnt, son[N], end[N];
void dfs1(int u){
    dep[u] = dep[fa[u]] + 1;
    siz[u] = 1;
    for(auto v : gra[u]){
        if (v == fa[u]) continue;
        fa[v] = u; dfs1(v);
        siz[u] += siz[v];
        if (siz[son[u]] < siz[v]) son[u] = v;
    }
}


struct Mat{
    int a[2][2];
    Mat operator*(const Mat& rhs){
        Mat ret = {a:{{-inf, -inf}, {-inf, -inf}}};
        rep(i, 0, 1)
            rep(j, 0, 1)
                rep(k, 0, 1)
                    ret.a[i][j] = std::max(ret.a[i][j], a[i][k]+rhs.a[k][j]);
        return ret;
    }
};

const Mat one{a:{{0, -inf}, {-inf, 0}}};

struct Seg{
    Mat d[N*4];
    Mat query(int u, int l, int r, int L, int R){
        if (r < L || R < l || L > R) return one;
        if (L <= l && r <= R) return d[u];
        int mid = (l+r)/2;
        return query(u<<1, l, mid, L, R) * query((u<<1)|1, mid+1, r, L, R);
    }
    void modify(int u, int l, int r, int P, const Mat& X){
        if (l == r){ d[u] = X; return; }
        int mid = (l+r)/2;
        if (P <= mid) modify(u<<1, l, mid, P, X);
        else modify((u<<1)|1, mid+1, r, P, X);
        d[u] = d[u<<1] * d[(u<<1)|1];
    }
} seg;

int f[N][2], g[N][2], c[N];

void update_seg(int u){
    if (u <= 0) return;
    seg.modify(1, 1, n, dfn[u], Mat{a:{{-inf, g[u][1]},{g[u][0], g[u][0]}}});
}

void dfs2(int u){
    dfn[u] = ++dfnt;
    if (!top[u]) top[u] = u, end[u] = u;
    if (son[u]){ top[son[u]] = top[u]; end[top[u]] = son[u]; dfs2(son[u]); }
    g[u][1] = c[u];
    for(auto v : gra[u]){
        if (v == fa[u] || v == son[u]) continue;
        dfs2(v);
        g[u][0] += std::max(f[v][0], f[v][1]);
        g[u][1] += f[v][0];
    }
    f[u][1] = g[u][1], f[u][0] = g[u][0]; 
    if (son[u]){
        f[u][1] += f[son[u]][0];
        f[u][0] += std::max(f[son[u]][0], f[son[u]][1]);
    }
    update_seg(u);
}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int m; cin >> n >> m;
    rep(i, 1, n) cin >> c[i];
    rep(i, 2, n){
        int u, v; cin >> u >> v;
        gra[u].push_back(v); gra[v].push_back(u);
    }
    dfs1(1); dfs2(1);
    cerr << std::max(f[1][0], f[1][1]) << endl;
    while(m--){
        int u, x; cin >> u >> x;
        g[u][1] = g[u][1] - c[u] + x;
        c[u] = x;
        for(; u; u = fa[top[u]]){
            update_seg(u);
            Mat q = seg.query(1, 1, n, dfn[top[u]], dfn[fa[end[top[u]]]]);
            g[fa[top[u]]][1] -= f[top[u]][0];
            g[fa[top[u]]][0] -= std::max(f[top[u]][0], f[top[u]][1]);

            f[top[u]][1] = std::max(q.a[0][0] + c[end[top[u]]], q.a[0][1] + 0);
            f[top[u]][0] = std::max(q.a[1][0] + c[end[top[u]]], q.a[1][1] + 0);

            g[fa[top[u]]][1] += f[top[u]][0];
            g[fa[top[u]]][0] += std::max(f[top[u]][0], f[top[u]][1]);
        }
        cout << std::max(f[1][0], f[1][1]) << endl;
    }
    return 0;
}