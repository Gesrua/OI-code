#include <iostream>
#include <cctype>
#include <cstring>
#include <queue>
using std::cerr; using std::min; using std::endl; using std::cout;
char s[20000001]; int stl;
const int N = 10010;
const int M = 400000;
// const int N = 10;
// const int M = 20;
inline void rd(int &x){
	x = 0;
	for (; !isdigit(s[stl]); ++stl);
	for (; isdigit(s[stl]); ++stl) x = (x << 3) + (x << 1) + s[stl] - '0';
}
struct edge {
	int v;
	edge* nxt;
	edge(int _v, edge* _nxt) : v(_v), nxt(_nxt){
	};
	edge () : v(0), nxt(NULL){
	};
};
struct graph {
	edge e[M];
	edge* head[N];
	int cnt;
	inline void addedge(const int &u, const int &v){
		e[cnt] = edge(v, head[u]);
		head[u] = &e[cnt];
		++cnt;
	}
	graph (){
		std::memset(head, NULL, sizeof(head));
		cnt = 0;
	}
} g, gt;
bool flag[10010] = {}, book[10010] = {};
int main(){
	int n, m, u, v, x, y;
	fread(s, 20000000, 1, stdin);
	rd(n); rd(m);
	for (int i = 0; i < m; ++i){
		rd(u); rd(v);
		g.addedge(u, v);
		gt.addedge(v, u);
	}
	rd(x); rd(y);
	std::queue< int > q;
	book[y] = true;
	// for (int i = 1; i <= n; ++i){
	//     cerr << "pnt = " << i << ' ';
	//     for (edge* j = g.head[i]; j != NULL; j = j->nxt){
	//         cerr << j->v << ' ';
	//     }
	//     cerr << endl;
	// }
	q.push(y);
	int cur, cur_a;
	while (!q.empty()){
		cur = q.front();
		q.pop();
		for (edge* i = gt.head[cur]; i != NULL; i = i->nxt){
			if (!book[i->v]){
				q.push(i->v);
				book[i->v] = true;
			}

		}
	}

	for (int i = 1; i <= n; ++i){
		flag[i] = true;
		for (edge* j = g.head[i]; j != NULL; j = j->nxt){
			if (!book[j->v]){
				flag[i] = false;
				break;
			}
		}
		// cerr << endl;
	}


	std::memset(book, 0, sizeof(book));
	q.push(x);
	std::queue< int > ans;
	book[x] = true;
	ans.push(0);

	// for (int i = 1; i <= n; ++i){
	//     cerr << "pnt = " << i << ' ';
	//     for (edge* j = g.head[i]; j != NULL; j = j->nxt){
	//         cerr << j->v << ' ';
	//     }
	//     cerr << endl;
	// }

	while (!q.empty()){
		cur = q.front();
		// cerr << cur << " ptr ";
		cur_a = ans.front() + 1;
		ans.pop();
		q.pop();
		for (edge* i = g.head[cur]; i != NULL; i = i->nxt){
			if (i->v == y){
				cout << cur_a;
				return 0;
			}
			if (!book[i->v] && flag[i->v]){
				// cerr << i->v << ' ';
				q.push(i->v);
				ans.push(cur_a);
				book[i->v] = true;
			}
		}
		// cerr << endl;
	}
	cout << -1;
	return 0;
}