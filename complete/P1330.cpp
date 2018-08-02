#include <iostream>
#include <cmath>
#include <cctype>
#include <deque>
#include <cstring>
const int INF = 2100000000;
using std::isdigit; using std::cout; using std::min; using std::cerr; using std::endl;
char s[20000001]; int stl = 0;
inline void rd(int &x){
	x = 0;
	for (; !isdigit(s[stl]); ++stl);
	for (; isdigit(s[stl]); ++stl) x = (x << 3) + (x << 1) + s[stl] - '0';

}
struct edge {
	int v;
	edge* nxt;
	edge (){
		v = 0, nxt = NULL;
	}
	edge(int _v, edge* _nxt){
		v = _v, nxt = _nxt;
	}
} e[200100];
edge* p[10100] = {};
int n, m;
bool flag[10100] = {}, book[10100] = {}, map_book[10100];
int bfs(int x){
	if (map_book[x]) return 0;
	std::memset(flag, 0, sizeof(flag));
	std::deque< int > q;
	flag[x] = 1;
	q.push_back(x);
	int now;
	map_book[x] = true;
	bool possi = true;
	while (!q.empty()){
		now = q.front();
		q.pop_front();
		if (flag[now]){
			for (edge* i = p[now]; i != NULL; i = i->nxt){
				if (flag[i->v]){
					possi = false;
				}
				if (!map_book[i->v]){
					q.push_back(i->v);
					map_book[i->v] = true;
				}
			}
		}else{
			for (edge* i = p[now]; i != NULL; i = i->nxt){
				if (map_book[i->v]){
					if (flag[i->v] != true){
						possi = false;
					}
					continue;
				}
				map_book[i->v] = true;
				q.push_back(i->v);
				flag[i->v] = true;
			}
		}

	}

	int ans = 0, t1 = 0;
	if (possi)
		for (int i = 1; i <= n; ++i){
			if (flag[i]) ++t1;
		}
	else t1 = INF;

	possi = true;
	std::memset(book, 0, sizeof(book));
	std::memset(flag, 0, sizeof(flag));
	book[x] = true;
	q.push_back(x);
	while (!q.empty()){
		now = q.front();
		q.pop_front();
		if (flag[now]){
			for (edge* i = p[now]; i != NULL; i = i->nxt){
				if (flag[i->v]){
					possi = false;
					q.clear();
					break;
				}
				if (!book[i->v]) q.push_back(i->v);
			}
		}else{
			for (edge* i = p[now]; i != NULL; i = i->nxt){
				if (book[i->v]){
					if (flag[i->v] != true){
						possi = false;
						q.clear();
						break;
					}
					continue;
				}
				book[i->v] = true;
				q.push_back(i->v);
				flag[i->v] = true;
			}
		}

	}
	int t2 = 0;
	if (possi)
		for (int i = 1; i <= n; ++i){
			if (flag[i]) ++t2;
		}
	else t2 = INF;

	ans = min(t1, t2);
	if (ans == INF) return -1;
	else return ans;
}
int main(){
	fread(s, 20000000, 1, stdin);
	int u, v;
	rd(n); rd(m);
	for (register edge* i = &e[0]; i < &e[m << 1];){
		rd(u); rd(v);
		*i = edge(v, p[u]);
		p[u] = i;
		++i;
		*i = edge(u, p[v]);
		p[v] = i;
		++i;
	}

	int t, sum = 0;
	for (int i = 1; i <= n; ++i){
		t = bfs(i);
		if (t == -1){
			cout << "Impossible";
			return 0;
		}
		sum += t;
	}
	cout << sum;
	return 0;
}
