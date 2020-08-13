#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl; using std::make_pair; using std::pair;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull; typedef pair<int, int> pii; 

const int N = 3.1e4;

namespace AC{

int tr[N][2], fail[N], end[N], tot = 1;

void insert(char* s){
    int u = 0;
    for(int i = 0; s[i]; ++i){
        int c = s[i] - '0';
        if (!tr[u][c]) tr[u][c] = tot++;
        u = tr[u][c];
        // cerr << s[i] << ' ' << u << endl;
    }
    end[u] = 1;
}

void build(){
    std::queue<int> q;
    rep(c, 0, 1) if (tr[0][c]) q.push(tr[0][c]);
    while(q.size()){
        int u = q.front(); q.pop();
        rep(c, 0, 1){
            if (tr[u][c]){
                fail[tr[u][c]] = tr[fail[u]][c];
                q.push(tr[u][c]);
            } else {
                tr[u][c] = tr[fail[u]][c];
            }
        }
    }
}

std::vector<int> g[N];

void dfs(int u, int tag){
    end[u] |= tag;
    for(auto v : g[u])
        dfs(v, end[u]);
}

int vis[N], tag = 0;

void dfs2(int u){
    if (vis[u]){
        tag = 1;
        return;
    }
    vis[u] = 1;
    rep(c, 0, 1)
        if (!end[tr[u][c]])
            dfs2(tr[u][c]);
    end[u] = 1;
}

void solve(){
    rep(u, 1, tot-1) g[fail[u]].push_back(u);
    dfs(0, 0);
    dfs2(0);
    if (tag) cout << "TAK";
    else cout << "NIE";
}

}

char s[N];

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n; cin >> n;
    rep(i, 1, n){
        cin >> s;
        AC::insert(s);
    }
    AC::build();
    AC::solve();
    return 0;
}