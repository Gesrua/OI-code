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

int a[1010][1010], c1[1010][1010], c2[1010][1010], d1[1010][1010], d2[1010][1010];

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    int n, m, k;
    io.read(n), io.read(m), io.read(k);
    std::deque<pii> mx, mn;
    // first->time, second->value
    rep(i, 1, n) {
        mx.clear(), mn.clear();
        rep(j, 1, m) {
            io.read(a[i][j]);
            while (mx.size() && mx.front().first <= j - k) mx.pop_front();
            while (mn.size() && mn.front().first <= j - k) mn.pop_front();
            while (mx.size() && mx.back().second <= a[i][j]) mx.pop_back();
            while (mn.size() && mn.back().second >= a[i][j]) mn.pop_back();
            mx.push_back({j, a[i][j]});
            mn.push_back({j, a[i][j]});
            c1[i][j] = mx.front().second;
            c2[i][j] = mn.front().second;
        }
    }
    rep(j, 1, m) {
        mx.clear(), mn.clear();
        rep(i, 1, n) {
            while (mx.size() && mx.front().first <= i - k) mx.pop_front();
            while (mn.size() && mn.front().first <= i - k) mn.pop_front();
            while (mx.size() && mx.back().second <= c1[i][j]) mx.pop_back();
            while (mn.size() && mn.back().second >= c2[i][j]) mn.pop_back();
            mx.push_back({i, c1[i][j]});
            mn.push_back({i, c2[i][j]});
            d1[i][j] = mx.front().second;
            d2[i][j] = mn.front().second;
        }
    }
    int ans = 2147483647;
    rep(i, k, n) rep(j, k, m) ans = std::min(ans, d1[i][j] - d2[i][j]);
    io.write(ans);
    return 0;
}