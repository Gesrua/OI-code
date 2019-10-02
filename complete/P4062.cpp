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
typedef unsigned long long ull;

const int N = 500000;
const int FIX = N + 1;

struct S {
    struct Seg1 {
        struct Node {
            Node *ls, *rs;
            ll sum, tag;
            int clear;
            int l, r;
            int dis() { return r - l + 1; }
            void pushdown() {
                if (clear) ls->clear = rs->clear = 1, ls->tag = rs->tag = ls->sum = rs->sum = 0, clear = 0;
                ls->sum += ls->dis() * tag, ls->tag += tag;
                rs->sum += rs->dis() * tag, rs->tag += tag;
                tag = 0;
            }
            void maintain() { sum = ls->sum + rs->sum; }
        } T[8 * N];
        int cnt = 0, L, R;
        Node* root;
        Seg1() { build(root, 1, N + FIX); }
        void build(Node*& c, int l, int r) {
            c = &T[cnt++];
            c->l = l, c->r = r;
            if (l == r) return;
            int mid = (l + r) / 2;
            build(c->ls, l, mid), build(c->rs, mid + 1, r);
        }
        void clear() { root->sum = root->tag = 0, root->clear = 1; }
        void _e(Node* c) {
            if (L <= c->l && c->r <= R) {
                c->tag += 1, c->sum += c->dis();
                return;
            }
            if (c->r < L || R < c->l) return;
            c->pushdown();
            _e(c->ls), _e(c->rs);
            c->maintain();
        }
        ll _q(Node* c) {
            if (L <= c->l && c->r <= R) return c->sum;
            if (c->r < L || R < c->l) return 0;
            c->pushdown();
            return _q(c->ls) + _q(c->rs);
        }
        void edit(int l, int r) {
            L = l + FIX, R = r + FIX;
            _e(root);
        }
        ll query(int l, int r) {
            L = l + FIX, R = r + FIX;
            return _q(root);
        }
        void print(Node* c) {
            if (!c) return;
            cout << c->l << ' ' << c->r << endl;
            print(c->ls), print(c->rs);
        }
    } s1;
    struct Seg2 {
        int cnt = 0, L, R;
        struct Node {
            Node *ls, *rs;
            ll sum, tag;
            int clear;
            int l, r;
            ll calc() { return ((ll)l + r - 2 * FIX) * (r - l + 1) / 2; }
            int dis() { return r - l + 1; }
            void pushdown() {
                if (clear) ls->clear = rs->clear = 1, ls->tag = rs->tag = ls->sum = rs->sum = 0, clear = 0;
                ls->sum += ls->calc() * tag, ls->tag += tag;
                rs->sum += rs->calc() * tag, rs->tag += tag;
                tag = 0;
            }
            void maintain() { sum = ls->sum + rs->sum; }
        } T[8 * N];

        Node* root;
        Seg2() { build(root, 1, N + FIX); }
        void build(Node*& c, int l, int r) {
            c = &T[cnt++];
            c->l = l, c->r = r;
            if (l == r) return;
            int mid = (l + r) / 2;
            build(c->ls, l, mid), build(c->rs, mid + 1, r);
        }
        void clear() { root->sum = root->tag = 0, root->clear = 1; }
        void _e(Node* c) {
            if (L <= c->l && c->r <= R) {
                c->tag += 1, c->sum += c->calc();
                return;
            }
            if (c->r < L || R < c->l) return;
            c->pushdown();
            _e(c->ls), _e(c->rs);
            c->maintain();
        }
        ll _q(Node* c) {
            if (L <= c->l && c->r <= R) return c->sum;
            if (c->r < L || R < c->l) return 0;
            c->pushdown();
            return _q(c->ls) + _q(c->rs);
        }
        void edit(int l, int r) {
            L = l + FIX, R = r + FIX;
            _e(root);
        }
        ll query(int l, int r) {
            L = l + FIX, R = r + FIX;
            return _q(root);
        }
    } s2;
    void clear() { s1.clear(), s2.clear(); }
    void edit(int l, int r) {
        if (l > r) std::swap(l, r);
        // cerr << "editing" << endl;
        // rep(i, l, r) cerr << s1.query(i, i) << ' ';
        // cerr << endl;
        s1.edit(l, r), s2.edit(l, r);
        // rep(i, l, r) cerr << s1.query(i, i) << ' ';
        // cerr << endl;
    }
    ll query(ll x, ll y) {
        if (x > y) std::swap(x, y);
        return (y - x + 1) * s1.query(-N, x - 1) + y * s1.query(x, y - 1) - s2.query(x, y - 1);
    }
} s;
int n, a[N + 10];
struct X {
    struct Node {
        int pos;
        Node* nxt;
    } pool[N + 10];
    Node* p[N + 10];
    Node* end[N + 10];
    int cnt = 0;
    void add(int x, int pos) {
        pool[cnt].pos = pos, pool[cnt].nxt = nullptr;
        // p[x] = &pool[cnt++];
        if (p[x] == nullptr)
            p[x] = &pool[cnt], end[x] = &pool[cnt];
        else
            end[x]->nxt = &pool[cnt], end[x] = &pool[cnt];
        cnt++;
    }
    bool empty(int x) { return p[x] == nullptr; }
    void del(int x) { p[x] = p[x]->nxt; }
    int ask(int x) { return p[x] != nullptr ? p[x]->pos : (n + 1); }
} q;
int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int t;
    cin >> n >> t;
    rep(i, 1, n) {
        cin >> a[i];
        q.add(a[i], i);
    }
    ll ans = 0;
    rep(x, 0, n) {
        // cerr << "doing " << x << endl;
        if (q.empty(x)) continue;
        s.clear();
        int pre = 0, lst = 0, cur, nxt;
        while (!q.empty(x)) {
            cur = q.ask(x);
            // cerr << "cur " << cur << endl;
            q.del(x);
            s.edit(2 * pre - lst, 2 * pre - (cur - 1));
            // cerr << "value " << 2 * pre - lst << ' ' << 2 * pre - (cur - 1) << endl;
            // cerr << "edit " << lst << ' ' << cur - 1 << endl;
            pre++, lst = cur;
            nxt = q.ask(x);
            // cerr << "ans " << s.query(2 * pre - cur, 2 * pre - (nxt - 1)) << endl;
            // cerr << "dbg " << s.s1.query(0, 2 * pre - (nxt - 1)) << endl;
            ans += s.query(2 * pre - cur, 2 * pre - (nxt - 1));
        }
    }
    cout << ans;
    return 0;
}