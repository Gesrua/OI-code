#include <cstdio>
#include <iostream>
#include <utility>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#define rep(i, l, r) for (register int i = (l); i <= (r); ++i)
#define per(i, l, r) for (register int i = (l); i >= (r); --i)
using std::cin; using std::cout; using std::cerr; using std::endl;
using std::make_pair; using std::pair;
typedef pair< int, int > pii;
struct edge{
    int v, w;
    edge* nxt;
    edge(int _v, int _w, edge* _nxt){ v = _v, w = _w, nxt = _nxt;};
    edge() {nxt = nullptr;}
    inline void set(int _v, int _w, edge* _nxt){ v = _v, w = _w, nxt = _nxt;};    
}e[10000];
int tot = 0;
bool layer[2][109];
edge* p[109];
inline void addedge(int u, int v, int w){
    e[tot].set(v, w, p[u]);
    p[u] = &e[tot++];
}
int main(){
    std::memset(layer[0], 1, sizeof(layer[0]));
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, m, c[109], gate[109];
    cin >> n >> m;
    rep(i, 1, n){
        cin >> c[i] >> gate[i];
        c[i] -= gate[i];
    }
    rep(i, 1, m){
        int u, v, w;
        cin >> u >> v >> w;
        addedge(u, v, w);
        layer[0][v] = false;
    }
    rep (i, 1, n)
        if(layer[0][i]) c[i] += gate[i];
    // cerr << "read over\n";
    int cur = 0, nxt = 1;
    bool flag = true;
    while(1){
        flag = false;
        std::memset(layer[nxt], 0, sizeof(layer[nxt]));
        rep(u, 1, n){
            if (!layer[cur][u]) continue;
            if (c[u] <= 0) c[u] = 0;
            for (edge* i = p[u]; i != nullptr; i = i->nxt){
                c[i->v] += c[u]*i->w;
                flag = true;
                layer[nxt][i->v] = true;
            }
        }
        if (flag == false) break;
        std::swap(cur, nxt);
    }
    flag = true;
    rep(i, 1, n){
        if (layer[cur][i]){
            if (c[i] > 0){
                cout << i << ' ' << c[i] << endl;
                flag = false;
            }
        }
    }
    if (flag) cout << "NULL";
    return 0;
}