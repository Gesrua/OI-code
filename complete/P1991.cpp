#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#define rep(i, l, r) for (register int i = (l); i <= (r); ++i)
using std::cin; using std::cerr; using std::cout; using std::endl;
struct point {
	int x, y;
	point (){
		x = 0, y = 0;
	}
	point(int _x, int _y){
		x = _x, y = _y;
	}
	inline double dist(const point& b){
		return std::sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
	}
} p[1000];
int fa[500];
int find(int x){
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
struct edge {
	int u, v;
	double w;
} e[700000];
int main(){
	std::ios::sync_with_stdio(false);
	int n, s, tot = 0;
	cin >> s >> n;
	rep (i, 1, n) cin >> p[i].x >> p[i].y;
	rep (i, 1, n)
	rep (j, 1, n)
	e[tot].u = i,
	e[tot].v = j,
	e[tot].w = p[i].dist(p[j]),
	++tot;

	std::sort(e, e + tot, [](const edge& x, const edge& y){
		return x.w < y.w;
	});

	--tot;
	rep (i, 0, n) fa[i] = i;
	double sum = 0;
	for (int i = 0; s < n; ++i)
		if (find(e[i].u) != find(e[i].v))
			fa[find(e[i].u)] = find(e[i].v),
			++s,
			sum = e[i].w;
	cout.setf(std::ios::fixed);
	cout << std::setprecision(2) << sum;
	return 0;
}