#include <cstdio>
#include <iostream>
#include <cmath>
#include <stack>
using std::cin; using std::cout; using std::cerr; using std::endl; using std::max;

char str[20000001]; int stl = 0;
inline int rd(int& X){
	char ch = X = 0;
	for (; ch < '0' || ch > '9'; ch = str[stl++]);
	for (; ch >= '0' && ch <= '9'; ch = str[stl++]) X = (X << 3) + (X << 1) + ch - '0';
	return X;
}

struct edge {
	int v;
	edge* nxt;
	edge(int _v, edge* _nxt){
		v = _v, nxt = _nxt;
	}
	edge (){
		v = 0, nxt = NULL;
	}
} e[1000010];
edge* p[500010];
int f[500010][20], depth[500010];
bool flag[500010] = {};
int main(){
	fread(str,20000000,1,stdin);
	// std::ios::sync_with_stdio(false);
	int n, m, u, v, root;
	// scanf("%d%d%d", &n, &m, &root);
	rd(n); rd(m); rd(root);
	// cin >> n >> m >> root;
	register edge* i = &e[0];
	for (register int j = 1; j < n; ++j){
		// cin >> u >> v;
		// scanf("%d%d", &u, &v);
		rd(u); rd(v);
		*i = edge(v, p[u]);
		p[u] = i;
		++i;
		*i = edge(u, p[v]);
		p[v] = i;
		++i;
	}
	f[root][0]  = f[root][1] = 0;
	std::stack< int > s;
	s.push(root);
	depth[root] = 0;
	// cerr << "end\n";
	while (!s.empty()){
		register int now = s.top();
		s.pop();
		// cerr << "cur "<< now << endl;
		flag[now] = true;
		for (register int i = 1; 1 << i <= depth[now]; ++i){
			f[now][i] = f[f[now][i - 1]][i - 1];
		}
		// cerr << "push\n";
		for (register edge* i = p[now]; i != NULL; i = i->nxt){
			if (flag[i->v]) continue;
			// cerr << i->v << ' ';
			s.push(i->v);
			f[i->v][0] = now;
			// cerr << i->v << " 0  = " << now << endl;
			depth[i->v] = depth[now] + 1;
		}

	}
	// cerr << "end\n";
	// lim = std::log2(lim);
	for (int k = 0; k < m; ++k){
		register int u, v;
		// cin >> u >> v;
		rd(u); rd(v);
		// scanf("%d%d", &u, &v);
		int tmp = depth[u] - depth[v]; // u 的深度大于 v
		if (tmp < 0){std::swap(u, v); tmp = -tmp;}
		for (register int i = 0; i < 20; ++i){
			if ((1 << i) & tmp){
				u = f[u][i];
			}
		}
		if (u == v){
			cout << u << endl;
			continue;
		}
		for (register int i = 19; i >= 0; --i){
			if (f[u][i] != f[v][i]){
				u = f[u][i];
				v = f[v][i];
				// break;
			}
		}
		printf("%d\n", f[u][0]);
		// cout << f[u][0] << endl;
		// cerr << u << ' ' << v << endl;
	}
	// cerr << "end\n";
	return 0;
}