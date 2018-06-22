#include <bits/stdc++.h>
struct cell {
	bool flag;
	int x, y, s;
};
struct node {
	bool flag;
	int x, y;
	bool operator < (node const& _A) const {
		if (x == _A.x){
			if (y == _A.y){
				return int(flag) < int(_A.flag);
			}
			else return y < _A.y;
		}
		else return x < _A.x;
	}
};
int main(int argc, char const *argv[]){
	int h, w, d, r, i, j;
	std::cin >> h >> w >> d >> r;
	bool map[1002][1002] = {};
	char c;
	for (i = 1; i <= h; i++)
		for (j = 1; j <= w; j++){
			std::cin >> c;
			if (c == '.') map[i][j] = true;
		}
	std::queue<cell> q;
	cell t;
	t.flag = false;
	t.x = 1;
	t.y = 1;
	t.s = 0;
	q.push(t);
	bool book[1010][1010][2] = {};
	int dir[5][2] = {{0,1},{0,-1},{1,0},{-1,0},{d,r}};
	while (!q.empty()){
		t = q.front();
		if ((t.x == h) && (t.y == w)){
			std::cout << t.s;
			return 0;
		}
		i = 5;
		if (t.flag) i = 4;
		while (i > 0){
			t = q.front();
			i--;
			t.x = t.x + dir[i][0];
			t.y = t.y + dir[i][1];
			if (i == 4) t.flag = true;
			if (!((t.x > 0) && (t.y > 0) && (t.x <= h) && (t.y <= w) && (map[t.x][t.y]))) continue;

			if (!book[t.x][t.y][int(t.flag)]){
				book[t.x][t.y][int(t.flag)] = true;
				t.s++;
				q.push(t);
			}
		}
		q.pop();
	}
	std::cout << -1;
	return 0;
}
