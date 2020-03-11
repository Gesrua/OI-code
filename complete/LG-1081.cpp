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
using std::cerr;
using std::endl;
using std::make_pair;
using std::pair;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

// #define DEBUG 1  //调试开关
struct IO {
#define MAXSIZE (1 << 20)
#define isdigit(x) (x >= '0' && x <= '9')
    char buf[MAXSIZE], *p1, *p2;
    char pbuf[MAXSIZE], *pp;
#if DEBUG
#else
    IO() : p1(buf), p2(buf), pp(pbuf) {}
    ~IO() { fwrite(pbuf, 1, pp - pbuf, stdout); }
#endif
    inline char gc() {
#if DEBUG  //调试，可显示字符
        return getchar();
#endif
        if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
        return p1 == p2 ? -1 : *p1++;
    }
    inline bool blank(char ch) { return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t'; }
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
            for (ch = gc(); isdigit(ch); ch = gc()) tmp /= 10.0, x += tmp * (ch - '0');
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
    inline void write(const char *s) {
        while (*s != '\0') push(*(s++));
    }
    template <class T>
    inline void write(T x, char lastChar) {
        write(x), push(lastChar);
    }
} io;

typedef std::pair<ll, ll> pll;

const int N = 100010, K = 18;

pll disa[N][K + 1], disb[N][K + 1];
int toa[N][K + 1], tob[N][K + 1];
ll h[N];
int n;
using std::abs;
#define adpl(x, y) (x.first += y.first, x.second += y.second)
#define add(x, y) pll(x.first + y.first, x.second + y.second)

void pre() {
    std::set<pll> s;
    s.insert({-3e9 - 1, -1}), s.insert({-3e9 - 2, -1}), s.insert({3e9 + 1, -1}), s.insert({3e9 + 2, -1});
    per(i, n, 1) {
        auto x = s.lower_bound({h[i], 0});
        std::set<std::pair<pll, ll>> tmp;
        tmp.insert({{abs(h[i] - x->first), h[x->second]}, x->second});
        ++x, tmp.insert({{abs(h[i] - x->first), h[x->second]}, x->second});
        --x, --x, tmp.insert({{abs(h[i] - x->first), h[x->second]}, x->second});
        --x, tmp.insert({{abs(h[i] - x->first), h[x->second]}, x->second});
        auto t = tmp.begin();
        if (t->second != -1) {
            tob[i][0] = t->second;
            disb[i][0] = {0, t->first.first};
            ++t;
            if (t->second != -1) {
                toa[i][0] = t->second;
                disa[i][0] = {t->first.first, 0};
            }
        }
        s.insert({h[i], i});
    }
    rep(i, 1, n) {
        toa[i][1] = tob[toa[i][0]][0];
        disa[i][1] = add(disa[i][0], disb[toa[i][0]][0]);
    }
    rep(k, 2, K) {
        rep(i, 1, n) {
            toa[i][k] = toa[toa[i][k - 1]][k - 1];
            disa[i][k] = add(disa[i][k - 1], disa[toa[i][k - 1]][k - 1]);
        }
    }
}

pll query(int s, ll x) {
    pll ret(0, 0);
    // cerr << "quering " << s << ' ' << x << endl;
    per(k, K, 0) {
        if (toa[s][k] == 0 || disa[s][k].first + disa[s][k].second > x) continue;
        // cerr << k << ' ' << toa[s][k]endl;
        x -= disa[s][k].first + disa[s][k].second;
        adpl(ret, disa[s][k]);
        s = toa[s][k];
    }
    // cerr << "end query\n";
    return ret;
}

int main() {
    // #ifndef ONLINE_JUDGE
    //     freopen("input", "r", stdin);
    // #endif
    io.read(n);
    rep(i, 1, n) io.read(h[i]);
    pre();
    // rep(k, 0, 2) {
    //     rep(i, 1, n) { cerr << toa[i][k] << ' '; }
    //     cerr << "\n---\n";
    // }
    // rep(k, 0, 2) {
    //     rep(i, 1, n) { cerr << "(" << disa[i][k].first << ", " << disa[i][k].second << ") "; }
    //     cerr << "\n---\n";
    // }

    int s;
    ll x;
    double ratio = -1;
    int ans = -1;
    io.read(x);
    rep(i, 1, n) {
        pll t = query(i, x);
        double tr = t.second == 0 ? -1 : (double(t.first) / t.second);
        if (ans == -1) ratio = tr, ans = i;
        if (ratio < 0) {
            if (tr < 0) {
                if (h[ans] < h[i]) ans = i, ratio = tr;
            } else
                ans = i, ratio = tr;
        } else {
            if (tr < 0) continue;
            if (tr < ratio || (tr == ratio && h[ans] < h[i])) ans = i, ratio = tr;
        }
    }
    io.write(ans, '\n');

    int q;
    io.read(q);
    while (q--) {
        io.read(s), io.read(x);
        pll t = query(s, x);
        // cerr << "q = " << q << ' ' << t.first << ' ' << t.second << endl;
        io.write(t.first, ' '), io.write(t.second, '\n');
    }
    return 0;
}