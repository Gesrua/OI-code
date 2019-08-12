#define NDEBUG
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("inline")
// #pragma GCC optimize("-fgcse")
// #pragma GCC optimize("-fgcse-lm")
// #pragma GCC optimize("-fipa-sra")
// #pragma GCC optimize("-ftree-pre")
// #pragma GCC optimize("-ftree-vrp")
// #pragma GCC optimize("-fpeephole2")
// #pragma GCC optimize("-ffast-math")
// #pragma GCC optimize("-fsched-spec")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("-falign-jumps")
// #pragma GCC optimize("-falign-loops")
// #pragma GCC optimize("-falign-labels")
// #pragma GCC optimize("-fdevirtualize")
// #pragma GCC optimize("-fcaller-saves")
// #pragma GCC optimize("-fcrossjumping")
// #pragma GCC optimize("-fthread-jumps")
// #pragma GCC optimize("-funroll-loops")
// #pragma GCC optimize("-fwhole-program")
// #pragma GCC optimize("-freorder-blocks")
// #pragma GCC optimize("-fschedule-insns")
// #pragma GCC optimize("inline-functions")
// #pragma GCC optimize("-ftree-tail-merge")
// #pragma GCC optimize("-fschedule-insns2")
// #pragma GCC optimize("-fstrict-aliasing")
// #pragma GCC optimize("-fstrict-overflow")
// #pragma GCC optimize("-falign-functions")
// #pragma GCC optimize("-fcse-skip-blocks")
// #pragma GCC optimize("-fcse-follow-jumps")
// #pragma GCC optimize("-fsched-interblock")
// #pragma GCC optimize("-fpartial-inlining")
// #pragma GCC optimize("no-stack-protector")
// #pragma GCC optimize("-freorder-functions")
// #pragma GCC optimize("-findirect-inlining")
// #pragma GCC optimize("-fhoist-adjacent-loads")
// #pragma GCC optimize("-frerun-cse-after-loop")
// #pragma GCC optimize("inline-small-functions")
// #pragma GCC optimize("-finline-small-functions")
// #pragma GCC optimize("-ftree-switch-conversion")
// #pragma GCC optimize("-foptimize-sibling-calls")
// #pragma GCC optimize("-fexpensive-optimizations")
// #pragma GCC optimize("-funsafe-loop-optimizations")
// #pragma GCC optimize("inline-functions-called-once")
// #pragma GCC optimize("-fdelete-null-pointer-checks")
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
#ifdef NDEBUG
#define dbg(x)
#else
#define dbg(x) cerr << x << endl;
#endif

using std::cerr;
using std::endl;
using std::make_pair;
using std::pair;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int ui;

// #define DEBUG 1  //调试开关
struct IO {
#define MAXSIZE (1 << 20)
#define isdigit(x) (x >= '0' && x <= '9')
    char buf[MAXSIZE], *p1, *p2;
    char pbuf[MAXSIZE], *pp;
#if DEBUG
#else
    IO() : p1(buf), pp(pbuf), p2(buf) {}
    ~IO() { fwrite(pbuf, 1, pp - pbuf, stdout); }
#endif
    inline char gc() {
#if DEBUG  //调试，可显示字符
        return getchar();
#endif
        if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
        return p1 == p2 ? -1 : *p1++;
    }
    inline bool blank(char ch) {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    }
    template <class T>
    inline void read(T &x) {
        register double tmp = 1;
        register bool sign = 0;
        x = 0;
        register char ch = gc();
        for (; !isdigit(ch); ch = gc())
            if (ch == '-') sign = 1;
        for (; isdigit(ch); ch = gc()) x = x * 10 + (ch - '0');
        if (ch == '.')
            for (ch = gc(); isdigit(ch); ch = gc())
                tmp /= 10.0, x += tmp * (ch - '0');
        if (sign) x = -x;
    }
    inline void read(char *s) {
        register char ch = gc();
        for (; blank(ch); ch = gc())
            ;
        for (; !blank(ch); ch = gc()) *s++ = ch;
        *s = 0;
    }
    inline void read(char &c) {
        for (c = gc(); blank(c); c = gc())
            ;
    }
    inline void push(const char &c) {
#if DEBUG  //调试，可显示字符
        putchar(c);
#else
        if (pp - pbuf == MAXSIZE) fwrite(pbuf, 1, MAXSIZE, stdout), pp = pbuf;
        *pp++ = c;
#endif
    }
    template <class T>
    inline void write(T x) {
        if (x < 0) x = -x, push('-');  // 负数输出
        static T sta[35];
        T top = 0;
        do {
            sta[top++] = x % 10, x /= 10;
        } while (x);
        while (top) push(sta[--top] + '0');
    }
    template <class T>
    inline void write(T x, char lastChar) {
        write(x), push(lastChar);
    }
} io;

inline int rnd() {
    static int seed = 703;
    return seed = int(seed * 48271LL % 2147483647);
}

