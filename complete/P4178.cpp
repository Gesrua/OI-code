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
#include <stack>
#define rep(i, l, r) for (register int i = (l); i <= (r); ++i)
#define per(i, l, r) for (register int i = (l); i >= (r); --i)
using std::cin; using std::cout; using std::cerr; using std::endl;
using std::make_pair; using std::pair;
typedef pair< int, int > pii;

const int N = 40010;

int n, k;

struct edge{
    int v, w;
    edge* nxt;
};
struct node{
    edge* first;
    bool solved;
};
struct graph{
    edge e[N*2];
    node p[N];
    int tot;
    graph(){
        tot = 0;
    }
    inline void _addedge(int u, int v, int w){
        e[tot].v = v, e[tot].w = w, e[tot].nxt = p[u].first, p[u].first = &e[tot++];
    }
    inline void addedge(int u, int v, int w){
        _addedge(u, v, w);
        _addedge(v, u, w);
    }
}g;

#define travel(i, u) for (edge* i = g.p[u].first; i != NULL; i = i->nxt)

void init(){
    // cin >> n >> k;
    cin >> n;
    rep(i, 1, n-1){
        int u, v, w;
        cin >> u >> v >> w;
        g.addedge(u, v, w);
    }
    cin >> k;
    // rep(i, 1, n){
    //     cout << i << " : ";
    //     travel(j, i)
    //         cout << j->v << ' ';
    //     cout << endl;
    // }
}

struct array{
    int a[N], tot;
    array(){
        tot = 0;
    }
    void push_back(int x){
        a[tot++] = x;
    }
    void pop_back(int x){
        --tot;
    }
    int& operator[](int x){
        return a[x];
    }
    int* begin(){
        return a;
    }
    int* end(){
        return a+tot;
    }
    void clear(){
        tot = 0;
    }
    int size(){
        return tot;
    }
}s;

int SIZE, grav, max_grav;
long long ans = 0;

int dfs1(int fa, int x){
    int tot = 1, max = 0;
    travel(i, x){
        if (g.p[i->v].solved || i->v == fa) continue;
        int t = dfs1(x, i->v);
        max = std::max(max, t);
        tot += t;
    }
    max = std::max(max, SIZE-tot);
    // cerr << x << ' ' << max << endl;
    if (max <= max_grav) grav = x, max_grav = max;
    return tot;
}

void dfs2(int fa, int x, int dep){
    travel(i, x){
        if (g.p[i->v].solved || i->v == fa) continue;
        s.push_back(dep+i->w);
        dfs2(x, i->v, dep+i->w);
    }
}

int calc(int x, int dep){
    s.clear();
    s.push_back(dep);
    dfs2(0, x, dep);
    std::sort(s.begin(), s.end());
    // if (x == 6 && dep == 0){
    //     rep (i, 0, s.size()-1)
    //         cout << s[i] << ' ';
    //     cout << endl;
    // }
    int ret = 0, i = 0, j = s.size()-1;
    while (i < j){
        while (s[j] > k-s[i]) --j;
        if (i < j) ret += j-i;
        ++i;
    }
    return ret;
}

void solve(int x, int size);

void work(int x){
    int ret = calc(x, 0);
    g.p[x].solved = 1;
    // cerr << "root = " << x << " ret = " << ret << endl;
    travel(i, x){
        if (g.p[i->v].solved) continue;
        // int t = calc(i->v, i->w);
        // if (x == 2){
        //     cout << "calc " << t << ' ' << i->v << ' '<< endl;
        // }
        // ret -= t;
        ret -= calc(i->v, i->w);
        // cerr << i->v << ' ' << s.size() << endl;
        solve(i->v, s.size());
    }
    // cerr << "root = " << x << " ret = " << ret << endl;
    ans += ret;
}

void solve(int x, int size){
    SIZE = size;
    grav = x;
    max_grav = size-1;
    dfs1(0, x);
    // cerr << "g = " << grav << endl;
    work(grav);
}

int main(){
    // freopen("input", "r", stdin);
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    init();
    solve(1, n);
    cout << ans;
    return 0;
}