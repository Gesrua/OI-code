#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

std::map<std::string, int> uq;
const int N = 23, M = 1000, inf = 0x3f3f3f3f;
struct Edge {
    int u, v, w, del;
} e[M], ge[N*5];
bool cmp_w(const Edge& a, const Edge& b) { return a.w < b.w; }
bool cmp_v(const Edge& a, const Edge& b) { return a.v < b.v; }
std::vector<int> g[N];

namespace UnionFindSet {
template <int N>
struct UnionFindSet {
    int fa[N];
    UnionFindSet() {
        for (register int i = 0; i < N; ++i) fa[i] = i;
    }
    int getf(int x) { return fa[x] = (fa[x] == x ? x : getf(fa[x])); }
    inline void merge(int x, int y) { fa[getf(x)] = getf(y); }
    inline bool same(int x, int y) { return getf(x) == getf(y); }
};
};  // namespace UnionFindSet
UnionFindSet::UnionFindSet<N> ufs;

int tag[N], connect[N], mx;
int dfs(int u, int fa){
    if (connect[u]) return 0;
    for(auto i : g[u]){
        if(ge[i].del || ge[i].v == fa) continue;
        int x = dfs(ge[i].v, u);
        if (x == -1) continue;
        if (ge[i].w > x) mx = i;
        return std::max(ge[i].w, x);
    }
    return -1;
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0);
    cout.tie(0);
    int m, tot = 0;
    cin >> m;
    uq["Park"] = ++tot;
    std::string s1, s2;
    int u, v, w;
    rep(i, 1, m) {
        cin >> s1 >> s2 >> w;
        if (uq.count(s1)) u = uq[s1];
        else u = uq[s1] = ++tot;
        if (uq.count(s2)) v = uq[s2];
        else v = uq[s2] = ++tot;
        e[i].u = u, e[i].v = v, e[i].w = w;
    }
    std::sort(e + 1, e + 1 + m, cmp_w);
    // rep(i, 1, m){ cerr << e[i].u << ' ' << e[i].v << ' ' << e[i].w << endl; }
    int ans = 0, gec = 0;
    rep(i, 1, m) {
        int& u = e[i].u;
        int& v = e[i].v;
        if (u == 1 || v == 1) continue;
        if (!ufs.same(u, v)) {
            ufs.merge(u, v);
            ge[gec].v = v, ge[gec].w = e[i].w, g[u].push_back(gec++); 
            ge[gec].v = u, ge[gec].w = e[i].w, g[v].push_back(gec++); 
            // cerr << "addedge " << u << ' ' << v << ' ' << w << endl;
            // g[u].push_back({v, e[i].w}), g[v].push_back({u, e[i].w});
            ans += e[i].w;
        }
    }
    // rep(i, 1, tot) cerr << ufs.getf(i) << ' '; cerr << endl;
    std::vector<int> blk;
    std::vector<Edge> ne;
    rep(i, 1, m) {
        int& u = e[i].u;
        int& v = e[i].v;
        if (u != 1 && v != 1) continue;
        if (v == 1) std::swap(u, v);
        ne.push_back(e[i]);
        if (!tag[ufs.getf(v)]) blk.push_back(ufs.getf(v)), tag[ufs.getf(v)] = 1;
    }
    // for(auto i : blk){ cerr << i << ' '; } cerr << endl;
    std::sort(ne.begin(), ne.end(), cmp_v);
    int cnt = blk.size(), s;
    cin >> s;
    if (cnt > s) return -1;
    for (int i = 0; i < ne.size();) {
        // cerr << i << endl;
        int j = i;
        int mi = j;
        for (++j; j < ne.size() && ufs.getf(ne[j].v) == ufs.getf(ne[i].v); ++j)
            if (ne[j].w < ne[mi].w) mi = j;
        ans += ne[mi].w;
        connect[ne[mi].v] = 1;
        i = j;
    }
    // cerr << ans << endl;

    s -= cnt;
    while (s--) {
        int delta = 0, del, p;
        for (int i = 0; i < ne.size(); ++i) {
            if (connect[ne[i].v]) continue;
            int x = dfs(ne[i].v, 0);
            // cerr << ne[i].v << ' ' << ne[i].w << ' ' << x << endl;
            if (ne[i].w - x < delta){
                delta = ne[i].w - x, del = mx, p = ne[i].v;
            }
        }
        // cerr << delta << endl;
        if (delta >= 0) break;
        ans += delta;
        // assert(ge[del].del == 0);
        ge[del].del = ge[del^1].del = 1; connect[p] = 1;
        // cerr << del << ' ' << ge[del].w << ' ' << ge[del^1].w << endl;
    }
    cout << "Total miles driven: " << ans;

    // cerr << ans << ' ' << s << endl;
    return 0;
}
