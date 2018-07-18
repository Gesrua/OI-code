#include <iostream>
#include <vector>
#include <stack>
using std::cin; using std::cout; using std::cerr; using std::endl; using std::min; using std::max;
struct edge {
	int v, w;
	edge* nxt;
	edge (){
		v = 0;
		w = 0;
		nxt = NULL;
	}
	edge(int _v, int _w, edge* _nxt){
		v = _v;
		w = _w;
		nxt = _nxt;
	}
} e[200003];
edge* p[100003] = {};
int a[100003] = {};
bool flag[100003] = {};
int main(){
	int n, m, u, v, w, pos = 0;
	std::ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i < n; ++i){
		cin >> u >> v >> w;
		e[++pos] = edge(v, w, p[u]);
		p[u] = &e[pos];
		e[++pos] = edge(u, w, p[v]);
		p[v] = &e[pos];
	}
	std::stack< int > s;
	s.push(1);
	int now;
	while (!s.empty()){
		now = s.top();
		// cerr << now << endl;
		flag[now] = true;
		s.pop();
		for (edge* i = p[now]; i != NULL; i = i->nxt){
			// cerr << i << ' ' << now << ' ' << e[i].v << endl;
			if (flag[i->v]) continue;
			a[i->v] = a[now] ^ (i->w);
			s.push(i->v);
		}
	}
	cin >> m;
	for (int i = 0; i < m; ++i){
		cin >> u >> v;
		cout << (a[u] ^ a[v]) << endl;
	}
	return 0;
}
