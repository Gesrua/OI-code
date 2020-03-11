#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;
const int N = 1100, p = 1e9+7;
typedef long long ll;
#define add(x, y) (x+y>=p?x+y-p:x+y)
struct FHQ_Treap {
    struct Node{
        int x; ll y, sum; int rnd;
        Node *ls, *rs;
        void maintain(){ sum = ((ls?ls->sum:0)+(rs?rs->sum:0)+y)%p; }
    } T[N], *root; int tot = 0;
    Node* New(int x, ll y){ T[tot].x = x, T[tot].y = y, T[tot].sum = y, T[tot].ls = T[tot].rs = nullptr, T[tot].rnd = rand(); return &T[tot++]; }
    void init(){ tot = 0, root = nullptr; }
    typedef std::pair<Node*, Node*> pnn;
    Node* merge(Node* u, Node* v){
        if (u == nullptr) return v;
        if (v == nullptr) return u;
        if (u->rnd > v->rnd){
            u->rs = merge(u->rs, v); u->maintain();
            return u;
        } else {
            v->ls = merge(u, v->ls); v->maintain();
            return v;
        }
    }
    pnn split(Node* u, int key){
        if (u == nullptr) return {nullptr, nullptr};
        if (u->x < key){
            auto o = split(u->rs, key);
            u->rs = o.first; u->maintain();
            return {u, o.second};
        } else {
            auto o = split(u->ls, key);
            u->ls = o.second; u->maintain();
            return {o.first, u};
        }
    }
    void insert(int x, ll y){
        auto o = split(root, x);
        root = merge(o.first, merge(New(x, y), o.second));
    }
    ll query(int x){
        auto o = split(root, x);
        ll ret = o.first?o.first->sum:0;
        merge(o.first, o.second);
        return ret;
    }
} bst;

ll f[N][N];
int a[N];

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false); cout.tie(0);
    srand((unsigned int)time(nullptr));
    // bst.init();
    // int opt;
    // while(cin >> opt){
    //     int x, y;
    //     if (opt == 1){
    //         cin >> x >> y;
    //         bst.insert(x, y);
    //     } else {
    //         cin >> x;
    //         cout << bst.query(x) << endl;
    //     }
    // }
    int T;
    cin >> T;
    rep(kase, 1, T){
        int n, m; std::memset(f, 0, sizeof(f));
        cin >> n >> m;
        a[0] = -1e9-1;
        rep(i, 1, n) cin >> a[i];
        f[0][0] = 1;
        rep(i, 1, m){
            bst.init();
            rep(j, 0, n){
                f[i&1][j] = bst.query(a[j]);
                // cerr << f[i&1][j] << ' ';
                bst.insert(a[j], f[(i-1)&1][j]);
            }
            // cerr << endl;
            // f[(i+1)&1][0] = 0;
        }
        ll ret = 0;
        rep(i, 1, n) ret = add(ret, f[m&1][i]);
        cout << "Case #"<<kase<<": " << ret << endl;
    }
    return 0;
}