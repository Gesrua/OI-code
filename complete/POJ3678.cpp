#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;

const int N = 2010;

std::vector<int> g[N];

#define addedge(x, y) g[x].push_back(y)

int dfn[N], low[N], clr[N], num = 0, stack[N], top = 0, cnt = 0, ins[N];
void tarjan(int u){
    dfn[u] = low[u] = ++num;
    stack[++top] = u, ins[u] = 1;
    for(auto v : g[u]){
        if (!dfn[v]){
            tarjan(v);
            low[u] = std::min(low[u], low[v]);
        } else if (ins[v]) low[u] = std::min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u]){
        ++cnt; int z;
        do{
            z = stack[top--], ins[z] = 0;
            clr[z] = cnt;
        } while(z != u);
    }
}


int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int n, m, a, b, c; char opt[5];
    cin >> n >> m;
    // 0~n-1 => 0
    // n~2n-1 => 1
    rep(i, 1, m){
        cin >> a >> b >> c >> opt;
        if(opt[0] == 'A'){
            if (c == 1){
                addedge(a, a+n);
                addedge(b, b+n);
            } else {
                addedge(a+n, b);
                addedge(b+n, a);
            }
        } else if (opt[0] == 'O'){
            if (c == 1){
                addedge(a, b+n);
                addedge(b, a+n);
            } else {
                addedge(a+n, a);
                addedge(b+n, b);
            }
        } else if (opt[0] == 'X'){
            if (c == 1){
                addedge(a, b+n), addedge(a+n, b);
                addedge(b, a+n), addedge(b+n, a);
            } else {
                addedge(a, b), addedge(a+n, b+n);
                addedge(b, a), addedge(b+n, a+n);
            }
        }
    }
    for(int i = 0; i < 2*n; ++i) if (!dfn[i]) tarjan(i);
    for(int i = 0; i < n; ++i)
        if (clr[i] == clr[i+n]){
            cout << "NO"; return 0;
        }
    cout << "YES";
    return 0;
}
