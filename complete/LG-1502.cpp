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
#define R(n) for (int i = 0; i < n; ++i)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int ui;

struct S {
    ll x, y;
    ll l;
    bool operator<(const S& y) const { return x < y.x; }
} a[100010];
int cnt = 0;

const ll inf = 4294967296;

struct Node {
    ll m, tag;
    Node *ls, *rs;
} T[10050000];
ll L, R, X;
int tot = 0;

void d(Node*& c) {
    if (!c->ls) {
        c->ls = &T[tot++];
        c->ls->m = c->ls->tag = 0, c->ls->ls = c->ls->rs = nullptr;
    }
    if (!c->rs) {
        c->rs = &T[tot++];
        c->rs->m = c->rs->tag = 0, c->rs->ls = c->rs->rs = nullptr;
    }
    c->ls->m += c->tag;
    c->ls->tag += c->tag;
    c->rs->m += c->tag;
    c->rs->tag += c->tag;
    c->tag = 0;
}
void up(Node*& c) {
    c->m = std::max(c->ls ? c->ls->m : 0, c->rs ? c->rs->m : 0);
    // c->m = std::max(c->ls->m, c->rs->m);
}

void add(Node*& c, ll l, ll r) {
    if (R < l || r < L) return;
    if (L <= l && r <= R) {
        c->tag += X;
        c->m += X;
        return;
    }
    d(c);
    ll mid = (l + r) / 2;
    add(c->ls, l, mid), add(c->rs, mid + 1, r);
    up(c);
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, Z;
    ll w, h;
    cin >> Z;
    while (Z--) {
        cin >> n >> w >> h;
        --h;
        tot = cnt = 0;
        Node* rt = &T[tot++];
        rt->ls = rt->rs = nullptr, rt->m = rt->tag = 0;
        R(n) {
            cin >> a[cnt].x >> a[cnt].y >> a[cnt].l;
            ++cnt;
            a[cnt].x = a[cnt - 1].x + w;
            a[cnt].y = a[cnt - 1].y, a[cnt].l = -a[cnt - 1].l;
            ++cnt;
        }
        std::sort(a, a + cnt);
        ll ans = 0;
        for (int i = -1; i + 1 < cnt;) {
            do {
                ++i;
                L = a[i].y, R = a[i].y + h, X = a[i].l;
                add(rt, 0, inf);
            } while (a[i].x == a[i + 1].x);
            ans = std::max(ans, rt ? rt->m : 0);
        }
        cout << ans << endl;
    }
    return 0;
}