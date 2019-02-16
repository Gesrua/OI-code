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
using std::pair;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int ui;

const int N = 10100, M = 100100;

struct edge {
    int v;
    edge* nxt;
} e[M];

struct point {
    int w;
    edge* head;
} p[N];

int cnt = 0;

void addedge(int u, int v) {
    e[cnt].v = v, e[cnt].nxt = p[u].head;
    p[u].head = &e[cnt++];
}

#define travese(i, u) for (edge* i = p[u].head; i; i = i->nxt)
#define chkmax(a, b) \
    if (a < b) a = b;
#define chkmin(a, b) \
    if (a > b) a = b;

int id[N], idc, dfn[N], low[N], vis[N], val[N];

int stamp = 0, a[N];

struct stack {
    int cur = 0;
    void clear() { cur = 0; }
    void push(int x) { a[cur++] = x; }
    int top() { return a[cur - 1]; }
    int pop() { return a[--cur]; }
} s;

struct queue {
    int head = 0, tail = 0;
    void clear() { head = 0, tail = 0; }
    void push(int x) { a[tail++] = x; }
    void pop() { ++head; }
    int front() { return a[head]; }
    bool empty() { return head >= tail; }
} q;

void tarjan(int u) {
    dfn[u] = low[u] = ++stamp, vis[u] = 1;
    s.push(u);
    travese(i, u) {
        if (dfn[i->v]) {
            if (vis[i->v]) chkmin(low[u], low[i->v]);
        } else {
            tarjan(i->v);
            chkmin(low[u], low[i->v]);
        }
    }
    if (dfn[u] == low[u]) {
        ++idc;
        do {
            val[idc] += p[s.top()].w, id[s.top()] = idc;
            vis[s.top()] = 0;  // ???
        } while (s.pop() != u);
    }
    // vis[u] = 0; ???
}

std::vector<int> g[N];

int in[N];

int ans = 0, f[N];

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    static int n, m;
    cin >> n >> m;
    int u, v;
    rep(i, 1, n) cin >> p[i].w;
    rep(i, 1, m) {
        cin >> u >> v;
        addedge(u, v);
    }

    // tarjan 缩点
    rep(i, 1, n) if (!dfn[i]) tarjan(i);

    // build new graph
    rep(u, 1, n) travese(i, u) if (id[u] != id[i->v]) g[id[u]].push_back(id[i->v]), in[id[i->v]]++;

    // topo sort + DAG dp
    q.clear();
    rep(i, 1, idc) if (in[i] == 0) q.push(i), f[i] = val[i];
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            in[v]--;
            f[v] = std::max(f[v], f[u] + val[v]);
            if (in[v] == 0) q.push(v);
        }
    }

    // ans
    rep(i, 1, idc) chkmax(ans, f[i]);
    cout << ans;
    return 0;
}
