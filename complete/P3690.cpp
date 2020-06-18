#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl; using std::make_pair; using std::pair;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull; typedef pair<int, int> pii; 

const int N = 1e5+10;

int fa[N], ch[N][2], s[N], c[N], tag[N];

#define is_root(u) (ch[fa[u]][0] != u && ch[fa[u]][1] != u)
#define get(u) (ch[fa[u]][1] == u)

void maintain(int u){
    s[u] = s[ch[u][0]] ^ s[ch[u][1]] ^ c[u];
}

void rotate(int u){
    int f = fa[u], ff = fa[f], chk = get(u);
    if (!is_root(f)) ch[ff][ch[ff][1] == f] = u; // is_root 判定
    ch[f][chk] = ch[u][chk^1], fa[ch[u][chk^1]] = f;
    ch[u][chk^1] = f; fa[f] = u;
    fa[u] = ff;
    maintain(f);
    maintain(u);
}

void pushdown(int u){
    if (tag[u]){
        std::swap(ch[u][0], ch[u][1]);
        tag[ch[u][0]] ^= 1;
        tag[ch[u][1]] ^= 1;
        tag[u] = 0;
    }
}

void update(int u){
    if (!is_root(u)) update(fa[u]);
    pushdown(u);
}

void splay(int u){
    update(u);
    for(int f = fa[u]; !is_root(u); rotate(u), f = fa[u]){
        if (!is_root(f)) rotate(get(f) == get(u) ? f : u);
    }
}

// 转完以后 u 并不一定在根
void access(int u){
    for(int p = 0; u; u = fa[u]){
        splay(u);
        ch[u][1] = p;
        maintain(u);
        p = u;
    }
}

void reverse(int u){ tag[u] ^= 1; }
void makeroot(int u){ access(u); splay(u); reverse(u); }
void split(int u, int v){ makeroot(u); access(v); splay(v); }
void link(int u, int v){ makeroot(v); fa[v] = u; }
void cut(int u, int v){
    split(u, v);
    if (ch[v][0] == u && !ch[ch[v][0]][1]) ch[v][0] = fa[u] = 0, maintain(v);
}

int findroot(int u){
    access(u); splay(u);
    while(1){
        pushdown(u);
        if (!ch[u][0]) break;
        u = ch[u][0];
    }
    splay(u);
    return u;
}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, m; cin >> n >> m;
    rep(i, 1, n) cin >> c[i];
    while(m--){
        int opt, u, v;
        cin >> opt >> u >> v;
        if (opt == 0){
            split(u, v);
            cout << s[v] << endl;
        } else if (opt == 1){
            if (findroot(u) != findroot(v)){
                link(u, v);
            }
        } else if (opt == 2){
            if (findroot(u) == findroot(v)){
                cut(u, v);
            }
        } else {
            access(u);
            splay(u);
            c[u] = v;
            maintain(u);
        }
    }
    return 0;
}