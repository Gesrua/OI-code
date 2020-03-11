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
#define ls (idx * 2)
#define rs (idx * 2 + 1)
const ll inf = 4611686018427387904LL;

int n, tot;
struct Node;
struct Edge {
    ll w;
    Node* v;
    Edge* nxt;
} e[5000010];
int cnt = 0;
struct Node {
    int l, r, vis;
    ll d;
    Edge* p;
} a[100010];

void addedge(Node* u, Node* v, ll w) {
    e[tot].v = v, e[tot].w = w, e[tot].nxt = u->p, u->p = &e[tot++];
}

struct InTree {
    Node in[400010];
    Node* build(int idx, int l, int r) {
        Node* cur = &in[idx];
        cur->l = l, cur->r = r;
        cur->d = inf;
        if (l == r) {
            addedge(cur, &a[l], 0);
            return cur;
        }
        int mid = (l + r) / 2;
        addedge(cur, build(ls, l, mid), 0);
        addedge(cur, build(rs, mid + 1, r), 0);
        return cur;
    }
    int L, R, w;
    Node* f;
    void add(int v, int l, int r, int _w) {
        L = l, R = r, w = _w, f = &a[v];
        _a(1, 1, n);
    }
    void _a(int idx, int l, int r) {
        if (L <= l && r <= R) {
            addedge(f, &in[idx], w);
            return;
        }
        if (r < L || R < l) return;
        int mid = (l + r) / 2;
        _a(ls, l, mid), _a(rs, mid + 1, r);
    }
    void print(int idx, int l, int r) {
        if (l == r) return;
        cerr << l << ' ' << r << endl;
        for (Edge* i = in [idx].p; i; i = i->nxt) {
            cerr << i->v->l << ' ' << i->v->r << ' ' << i->w << endl;
        }
        cerr << "----------" << endl;
        int mid = (l + r) / 2;
        print(ls, l, mid), print(rs, mid + 1, r);
    }
} I;
struct OutTree {
    Node out[400010];
    int cnt = 0;
    Node* build(int idx, int l, int r) {
        // if (l == r) return &a[l];
        Node* cur = &out[idx];
        cur->l = l, cur->r = r;
        cur->d = inf;
        if (l == r) {
            addedge(&a[l], cur, 0);
            return cur;
        }
        int mid = (l + r) / 2;
        addedge(build(ls, l, mid), cur, 0);
        addedge(build(rs, mid + 1, r), cur, 0);
        return cur;
    }
    int L, R, w;
    Node* f;
    void add(int l, int r, int v, int _w) {
        L = l, R = r, w = _w, f = &a[v];
        _a(1, 1, n);
    }
    void _a(int idx, int l, int r) {
        if (L <= l && r <= R) {
            addedge(&out[idx], f, w);
            return;
        }
        if (r < L || R < l) return;
        int mid = (l + r) / 2;
        _a(ls, l, mid), _a(rs, mid + 1, r);
    }
    void print(int idx, int l, int r) {
        if (l == r) return;
        cerr << l << ' ' << r << endl;
        for (Edge* i = out[idx].p; i; i = i->nxt) {
            cerr << i->v->l << ' ' << i->v->r << ' ' << i->w << endl;
        }
        cerr << "----------" << endl;
        int mid = (l + r) / 2;
        print(ls, l, mid), print(rs, mid + 1, r);
    }
} O;

typedef pair<ll, Node*> pin;

void print_node(Node* u) {
    for (Edge* i = u->p; i; i = i->nxt) {
        cerr << i->v->l << ' ' << i->v->r << ' ' << i->w << endl;
    }
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int q, s;
    cin >> n >> q >> s;
    rep(i, 1, n) a[i].l = a[i].r = i, a[i].d = inf;
    I.build(1, 1, n), O.build(1, 1, n);
    // I.print(1, 1, n);
    rep(i, 1, q) {
        int t, u, v, l, r;
        ll w;
        cin >> t;
        if (t == 1) {
            cin >> v >> u >> w;
            addedge(&a[v], &a[u], w);
        } else if (t == 2) {
            cin >> v >> l >> r >> w;
            I.add(v, l, r, w);
        } else if (t == 3) {
            cin >> v >> l >> r >> w;
            O.add(l, r, v, w);
        }
    }
    std::priority_queue<pin, std::vector<pin>, std::greater<pin> > que;
    que.push(pin(0, &a[s]));
    a[s].d = 0;
    while (que.size()) {
        Node* u = que.top().second;
        // cerr << u->l << ' ' << u->r << endl;
        ll d = que.top().first;
        que.pop();
        if (u->vis || u->d != d) continue;
        u->vis = 1;
        for (Edge* i = u->p; i; i = i->nxt) {
            if (d + i->w < i->v->d) {
                i->v->d = d + i->w;
                que.push(pin(i->v->d, i->v));
            }
        }
    }
    rep(i, 1, n) { cout << (a[i].d == inf ? -1 : a[i].d) << ' '; }
    return 0;
}