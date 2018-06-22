#include <bits/stdc++.h>
struct cell {
	int dir, x, y, step;
} t;
int n, m, dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
bool check(int a,int b){
	if (a < 0 || a > n || b < 0 || b > m) return false;
	return true;
}
int main(){
	bool map[100][100] = {};
	int i, j, k;
	std::cin >> n >> m;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			map[i][j] = true;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++){
			std::cin >> k;
			if (k == 1){
				map[i][j] = map[i - 1][j] = map[i - 1][j - 1] = map[i][j - 1] = false;
			}
		}
	cell start, end;
	char c;
	std::cin >> start.x >> start.y >> end.x >> end.y >> c;
	if (c == 'E') start.dir = 0;
	if (c == 'S') start.dir = 1;
	if (c == 'W') start.dir = 2;
	if (c == 'N') start.dir = 3;
	std::queue<cell> q;
	start.step = 0;
	q.push(start);
	while (!q.empty()){
		t = q.front();
		if ((t.x == end.x) && (t.y == end.y)){
			std::cout << t.step;
			return 0;
		}
	}
	std::cout << -1;
	return 0;
}
