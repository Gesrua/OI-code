#include <cstdio>
#include <iostream>
#include <cctype>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
using std::min; using std::cin; using std::cerr; using std::cout; using std::endl; using std::isdigit; using std::pair; using std::make_pair;
typedef pair<int, int> pii;
const int N = 300;
const int M = 50000;
const int INF = 100000000;
char s[50000001]; int stl = 0;
int dis[300][300] = {};
inline void rd(int &x){
	x = 0;
	for (; !isdigit(s[stl]); ++stl);
	for (; isdigit(s[stl]); ++stl) x = (x << 3) + (x << 1) + s[stl] - '0';
}
struct edge {
	int v, w;
	edge* nxt;
	edge () : v(0), w(0), nxt(NULL){
	}
	edge(int _v, int _w, edge* _nxt) : v(_v), w(_w), nxt(_nxt){
	}
};
int g[300][300];
int main(){
	int n, m, u, v, w;
	fread(s, 50000000, 1, stdin);
	rd(n); rd(m);
	int t[300];
	for (int i = 0; i < n; ++i) rd(t[i]);
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= n; ++j)
			g[i][j] = INF;
	for (int i = 1; i <= m; ++i){
		rd(u); rd(v); rd(w);
		g[u][v] = w;
		g[v][u] = w;
	}
	int q, tmp, k = 0;
	rd(q);
	// bool vis[300] = {};
	for (int l = 1; l <= q; ++l){
		int x, y;
		rd(x); rd(y);
		rd(tmp);
		while (t[k] <= tmp && k < n){
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			++k;
		}
		if (g[x][y] == INF || t[x] > tmp || t[y] > tmp) cout << "-1\n";
		else cout << g[x][y] << endl;
	}
	return 0;
}