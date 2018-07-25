#include <cstdio>
#include <iostream>
#include <queue>
#include <cctype>
#include <cmath>
using std::isdigit; using std::cin; using std::cout; using std::cerr; using std::isupper; using std::endl; using std::min;
int e[100][100] = {};
int degree[100];
inline int trans(char x){
	if (isupper(x)) return x - 'A' + 1;
	else return x - 'a' + 27;
}
inline char detrans(int x){
	if (x < 27) return char(x + 'A' - 1);
	else return char(x + 'a' - 27);
}
bool flag[100] = {};
int ans[100000], cur;
int judge();
void dfs(int u){
	// cerr << u;
	for (int v = 1; v < 60; ++v){
		if (e[u][v]){
			e[u][v] = 0;
			e[v][u] = 0;
			dfs(v);
		}
	}
	ans[cur--] = u;
	// ans[cur--] = u;
}
int cnt, start;
int main(){
	int n;
	std::ios::sync_with_stdio(false);
	cin >> n;
	char x, y;
	int u, v;
	for (int i = 0; i < n; ++i){
		cin >> x >> y;
		u = trans(x), v = trans(y);
		flag[u] = true, flag[v] = true;
		++degree[u], ++degree[v];
		e[u][v] = 1, e[v][u] = 1;
	}

	if (!judge()){ cout << "No Solution"; return 0; }
	cur = n;
	dfs(start);
	for (int i = 0; i <= n; ++i){
		cout << detrans(ans[i]);
	}
	return 0;
}
int judge(){
	int odd = 100, even = 100;
	for (int i = 1; i < 100; ++i){
		if (degree[i] & 1) odd = min(i, odd);
		else even = min(i, even);
	}

	for (int i = 1; i < 100; ++i){
		if (flag[i]){
			std::queue<int> q;
			q.push(i);
			flag[i] = false;
			while (!q.empty()){
				int u = q.front();
				q.pop();
				for (int v = 1; v <= 100; ++v){
					if (flag[v] && e[u][v]){
						flag[v] = false;
						q.push(v);
					}
				}
			}
			break;
		}
	}
	// start = 100;
	for (int i = 1; i < 100; ++i)
		if (flag[i]) return 0;
	// int cnt = 0;
	for (int i = 1; i < 100; ++i)
		if (degree[i] & 1) ++cnt;

	// cerr << detrans(even) << ' ' << detrans(odd) << endl;
	if (cnt != 0 && cnt != 2) return 0;
	if (cnt == 0) start = even;
	if (cnt == 2) start = odd;
	return 1;
}