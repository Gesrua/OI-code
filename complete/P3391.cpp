#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl; using std::make_pair; using std::pair;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull; typedef pair<int, int> pii; 

const int N = 100010;
int rt, ch[N][2], fa[N], tot, val[N], tag[N], siz[N], n;

struct Splay{
    void maintain(int x){ siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + 1; }
    void pushdown(int x){
        if (tag[x]){
            std::swap(ch[x][0], ch[x][1]);
            tag[x] = 0;
            tag[ch[x][0]] ^=1;
            tag[ch[x][1]] ^= 1;
            tag[0] = 0;
        }
    }
    int get(int x){ return ch[fa[x]][1] == x;}
    void link(int f, int son, int chk){
        ch[f][chk] = son, fa[son] = f;
        maintain(f);
    }
    int build(int l, int r, int f = 0){
        if (l > r) return 0;
        int mid = (l+r)/2, cnr = ++tot;
        fa[cnr] = f; val[cnr] = mid;
        if (f == 0) rt = cnr;
        ch[cnr][0] = build(l, mid-1, cnr);
        ch[cnr][1] = build(mid+1, r, cnr);
        maintain(cnr);
        return cnr;
    }
    void rotate(int x){
        int y = fa[x], z = fa[y], chk = get(x);
        link(y, ch[x][chk^1], chk);
        link(x, y, chk^1);
        if (z) ch[z][ch[z][1] == y] = x;
        fa[x] = z;
    }
    // 成为 goal 的儿子
    void splay(int x, int goal = 0){
        for(int f = fa[x]; f != goal; rotate(x), f = fa[x])
            if (fa[f] != goal) rotate(get(x) == get(f) ? f : x);
        // rt = x;
        if (goal == 0) rt = x;
    }
    int kth(int k){
        int cnr = rt;
        while(1){
            pushdown(cnr);
            if (k <= siz[ch[cnr][0]]){ cnr = ch[cnr][0]; continue; }
            k -= siz[ch[cnr][0]] + 1;
            if (k <= 0) { splay(cnr); return cnr; }
            cnr = ch[cnr][1];
        }
    }
    void rev(int l, int r){
        l = kth(l-1);
        r = kth(r+1);
        // cerr << val[l] << ' ' << val[r] << endl;
        splay(l, 0);
        // cerr << "first splay" << endl;
        splay(r, l);
        // cerr << "rt and right " << val[rt] << ' ' << val[ch[rt][1]] << endl;
        // cerr << "tag" << val[ch[ch[rt][1]][0]] << endl;
        tag[ch[ch[rt][1]][0]] ^= 1;
    }
    void print(int x){
        if (x == 0) return;
        pushdown(x);
        print(ch[x][0]);
        // cout << val[x] << ' ';
        if (val[x] != 0 && val[x] != n+1) cout << val[x] << ' ';
        print(ch[x][1]);
    }
} tree;

int main() {
    // freopen("input", "r", stdin);
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int m; cin >> n >> m;
    tree.build(0, n+1);
    // tree.print(rt); cout << endl;
    // cerr << "QAQ" << endl;
    while(m--){
        int l, r; cin >> l >> r;
        tree.rev(l+1, r+1);
        // tree.print(rt); cout << endl;
        // cerr << "Over" << endl;
    }
    tree.print(rt);
    return 0;
}