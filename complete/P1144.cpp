#include <cstdio>
#include <iostream>
#include <cctype>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
const int MOD = 100003;
using std::min; using std::cin; using std::cerr; using std::cout; using std::endl; using std::isdigit; using std::pair; using std::make_pair;
char s[50000001]; int stl = 0;
inline int mod(int x){
	if (x > 100003) return x - 100003;
	else return x;
	// return x%MOD;
}
inline void rd(int &x){
	x = 0;
	for (; !isdigit(s[stl]); ++stl);
	for (; isdigit(s[stl]); ++stl) x = (x << 3) + (x << 1) + s[stl] - '0';
}
const int N = 2000000;
const int M = 4000000;
const int INF = 2147483647;
struct edge {
	int v;
	edge* nxt;
	edge () : v(0), nxt(NULL){
	}
	edge(int _v, edge* _nxt) : v(_v), nxt(_nxt){
	}
};
edge e[M];
edge* head[N] = {};
int cnt, n;
inline void addedge(const int &u, const int &v){
	e[cnt] = edge(v, head[u]);
	head[u] = &e[cnt];
	++cnt;
}
struct node {
	int s, sum;
	node () : s(0), sum(0){
	}
	node(int _s, int _sum) : s(_s), sum(_sum){
	}
} dis[N];
int main(){
	fread(s, 50000000, 1, stdin);
	std::queue< int > q;
	int u, v, n, m;
	rd(n); rd(m);
	for (int i = 1; i <= m; ++i){
		rd(u); rd(v);
		addedge(u, v);
		addedge(v, u);
	}
	q.push(1);
	dis[1] = node(0, 1);
	int cur;
	while (!q.empty()){
		// if (cur.s != q.top().s;
		cur = q.front();
		q.pop();
		// cerr << cur << ' ';
		for (edge* i = head[cur]; i != 0; i = i->nxt){
			if (dis[i->v].sum == 0){
				dis[i->v] = node(dis[cur].s + 1, dis[cur].sum);
				q.push(i->v);
				continue;
			}
			if (dis[cur].s + 1 == dis[i->v].s){
				dis[i->v].sum = mod(dis[i->v].sum + dis[cur].sum);
				// q.push(i->v);
			}
		}
	}
	for (int i = 1; i <= n; ++i)
		cout << mod(dis[i].sum) << endl;
	return 0;
}