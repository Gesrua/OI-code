#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::min;
using std::pair;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int ui;

const int N = 2e6 + 5;

int pre[N], n, m, low[N], dfn, color[N], cnt;
std::vector<int> g[N];
std::stack<int> s;

void tarjan(int u) {
    pre[u] = low[u] = ++dfn, s.push(u);
    for (auto v : g[u])
        if (!pre[v])
            tarjan(v), low[u] = min(low[u], low[v]);
        else if (!color[v])
            low[u] = min(low[u], low[v]);
    if (low[u] == pre[u]) {
        int v;
        ++cnt;
        do {
            v = s.top();
            s.pop();
            color[v] = cnt;
        } while (v != u);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n >> m;
    rep(i, 1, m) {
        int x, a, y, b;
        cin >> x >> a >> y >> b;
        g[x + (a ^ 1) * n].push_back(y + b * n);  // 1~n false n+1~2n true
        g[y + (b ^ 1) * n].push_back(x + a * n);
    }
    rep(i, 1, 2 * n) if (!color[i]) tarjan(i);
    rep(i, 1, n) if (color[i] == color[i + n]) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << "POSSIBLE\n";
    // if topo(i) > topo(i+n): cout << 0
    // topo(i) > topo(i+n) <=> color[i] <  color[i+n]
    rep(i, 1, n) cout << (color[i] > color[i + n]) << ' ';
    return 0;
}