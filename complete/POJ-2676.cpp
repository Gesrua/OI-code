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

const int belong[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 2, 2, 2, 3, 3, 3}, {0, 1, 1, 1, 2, 2, 2, 3, 3, 3}, {0, 1, 1, 1, 2, 2, 2, 3, 3, 3}, {0, 4, 4, 4, 5, 5, 5, 6, 6, 6},
                            {0, 4, 4, 4, 5, 5, 5, 6, 6, 6}, {0, 4, 4, 4, 5, 5, 5, 6, 6, 6}, {0, 7, 7, 7, 8, 8, 8, 9, 9, 9}, {0, 7, 7, 7, 8, 8, 8, 9, 9, 9}, {0, 7, 7, 7, 8, 8, 8, 9, 9, 9}};

const int N = 9;

int blk[N + 1], hang[N + 1], lie[N + 1];
int out[N + 1][N + 1];
pii q[N * N];

int siz = 0;
bool sld = 0;

inline int lowbit(int x) { return x & (-x); }

inline void set(int &a, int x) { a |= x; }
inline void unset(int &a, int x) { a ^= x; }

int H[37];

void print_out() {
    rep(i, 1, N) {
        rep(j, 1, N) {
            // if (out[i][j] > (1 << 8))
            //     io.write(-1, ' ');
            // else if (out[i][j] == 0)
            //     io.write(0, ' ');
            // else
            //     io.write(H[out[i][j] % 37] + 1, ' ');
            io.write(H[out[i][j] % 37] + 1);
        }
        io.push('\n');
    }
    return;
}

void dfs(int i) {
    if (i == siz + 1) {
        sld = 1;
        print_out();
        return;
    }
    int x = q[i].first, y = q[i].second;
    int st = ~(blk[belong[x][y]] | hang[x] | lie[y]);
    int &a = blk[belong[x][y]], &b = hang[x], &c = lie[y];
    while (st && !sld) {
        int cur = lowbit(st);
        if (cur > (1 << 8)) return;
        set(a, cur), set(b, cur), set(c, cur);
        out[x][y] = cur;
        dfs(i + 1);
        unset(a, cur), unset(b, cur), unset(c, cur);
        st -= cur;
    }
}

#define clear(x) std::memset(x, 0, sizeof(x))

void work() {
    siz = sld = 0;
    clear(blk), clear(hang), clear(lie);
    rep(i, 1, N) {
        rep(j, 1, N) {
            char c;
            io.read(c);
            if (c == '0')
                q[++siz] = {i, j};
            else {
                out[i][j] = (1 << (c - '0' - 1));
                blk[belong[i][j]] |= (1 << (c - '0' - 1));
                hang[i] |= (1 << (c - '0' - 1));
                lie[j] |= (1 << (c - '0' - 1));
            }
        }
    }
    // print_out();
    // io.push('\n');
    dfs(1);
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    for (int i = 0; i < 11; i++) H[(1 << i) % 37] = i;
    int T;
    io.read(T);
    while (T--) {
        work();
    }
    return 0;
}