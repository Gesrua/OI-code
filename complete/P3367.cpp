#include <cstdio>
using std::scanf;
int fa[10001];
int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
int main() {
    int n, m, z, x, y;
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; ++i) fa[i] = i;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &z, &x, &y);
        if (z == 1) {
            fa[find(x)] = fa[find(y)];
        }
        if (z == 2) {
            if (find(x) == find(y))
                std::puts("Y");
            else
                std::puts("N");
        }
    }
    return 0;
}
