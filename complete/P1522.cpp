const int INF = 100000000;
#include <cctype>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::isdigit;
using std::max;
using std::min;
using std::sqrt;
struct point {
    int x, y;
    point() : x(0), y(0) {}
    point(int _x, int _y) : x(_x), y(_y) {}
    inline double dist(const point& b) { return sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y)); }
} p[160];
int fa[160];
int find(const int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
inline void unity(const int x, const int y) { fa[x] = find(fa[y]); }
double g[160][160], dis[160], g_dis[160][160];
int main() {
    int n;
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i].x >> p[i].y;
        fa[i] = i;
    }
    for (int i = 1; i <= n; ++i) {
        char c;
        for (int j = 1; j <= n; ++j) {
            cin >> c;
            g_dis[j][i] = g_dis[i][j] = p[i].dist(p[j]);
            if (c == '1') {
                g[i][j] = g[j][i] = g_dis[j][i];
                unity(i, j);
            } else
                g[i][j] = g[j][i] = INF;
        }
        g[i][i] = 0;
    }

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (g[i][j] > g[i][k] + g[k][j]) g[i][j] = g[i][k] + g[k][j];

    double ans = INF, tmp = 0;

    for (int i = 1; i <= n; ++i) {
        dis[i] = 0;
        for (int j = 1; j <= n; ++j)
            if (g[i][j] != INF) dis[i] = max(g[i][j], dis[i]);
        tmp = std::max(tmp, dis[i]);
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (find(i) != find(j)) ans = min(dis[i] + dis[j] + g_dis[i][j], ans);

    cout.setf(std::ios::fixed);
    cout << std::setprecision(6) << std::max(ans, tmp);
    return 0;
}