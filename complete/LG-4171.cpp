#include <algorithm>
#include <cassert>
#include <cmath>
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

const int N = 500;

int pre[N], dfn_time, cnt, color[N], low[N];
std::vector<int> g[N];
std::stack<int> s;

#define clean(i) std::memset(i, 0, sizeof(i))

// 汉 1~n 满 n+1~2n

void tarjan(int u) {
    pre[u] = low[u] = ++dfn_time;
    s.push(u);
    for (auto v : g[u]) {
        if (!pre[v])
            tarjan(v), low[u] = min(low[u], low[v]);
        else if (!color[v])
            low[u] = min(low[u], low[v]);
    }
    if (pre[u] == low[u]) {
        int v;
        ++cnt;
        do {
            v = s.top();
            s.pop();
            color[v] = cnt;
        } while (v != u);
    }
}

void solve() {
    while (!s.empty()) s.pop();
    clean(pre), clean(color), clean(low), dfn_time = cnt = 0;
    int n, m;
    cin >> n >> m;
    rep(i, 1, n * 2) g[i].clear();
    std::string s;
    while (m--) {
        int x = 0, y = 0, a, b;
        cin >> s;
        a = (s[0] == 'm');
        rep(i, 1, s.size() - 1) x = x * 10 + s[i] - '0';
        cin >> s;
        b = (s[0] == 'm');
        rep(i, 1, s.size() - 1) y = y * 10 + s[i] - '0';
        g[x + (a ^ 1) * n].push_back(y + b * n);
        g[y + (b ^ 1) * n].push_back(x + a * n);
    }
    rep(i, 1, n * 2) if (!color[i]) tarjan(i);
    rep(i, 1, n) if (color[i] == color[i + n]) {
        cout << "BAD\n";
        return;
    }
    cout << "GOOD\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}