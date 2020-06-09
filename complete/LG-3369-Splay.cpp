#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl; using std::make_pair; using std::pair;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull; typedef pair<int, int> pii; 

const int N = 100010;
int rt, ch[N][2], fa[N], sz[N], cnt[N], tot, val[N];

struct Splay{
    void maintain(int x){ sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + cnt[x]; }
    int get(int x){ return ch[fa[x]][1] == x;}
    void link(int f, int son, int chk){
        ch[f][chk] = son, fa[son] = f;
        maintain(f);
    }
    void rotate(int x){
        int y = fa[x], z = fa[y], chk = get(x);
        link(y, ch[x][chk^1], chk);
        link(x, y, chk^1);
        if (z) ch[z][ch[z][1] == y] = x;
        fa[x] = z;
    }
    void splay(int x){
        for(int f = fa[x]; f; rotate(x), f = fa[x])
            if (fa[f]) rotate(get(x) == get(f) ? f : x);
        rt = x;
    }
    void ins(int x){
        if (!rt) { rt = ++tot; cnt[rt] = 1, val[rt] = x; maintain(rt); return; }
        int cnr = rt, f = 0;
        while(1){
            if (val[cnr] == x){ cnt[cnr]++; maintain(cnr); splay(cnr); return; }
            f = cnr; cnr = ch[cnr][x > val[cnr]];
            if (!cnr){
                cnr = ++tot;
                cnt[cnr] = 1, val[cnr] = x; maintain(cnr);
                fa[cnr] = f; ch[f][x > val[f]] = cnr;
                splay(cnr);
                return;
            }
        }
    }
    int kth(int k){
        int cnr = rt;
        while(1){
            if (k <= sz[ch[cnr][0]]){ cnr = ch[cnr][0]; continue; }
            k -= sz[ch[cnr][0]] + cnt[cnr];
            if (k <= 0) { splay(cnr); return val[cnr]; }
            cnr = ch[cnr][1];
        }
    }
    int rk(int x){
        int cnr = rt, res = 0;
        while(1){
            if (x < val[cnr]){ cnr = ch[cnr][0]; continue; }
            res += sz[ch[cnr][0]];
            if (x == val[cnr]){ splay(cnr); return res+1; }
            res += cnt[cnr];
            cnr = ch[cnr][1];
        }
    }
    int pre(){
        int cnr = ch[rt][0];
        for(; ch[cnr][1]; cnr = ch[cnr][1]);
        splay(cnr);
        return cnr;
    }
    int nxt(){
        int cnr = ch[rt][1];
        for(; ch[cnr][0]; cnr = ch[cnr][0]);
        splay(cnr);
        return cnr;
    }
    void del(int x){
        rk(x); int d = rt;
        if (cnt[rt] > 1) { cnt[rt]--; maintain(rt); return; }
        if (!ch[rt][0] && !ch[rt][1]){ rt = 0; return; }
        if (!ch[rt][0]){ rt = ch[rt][1]; fa[rt] = 0; return; }
        if (!ch[rt][1]){ rt = ch[rt][0]; fa[rt] = 0; return; }
        pre();
        link(rt, ch[d][1], 1);
    }
} tree;

int main() {
    // freopen("input", "r", stdin);
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n; cin >> n;
    while(n--){
        int opt, x; cin >> opt >> x;
        if (opt == 1) tree.ins(x);
        else if (opt == 2) tree.del(x);
        else if (opt == 3) cout << tree.rk(x) << '\n';
        else if (opt == 4) cout << tree.kth(x) << '\n';
        else {
            tree.ins(x);
            cout << val[opt == 5 ? tree.pre() : tree.nxt()] << '\n';
            tree.del(x);
        }
    }
    return 0;
}