const int N = 300100;

struct Node {
    int l, r, pri, siz;
    ll prefix;
    Node *ls, *rs;
    void upd() { siz = (ls ? ls->siz : 0) + (rs ? rs->siz : 0) + r - l + 1; }
    int rank() { return (ls ? ls->siz : 0) + 1; }
} T[9000000];

void print(Node *u) {
#ifdef NDEBUG
    return;
#else
    if (u == nullptr) return;
    print(u->ls);
    dbg(u->l << ' ' << u->r << ' ' << u->prefix);
    print(u->rs);
#endif
}

int cnt = 0;
Node *gen(int l, int r, ll prefix) {
    T[cnt].l = l, T[cnt].r = r, T[cnt].prefix = prefix,
    T[cnt].ls = T[cnt].rs = nullptr, T[cnt].siz = r - l + 1, T[cnt].pri = rnd();
    return &T[cnt++];
}
Node *gen(int x, ll prefix) {
    T[cnt].l = T[cnt].r = x, T[cnt].prefix = prefix,
    T[cnt].ls = T[cnt].rs = nullptr, T[cnt].siz = 1, T[cnt].pri = rnd();
    return &T[cnt++];
}
int num[N], lstc;
Node *rt[N], *lst;
typedef std::pair<Node *, Node *> pnn;

Node *merge(Node *u, Node *v) {
    if (u == nullptr) return v;
    if (v == nullptr) return u;
    if (u->pri > v->pri) {
        u->rs = merge(u->rs, v);
        u->upd();
        return u;
    } else {
        v->ls = merge(u, v->ls);
        v->upd();
        return v;
    }
}

void unfold(Node *&u, int k) {  // 必须保证 u 为根
    assert(u->l != u->r);
    assert(u->l <= k && k <= u->r);
    if (u->l == k) {
        Node *t = gen(k + 1, u->r, u->prefix + 1);
        t->rs = u->rs;
        u->rs = t;
        u->r = k;
        u->rs->upd(), u->upd();
    } else if (u->r == k) {
        Node *t = gen(u->l, u->r - 1, u->prefix);
        t->ls = u->ls;
        u->ls = t;
        u->prefix += +u->r - u->l;
        u->l = u->r;
        u->ls->upd(), u->upd();
    } else {
        Node *t1 = gen(u->l, k - 1, u->prefix),
             *t2 = gen(k + 1, u->r, u->prefix + k + 1 - u->l);
        t1->ls = u->ls;
        t2->rs = u->rs;
        u->ls = t1;
        u->rs = t2;
        u->prefix += k - u->l;
        u->l = u->r = k;
        u->ls->upd(), u->rs->upd(), u->upd();
    }
}

pnn split_rank(Node *u, int k) {
    if (u == nullptr) return {nullptr, nullptr};
    if (u->l != u->r && u->rank() <= k && k <= u->rank() + u->r - u->l) {
        unfold(u, u->l + k - u->rank());
    }
    if (u->rank() <= k) {
        pnn o = split_rank(u->rs, k - (u->rank() + u->r - u->l));
        u->rs = o.first;
        u->upd();
        return {u, o.second};
    } else {
        pnn o = split_rank(u->ls, k);
        u->ls = o.second;
        u->upd();
        return {o.first, u};
    }
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    int n, m, q;
    io.read(n), io.read(m), io.read(q);
    rep(i, 1, n) {
        num[i] = m - 1;
        rt[i] = gen(1, m - 1, (ll)(i - 1) * m + 1);
    }
    rep(i, 1, n) { lst = merge(lst, gen(i, (ll)i * m)); }
    lstc = n;
    rep(stp, 1, q) {
        int x, y;
        io.read(x), io.read(y);
        if (y == m) {
            pnn o1, o2;
            o2 = split_rank(lst, x);
            o1 = split_rank(o2.first, x - 1);
            io.write(o1.second->prefix, '\n');
            o1.second->siz = 1, o1.second->ls = o1.second->rs = nullptr,
            o1.second->l = o1.second->r = ++lstc;
            lst = merge(merge(o1.first, o2.second), o1.second);
        } else {
            pnn t1, t2, o1, o2;

            print(rt[x]);
            t2 = split_rank(rt[x], y);
            t1 = split_rank(t2.first, y - 1);

            o2 = split_rank(lst, x);
            o1 = split_rank(o2.first, x - 1);

            io.write(t1.second->prefix, '\n');

            o1.second->siz = 1, o1.second->ls = o1.second->rs = nullptr,
            o1.second->l = o1.second->r = ++num[x];

            t1.second->siz = 1, t1.second->ls = t1.second->rs = nullptr,
            t1.second->l = t1.second->r = ++lstc;

            rt[x] = merge(merge(t1.first, t2.second), o1.second);
            lst = merge(merge(o1.first, o2.second), t1.second);
        }
    }
    return 0;
}