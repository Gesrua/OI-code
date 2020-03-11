#include <algorithm>
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
#define rep(i, l, r) for (int i = (l); i < (r); ++i)
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

const int N = 10000, M = 100000, INF = 1e8;

#define travese(i, u) for (edge* i = p[u]; i; i = i->nxt)

int n, m, s, t;

struct edge;

edge* begin;

struct edge {
    edge* nxt;
    int v, cap;
    edge* rev() { return begin + ((this - begin) ^ 1); }
} e[M * 2 + 100];

edge* p[N + 100];

int cnt = 0;

inline void addedge(int u, int v, int cap) { e[cnt].v = v, e[cnt].cap = cap, e[cnt].nxt = p[u], p[u] = &e[cnt++]; }

struct que {
    int a[N + 100], l = 0, r = 0;
    int front() { return a[l]; }
    void pop() { ++l; }
    bool empty() { return l >= r; }
    void push(int x) { a[r++] = x; }
    void clear() { l = 0, r = 0; }
} q;

struct node {
    edge* e;
    int v;
} pre[N + 100];
bool flag[N + 100];

bool bfs() {
    std::memset(flag, 0, sizeof(flag));
    flag[s] = 1;
    q.clear();
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        travese(i, u) {
            if (i->v == t && i->cap > 0) {
                pre[i->v].v = u;
                pre[i->v].e = i;
                return 1;
            }
            if (flag[i->v]) continue;
            if (i->cap > 0) {
                pre[i->v].v = u;
                pre[i->v].e = i;
                q.push(i->v);
                flag[i->v] = 1;
            }
        }
    }
    return 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    begin = e;
    cin >> n >> m >> s >> t;
    rep(i, 0, m) {
        int u, v, cap;
        cin >> u >> v >> cap;
        addedge(u, v, cap);
        addedge(v, u, 0);
    }
    int maxflow = 0;
    while (bfs()) {
        int delta = INF;
        for (int i = t; i != s; i = pre[i].v) {
            delta = std::min(delta, pre[i].e->cap);
        }
        for (int i = t; i != s; i = pre[i].v) {
            pre[i].e->cap -= delta;
            pre[i].e->rev()->cap += delta;
        }
        maxflow += delta;
    }
    cout << maxflow;
    return 0;
}
