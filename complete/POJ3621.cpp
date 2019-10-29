#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;
const int N = 1010, M = 5050;
struct Edge{
    int t, v;
    double w;
} e[M];
std::vector<Edge*> p[N];
int n, f[N], c[N];
double d[N];
bool inq[N];
// negative_loop => 1
int spfa(){
    std::queue<int> q;
    std::memset(c, 0, sizeof(c));
    std::memset(d, 0, sizeof(d));
    rep(i, 1, n) q.push(i), inq[i] = 1;
    while(q.size()){
        int u = q.front(); q.pop();
        inq[u] = 0;
        for(auto i : p[u]){
            if (d[i->v] > d[u] + i->w){
                if ((c[i->v]=c[u]+1) >= n) return 1;
                d[i->v] = d[u] + i->w;
                if (!inq[i->v]) q.push(i->v), inq[i->v] = 1;
            }
        }
    }
    return 0;
}
int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int m; cin >> n >> m;
    rep(i, 1, n) cin >> f[i];
    rep(i, 1, m){
        int u; cin >> u >> e[i].v >> e[i].t;
        p[u].push_back(&e[i]);
    }
    double l = 0, r = 1000;
    rep(ndacljk, 1, 20){
        double mid = (l+r)/2;
        rep(i, 1, m) e[i].w = mid * e[i].t - f[e[i].v];
        if (spfa()){
            l = mid;
        } else {
            r = mid;
        }
    }
    std::cout.setf(std::ios::fixed);
    cout << std::setprecision(2) << l << endl;
    return 0;
}
