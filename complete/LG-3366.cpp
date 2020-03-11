#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iostream>
char s[20000001];
int stl;
inline void rd(int &x) {
    x = 0;
    for (; !isdigit(s[stl]); ++stl)
        ;
    for (; isdigit(s[stl]); ++stl) x = (x << 3) + (x << 1) + s[stl] - '0';
}
int c[5010];
struct edge {
    int u, v, w;
    bool operator<(edge &b) { return w < b.w; }
} e[400020];
int find(int x) { return x == c[x] ? x : c[x] = find(c[x]); }
int main() {
    int n, m;
    fread(s, 20000000, 1, stdin);
    rd(n);
    rd(m);
    for (int i = 0; i <= n; ++i) {
        c[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        rd(e[i].u);
        rd(e[i].v);
        rd(e[i].w);
    }
    std::sort(e, e + m);
    int sum = 0, cnt = 0;
    for (edge *i = &e[0]; i < &e[m]; ++i) {
        // std::cerr << (i - &e[0]) << ' ';
        if (find(i->u) == find(i->v)) continue;
        c[find(i->u)] = find(i->v);
        sum += i->w;
        ++cnt;
    }
    // std::cerr << cnt << std::endl;
    if (cnt != n - 1)
        std::cout << "orz";
    else
        std::cout << sum;
    return 0;
}