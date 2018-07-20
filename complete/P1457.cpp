#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
using std::cin; using std::cout; using std::cerr; using std::endl; using std::max;
int m, n, hang, lie, size[50000] = {};
int map[200][200] = {};
void color(int x, int y, int c){
	if (x < 2 || y < 2 || x > hang || y > lie) return;
	if (map[x][y] != 1) return;
	map[x][y] = c;
	++size[c];
	if (map[x + 1][y] == 0) color(x + 2,y,c);
	if (map[x - 1][y] == 0) color(x - 2,y,c);
	if (map[x][y + 1] == 0) color(x, y + 2, c);
	if (map[x][y - 1] == 0) color(x, y - 2, c);
}
int main(){
	int x;
	std::ios::sync_with_stdio(false);
	// n hang
	// m lie
	cin >> m >> n;
	hang = n * 2; lie = m * 2;
	std::memset(map, -1, sizeof(map));
	for (int i = 2; i <= hang; i += 2)
		for (int j = 2; j <= lie; j += 2){
			map[i][j] = 1;
			cin >> x;
			if (!(x & 4)) map[i][j + 1] = 0;
			if (!(x & 8)) map[i + 1][j] = 0;
		}


	int cnt = 1;
	for (int i = 2; i <= hang; i += 2)
		for (int j = 2; j <= lie; j += 2){
			if (map[i][j] == 1){
				++cnt;
				color(i, j, cnt);
			}
		}
	cout << cnt - 1 << endl;
	int ans = size[2];
	for (int i = 3; i <= cnt; ++i){
		ans = max(ans, size[i]);
	}
	cout << ans << endl;
	// for (int i = 1; i <= hang+1; ++i){
	//     for (int j = 1; j <= lie+1; ++j){
	//         cout << std::setw(3) << map[i][j];
	//     }
	//     cout << endl;
	// }
	ans = 0;
	int y, pos, now;
	for (int i = 2; i <= hang; i += 2){
		for (int j = 2; j <= lie; j += 2){
			// east
			if (j + 2 <= lie && map[i][j + 1] == -1){
				if (map[i][j] != map[i][j + 2]) now = size[map[i][j]] + size[map[i][j + 2]];
				else now = size[map[i][j]];
				if (ans < now)
					ans = now, pos = 1, x = i, y = j;
				else
				if (ans == now){
					if (j < y || (j == y && x < i)) pos = 1, x = i, y = j;
				}
			}

			// north
			if (i > 2 && map[i - 1][j] == -1){
				if (map[i][j] != map[i - 2][j]) now = size[map[i][j]] + size[map[i - 2][j]];
				else now = size[map[i][j]];
				if (ans < now)
					pos = 0, x = i, y = j, ans = now;
				else if (ans == now)
					if (j < y || (j == y && x < i) || (x == i && y == j && pos == 1))
						pos = 0, x = i, y = j;
			}
		}
	}
	cout << ans << endl;
	if (pos == 1){
		cout << x / 2 << ' ' << y / 2 << " E";
	}else{
		cout << x / 2 << ' ' << y / 2 << " N";
	}
	return 0;
}