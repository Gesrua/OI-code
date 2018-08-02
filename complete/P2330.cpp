#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(i, l, r) for (register int i = (l); i <= (r); ++i)
using std::cin; using std::cerr; using std::endl; using std::cout;
const int M = 100100;
const int N = 400;
struct edge {
	int u, v, w;
	edge () : u(0), v(0), w(0){
	}
	edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w){
	}
} e[M];
struct union_find_set {
	int fa[N];
	void init(int n){
		rep(i, 0, n) fa[i] = i;
	}
	int find(const int x){
		return x == fa[x] ? x : fa[x] = find(fa[x]);
	}
	inline void unite(const int x, const int y){
		fa[find(x)] = find(y);
	}
	inline bool chk(const int x, const int y){
		return find(x) == find(y);
	}
} s;
int main(){
	static int n, m, tot = 0;
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	s.init(n);
	m <<= 1;
	for (register int i = 0; i < m; i += 2){
		cin >> e[i].u >> e[i].v >> e[i].w;
		e[i + 1].v = e[i].u, e[i + 1].u = e[i].v, e[i + 1].w = e[i].w;
	}
	std::sort(e, e + m, [](const edge& a, const edge& b){
		return a.w < b.w;
	});
	// for (register int i = 0; i < m; ++i)
	// cerr << e[i].u << ' ' << e[i].v << ' ' << e[i].w << endl;
	int cnt = 1, max = 0;
	for (register int i = 0; cnt < n; ++i){
		if (!s.chk(e[i].u, e[i].v)){
			s.unite(e[i].u, e[i].v);
			max = e[i].w;
			++cnt;
		}
	}
	cout << cnt - 1 << ' ' << max;
	return 0;
}