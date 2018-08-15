#include <cstdio>
#include <iostream>
#include <cstring>
#include <stack>
#include <cmath>
#define travese(u) for (edge* i = g.head[u]; i != NULL; i = i->nxt)
const int N = 10010;
const int M = 50010;
using std::cin; using std::cerr; using std::cout; using std::endl; using std::min;
int cnt = 1, dfn[N], low[N], flag[N], size[N];
bool vis[N], instack[N];
int n, m, tot = 0;
std::stack< int > s;
struct edge {
	int v;
	edge* nxt;
	edge () : v(0), nxt(NULL){
	}
	edge(int _v, edge* _nxt) : v(_v), nxt(_nxt){
	}
};
struct graph {
	edge e[M];
	edge* head[N];
	int cnt, n;
	inline void addedge(const int &u, const int &v){
		e[cnt] = edge(v, head[u]);
		head[u] = &e[cnt];
		++cnt;
	}
	graph (){
		std::memset(head, 0, sizeof(head));
		cnt = 0;
	}
} g, rg;
void tarjan(int u){
	dfn[u] = low[u] = cnt++;
	s.push(u);
	vis[u] = true;
	instack[u] = true;
	travese(u){
		if (!vis[i->v])
			tarjan(i->v),
			low[u] = min(low[u], low[i->v]);
		else if (instack[i->v]) low[u] = min(low[u], dfn[i->v]);
	}
	if (low[u] == dfn[u]){
		int t;
		while ((t = s.top()) != u){
			// cerr << t << ' ';
			flag[t] = tot,
			instack[t] = false,
			++size[tot],
			s.pop();
		}
		flag[u] = tot;
		instack[u] = false;
		++size[tot];
		s.pop();
		// cerr << u << endl;
		++tot;
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		g.addedge(u, v);
	}
	// for (int u = 1; u <= n; ++u){
	//  travese(u){
	//      cerr << u << " -> " << i->v << endl;
	//  }
	// }
	for (int i = 1; i <= n; ++i)
		if (!vis[i]) tarjan(i);
	int ans, cnt = 0, cb[N] = {};


	for (int u = 1; u <= n; ++u){
		travese(u){
			if (flag[i->v] != flag[u]) ++cb[flag[u]];
		}
	}

	for (int i = 0; i < tot; ++i)
		if (!cb[i])
			++cnt,
			ans = size[i];

	// cerr << "cnt = " << cnt << "; tot = " << tot << endl;

	if (cnt != 1) cout << 0;
	else cout << ans;
	return 0;
}