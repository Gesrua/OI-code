#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl; using std::make_pair; using std::pair;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull; typedef pair<int, int> pii; 

const int N = 2e5+10;

std::vector<int> g[N];
int m[N];
std::priority_queue<int> h[N];
std::vector<int> tmp;

void dfs(int u){
    for(auto v : g[u]){
        dfs(v);
        if (h[u].size() < h[v].size()) std::swap(h[u], h[v]);
        while(h[v].size()){
            tmp.push_back(std::max(h[u].top(), h[v].top()));
            h[u].pop(); h[v].pop();
        }
        while(tmp.size()) h[u].push(tmp[tmp.size()-1]), tmp.pop_back();
    }
    h[u].push(m[u]);
}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n; cin >> n;
    rep(i, 1, n) cin >> m[i];
    rep(i, 2, n){
        int f; cin >> f; g[f].push_back(i);
    }
    dfs(1);
    ll ans = 0;
    while(h[1].size()){
        ans += h[1].top();
        h[1].pop();
    }
    cout << ans;
    return 0;
}