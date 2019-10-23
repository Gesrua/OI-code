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
typedef unsigned long long ull;

using std::cin;
using std::cout;

char c[510];

// T[a, b] < T[x, y]
bool cmp(int a, int b, int x, int y) {
    // cerr << a << ' ' << b << ' ' << x << ' ' << y << endl;
    if (b < 1) return 1;
    while (c[a] == '0' && a <= b) ++a;
    while (c[x] == '0' && x <= y) ++x;
    if (b - a < y - x) return 1;
    if (b - a > y - x) return 0;
    rep(i, 0, b - a) if (c[a + i] < c[x + i]) return 1;
    else if (c[a + i] > c[x + i]) return 0;
    return 0;
}

int f[510], pre[510], g[510];

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0), cout.tie(0);
    while (cin >> (c + 1)) {
        std::memset(f, 0, sizeof(f));
        std::memset(g, 0, sizeof(g));
        int n = strlen(c + 1);
        rep(i, 1, n) per(j, i - 1, 0) if (cmp(f[j], j, j + 1, i)) {
            f[i] = j + 1;
            break;
        }
        int brk = f[n];
        // cerr << "brk " << f[n] << ' ' << n << endl;
        g[brk] = n;
        for (int i = brk - 1; i > 0 && c[i] == '0'; --i) g[i] = n;

        if (g[1] == n) {
            cout << (c + 1) << endl;
            continue;
        }

        per(i, brk - 1, 1) per(j, brk, i + 1) if (!g[i] && cmp(i, j - 1, j, g[j])) {
            // cerr << "upd " << i << ' ' << j - 1 << ' ' << j << ' ' << g[j] << endl;
            g[i] = j - 1;
            break;
        }
        // rep(i, 1, n) { cerr << g[i] << ' '; }
        // cerr << endl;
        int ptr = 1;
        while (1) {
            rep(i, ptr, g[ptr]) cout << c[i];
            // assert(ptr <= g[ptr]);
            ptr = g[ptr] + 1;
            if (ptr > n) break;
            cout << ',';
        }
        cout << endl;
    }

    return 0;
}