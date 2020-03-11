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

const int N = 100000;

int L, R, X;

struct node;

node* create();

struct node {
    int l, r, n;
    node *ls, *rs;
    int rk() { return rs != NULL ? rs->n : 0; }
    void pushup() { n = (ls != NULL ? ls->n : 0) + (rs != NULL ? rs->n : 0); }
} T[N * 40];

node* root[N + 100];

node* merge(node* ret, node* cur) {
    if (ret == NULL && cur == NULL) return NULL;
    if (cur == NULL) return ret;
    if (ret == NULL) return cur;
    ret->n += cur->n;
    ret->ls = merge(ret->ls, cur->ls);
    ret->rs = merge(ret->rs, cur->rs);
    return ret;
}

void insert(node* cur) {
    if (X < cur->l || cur->r < X) return;
    if (cur->l == cur->r) {
        cur->n++;
        return;
    }
    // cur->pushdown();
    int mid = cur->l + cur->r >> 1;
    // cerr << cur->l << ' ' << cur->r << endl;
    if (X <= mid) {
        cur->ls = create();
        cur->ls->l = cur->l, cur->ls->r = mid;
        insert(cur->ls);
    } else {
        cur->rs = create();
        cur->rs->l = mid + 1, cur->rs->r = cur->r;
        insert(cur->rs);
    }
    // insert(cur->ls);
    // insert(cur->rs);
    cur->pushup();
}

ll a[N + 100];

int cnt = 0, f[N + 100];

struct ask {
    int id, v, w, k, ans;
} q[5 * N + 100];

struct edge {
    int u, v, w;
} e[5 * N + 100];

bool ask_id(ask& a, ask& b) { return a.id < b.id; }

bool ask_w(ask& a, ask& b) { return a.w < b.w; }

bool edge_w(edge& a, edge& b) { return a.w < b.w; }

int find(int x) { return x == f[x] ? x : (f[x] = find(f[x])); }

int query(node* cur, int k) {
    while (cur->l != cur->r) {
        if (cur->rk() >= k) {
            cur = cur->rs;
        } else {
            k -= cur->rk();
            cur = cur->ls;
        }
    }
    return cur->l;
}

void out(std::string s) { cerr << s << endl; }

int main() {
    // freopen("/tmp/input", "r", stdin);
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, m, p;
    cin >> n >> m >> p;
    rep(i, 1, n) {
        f[i] = i;
        cin >> X;
        root[i] = create();
        root[i]->l = 1, root[i]->r = 1000000000;
        // out("insert begin");
        insert(root[i]);
        // out("insert end");
    }
    rep(i, 1, m) { cin >> e[i].u >> e[i].v >> e[i].w; }
    std::sort(e + 1, e + 1 + m, edge_w);
    rep(i, 1, p) {
        q[i].id = i;
        cin >> q[i].v >> q[i].w >> q[i].k;
    }
    std::sort(q + 1, q + 1 + p, ask_w);
    int j = 1;
    rep(i, 1, p) {
        while (j <= m && e[j].w <= q[i].w) {
            int x = find(e[j].u), y = find(e[j].v);
            if (x != y) {
                root[x] = merge(root[x], root[y]);
                f[y] = x;
            }
            ++j;
        }
        int x = find(q[i].v);
        if (root[x]->n < q[i].k) {
            q[i].ans = -1;
        } else {
            q[i].ans = query(root[x], q[i].k);
        }
    }
    std::sort(q + 1, q + 1 + p, ask_id);
    rep(i, 1, p) { cout << q[i].ans << endl; }
    return 0;
}

node* create() {
    // assert(cnt < (N*20));
    return &T[cnt++];
}