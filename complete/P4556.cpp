#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl; using std::make_pair; using std::pair;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull; typedef pair<int, int> pii; 

const int N = 100100, M = 100100, V = 100000;

int n, m;
std::vector<int> g[N];
int fa[20][N], dep[N], val[N];

void dfs(int u){
    dep[u] = dep[fa[0][u]] + 1;
    for(auto v : g[u]){
        if (v == fa[0][u]) continue;
        fa[0][v] = u;
        dfs(v);
    }
}

int lca(int u, int v){
    if (dep[u] < dep[v]) std::swap(u, v);
    int delta = dep[u] - dep[v];
    for(int i = 0; i <= 19; ++i) if (delta&(1<<i)) u = fa[i][u];
    // cerr << "lca " << u << ' ' << v << endl;
    if (u == v) return u;
    for(int i = 19; i >= 0; --i) if (fa[i][u] != fa[i][v]) u = fa[i][u], v = fa[i][v];
    return fa[0][u];
}

int tot = 0;
struct Node{
    int mx, l, r, ans;
    Node* ch[2];
} T[N*67];

void maintain(Node* o){
    int x = o->ch[0] ? o->ch[0]->mx : 0,  y = o->ch[1] ? o->ch[1]->mx : 0;
    o->mx = std::max(o->ch[0] ? o->ch[0]->mx : 0, o->ch[1] ? o->ch[1]->mx : 0);
    if (std::max(x, y) <= 0) o->ans = 0;
    else if (x >= y) o->ans = (o->ch[0] ? o->ch[0]->ans : 0);
    else o->ans = (o->ch[1] ? o->ch[1]->ans : 0);
}

Node* nn(int l, int r){
    T[tot].l = l, T[tot].r = r, T[tot].mx = 0;
    T[tot].ans = l;
    return &T[tot++];
}

void insert(Node* &o, int z, int d, int l, int r){
    if (o == nullptr) o = nn(l, r);
    if (o->l == o->r && o->l == z) return (void) (o->mx += d);
    int mid = (l + r) / 2;
    if (z <= mid) insert(o->ch[0], z, d, l, mid);
    else insert(o->ch[1], z, d, mid+1, r);
    maintain(o);
}

Node* merge(Node* a, Node* b){
    if (a == nullptr) return b; if (b == nullptr) return a;
    if (a->l == a->r){ a->mx += b->mx; return a; }
    a->ch[0] = merge(a->ch[0], b->ch[0]);
    a->ch[1] = merge(a->ch[1], b->ch[1]);
    maintain(a);
    return a;
}

int ans[N]; Node* rt[N];

void print(Node* u){
    if (u == nullptr) return;
    if (u->l == u->r){
        cerr << u->l << ' ' << u->ans << ' ' << u->mx << endl;
        return;
    }
    cerr << "QAQ " << u->l << ' ' << u->r << endl;
    print(u->ch[0]); 
    cerr << "QWQ " << u->l << ' ' << u->r << endl;
    print(u->ch[1]);
}

void calc(int u){
    // cerr << "pre " << u << endl;
    // print(rt[u]);
    // cerr << "---------" << endl;
    for(auto v : g[u]){
        if (v == fa[0][u]) continue;
        calc(v);
        // cerr << "merge" << endl;
        rt[u] = merge(rt[u], rt[v]);
        // cerr << "merged" << endl;
    }
    // if (u != 33) return;
    // cerr << u << endl;
    // print(rt[u]);
    // cerr << "----------" << endl;
    ans[u] = rt[u] ? rt[u]->ans : 0;
}


int main() {
    // freopen("input", "r", stdin);
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n >> m;
    rep(i, 2, n){
        int u, v; cin >> u >> v; g[u].push_back(v); g[v].push_back(u);
    }
    dfs(1);
    for(int k = 1; k <= 19; ++k) for(int i = 1; i <= n; ++i) fa[k][i] = fa[k-1][fa[k-1][i]];
    // cerr << "QAQ" << endl;
    while(m--){
        int x, y, z, l;
        cin >> x >> y >> z; l = lca(x, y);
        // cerr << x << ' ' << y << ' ' << l << endl;
        insert(rt[x], z, 1, 1, V);
        insert(rt[y], z, 1, 1, V);
        insert(rt[l], z, -1, 1, V);
        insert(rt[fa[0][l]], z, -1, 1, V);
    }
    // cerr << "QAQ" << endl;
    calc(1);
    rep(i, 1, n){
        cout << ans[i] << '\n';
    }
    return 0;
}