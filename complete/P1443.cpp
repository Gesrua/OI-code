#include <iostream>
#include <iomanip>
#include <cstring>
#include <queue>
struct cell {
	int x, y, step;
} t, t2;
int dir[8][2] = {{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2}};
int main(){
	int n, m, i,x,y, a[401][401];
	using namespace std;
	queue<cell> q;
	cin >> n >> m >> x >> y;
	memset(a, -1, sizeof(a));
	t.x = x;
	t.y = y;
	t.step = 0;
	a[x][y] = 0;
	q.push(t);
	while (!q.empty()){
		t2 = q.front();
		q.pop();
		for (i = 0; i < 8; i++){
			t = t2;
			t.x += dir[i][0];
			t.y += dir[i][1];
			if ((t.x > 0) && (t.y > 0) && (t.x <= n) && (t.y <= m) && a[t.x][t.y] == -1){
				// if (a[t.x][t.y] == -1){
				a[t.x][t.y] = t.step = t2.step + 1;
				q.push(t);
			}
			// else a[t.x][t.y] = min(a[t.x][t.y], a[t2.x][t2.y]+1);
			// else if (a[t.x][t.y] > a[t2.x][t2.y] + 1){
			// a[t.x][t.y] = a[t2.x][t2.y] + 1;
			// q.push(t);
			// }
			// }
		}
	}
	for (i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++)
			cout << setw(5) << left << a[i][j];
		cout << endl;
	}
	return 0;
}
