#include <algorithm>
#include <iostream>
#define rep(i, l, r) for (register int i = (l); i <= (r); ++(i))
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
struct edge {
    int u, v, w;
} e[20000];
int fa[200];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
inline void unite(int x, int y) { fa[find(x)] = find(y); }
bool operator<(const edge a, const edge b) { return a.w < b.w; }
int main() {
    int n, x, tot = 0;
    cin >> n;
    rep(i, 1, n) fa[i] = i;
    rep(i, 1, n) rep(j, 1, n) {
        cin >> x;
        if (x != 0) {
            e[tot].u = i, e[tot].v = j, e[tot].w = x;
            ++tot;
        }
    }
    long long sum = 0;
    std::sort(e, e + tot);
    rep(i, 1, tot - 1) {
        if (find(e[i].u) != find(e[i].v)) {
            sum += e[i].w;
            unite(e[i].u, e[i].v);
        }
    }
    cout << sum;
    return 0;
}