#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl; using std::make_pair; using std::pair;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull; typedef pair<int, int> pii; 

const int N = 100010;

std::vector<int> g[N];
int dep[N], son[N], top[N], fa[N], dfn[N], dfnt, rev[N], siz[N];

void dfs1(int u){
    dep[u] = dep[fa[u]] + 1;
    siz[u] = 1;
    for(auto v : g[u]){
        if (v == fa[u]) continue;
        fa[v] = u; dfs1(v);
        siz[u] += siz[v];
        if (siz[son[u]] < siz[v]) son[u] = v;
    }
}

void dfs2(int u){
    dfn[u] = ++dfnt; rev[dfn[u]] = u;
    if (!top[u]) top[u] = u;
    if (son[u]){
        top[son[u]] = top[u];
        dfs2(son[u]);
    }
    for(auto v : g[u]){
        if (v == fa[u] || v == son[u]) continue;
        dfs2(v);
    }
}

int lca(int u, int v){
    while(top[u] != top[v]){
        if (dep[top[u]] < dep[top[v]]) v = fa[top[v]];
        else u = fa[top[u]];
    }
    return dep[u] < dep[v] ? u : v;
}
int dis(int u, int v){
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

int tot = 0;
struct Node{
    int l, r, len, left, right, cnt;
    Node *ls, *rs;
} T[N*100];
void maintain(Node* u){
    if (u->ls == nullptr && u->rs == nullptr) return;
    if (u->ls == nullptr) return (void) (u->left = u->rs->left, u->right = u->rs->right, u->len = u->rs->len);
    if (u->rs == nullptr) return (void) (u->left = u->ls->left, u->right = u->ls->right, u->len = u->ls->len);
    if (u->ls->left == 0) return (void) (u->left = u->rs->left, u->right = u->rs->right, u->len = u->rs->len);
    if (u->rs->left == 0) return (void) (u->left = u->ls->left, u->right = u->ls->right, u->len = u->ls->len);
    u->left = u->ls->left; u->right = u->rs->right;
    u->len = u->ls->len + u->rs->len + dis(rev[u->ls->right], rev[u->rs->left]);
}
void insert(Node* &u, int z, int d, int l, int r){
    if (!u){ u = &T[++tot]; u->l = l, u->r = r; }
    if (l == r){
        u->cnt += d;
        if (u->cnt >= 1) u->left = u->right = l, u->len = 0;
        else u->left = u->right = u->len = 0;
        return;
    }
    int mid = (l+r)/2;
    if (z <= mid) insert(u->ls, z, d, l, mid);
    else insert(u->rs, z, d, mid+1, r);
    maintain(u);
}
Node* merge(Node* a, Node* b){
    if (a == nullptr) return b; if (b == nullptr) return a;
    if (a->l == a->r){
        a->cnt += b->cnt;
        if (a->cnt >= 1) a->left = a->right = a->l, a->len = 0;
        else a->left = a->right = a->len = 0;
        return a;
    }
    a->ls = merge(a->ls, b->ls);
    a->rs = merge(a->rs, b->rs);
    maintain(a);
    return a;
}
Node* rt[N];

void print(Node* u){
    if (!u) return;
    if (u->l == u->r){
        cerr << "rev " << rev[u->l] << ' ' << u->left << ' ' << u->cnt << endl;
        return;
    } else {
        cerr << "d " << u->l << ' ' << u->r << endl;
        cerr << rev[u->left] << ' ' << rev[u->right] << ' ' << u->len << endl;
    }
    print(u->ls); print(u->rs);
}

int ans[N]; ll r = 0;
void calc(int u){
    for (auto v : g[u]){
        if (v == fa[u]) continue;
        calc(v);
        rt[u] = merge(rt[u], rt[v]);
    }
    if (rt[u] && rt[u]->left)
        ans[u] = (rt[u]->len + dis(rev[rt[u]->left], rev[rt[u]->right])) / 2;
    else
        ans[u] = 0;
    assert(ans[u] >= 0);
    r += ans[u];
}

int main() {
    // freopen("input", "r", stdin);
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, m; cin >> n >> m;
    rep(i, 2, n){
        int u, v; cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }
    dfs1(1); dfs2(1);
    while(m--){
        int u, v, l; cin >> u >> v; l = lca(u, v);
        insert(rt[u], dfn[u], 1, 1, n); insert(rt[u], dfn[v], 1, 1, n);
        insert(rt[v], dfn[u], 1, 1, n); insert(rt[v], dfn[v], 1, 1, n);
        insert(rt[l], dfn[u], -1, 1, n); insert(rt[l], dfn[v], -1, 1, n);
        insert(rt[fa[l]], dfn[u], -1, 1, n); insert(rt[fa[l]], dfn[v], -1, 1, n);
    }
    calc(1);
    cout << r/2 << endl;
    return 0;
}