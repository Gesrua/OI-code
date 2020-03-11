#include <iostream>
#include <vector>
#include <algorithm>
using std::cin; using std::cout; using std::endl; using std::cerr;
const int N = 50100; typedef long long ll; const ll inf = 5e13 + 1;
typedef std::pair<int, ll> pil;
std::vector<pil> g[N];
int fa[N], n, m, army[N], tot = 0;; ll dep[N];
std::vector<ll> f[N]; typedef std::vector<ll> vll;
void dfs(int u, int fa, ll d, vll& x){
	dep[u] = -d;
    for (int i = 1; i <= army[u]; ++i) x.push_back(-d);
    for (auto i : g[u]){
        int& v = i.first; ll& w = i.second;
        if (v == fa) continue;
        dfs(v, u, d + w, x);
    }
}
ll nodes[N], troop[N], tn, tt;
ll control(int u, int fa, ll T, ll W){
	ll ret = -1;
//	cerr << u << ' ' << army[u] << ' ' << T+dep[u] << ' ' << W << endl;
	if (army[u] > 0 && T + dep[u] < W) return T;
	bool exist_not_control = (g[u].size() == 1);
	for (auto i : g[u]){
		if (i.first == fa) continue;
		int& v = i.first; ll& w = i.second;
		ll son = control(v, u, T, W);
		ret = std::max(ret, son - w);
		if (son < 0) exist_not_control = 1;
	}
	if (ret >= 0) return ret;
	if (!exist_not_control) return 0;
	else return -1;
}
bool judge(ll t){
    tn=tt=0;
    for (int i = 0; i < g[1].size(); ++i){
        int v = g[1][i].first; ll w = g[1][i].second;
		int x = 0;
		for(; x < f[i].size() && t+f[i][x] < 0; ++x);
        if (x >= f[i].size()) {
            if (control(v, 1, t, inf) < 0) nodes[++tn] = w;
        } else {
            if (t+f[i][x] < 2*w){
                if (control(v, 1, t, t+f[i][x]) < 0) ++x;
                for(; x < f[i].size(); ++x) 
                    if (t + f[i][x] - w >= 0)
                        troop[++tt] = t + f[i][x] - w;
            } else {
                for(; x < f[i].size(); ++x) troop[++tt] = t + f[i][x] - w;
                nodes[++tn] = w;
            }
		}
    }
    std::sort(nodes+1, nodes+tn+1); std::sort(troop+1, troop+tt+1);
    // cerr << "T = " << t << endl;
    // for (int i = 1; i <= tn; ++i) cerr << nodes[i] << ' '; cerr << endl;
    // for (int i = 1; i <= tt; ++i) cerr << troop[i] << ' '; cerr << endl;
    int i = 1, j = 1;
    while(i <= tn && j <= tt){
        if (nodes[i] <= troop[j]) ++i, ++j;
        else ++j;
    }
    return i > tn;
}
int main(){
//	freopen("input", "r", stdin);
    cin >> n;
    for (int i = 1; i < n; ++i){
        int u, v; ll w; cin >> u >> v >> w; g[u].push_back({v, w}), g[v].push_back({u, w});
    }
    cin >> m;
    for (int i = 1; i <= m; ++i){
        int pos; cin >> pos; army[pos]++;
    }
    for (auto i : g[1]){
        dfs(i.first, 1, 0, f[tot++]);
        std::sort(f[tot-1].begin(), f[tot-1].end());
    }
    // cerr << judge(80321);
    ll l = 0, r = inf;
    while (l < r){
        ll mid = (l+r)>>1;
        if (judge(mid)) r = mid;
        else l = mid + 1;
    }
    if (r == inf) cout << -1;
    else cout << l;
    return 0;
}