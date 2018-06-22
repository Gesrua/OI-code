#include <bits/stdc++.h>
int map[31][31], n, cur = 2;
bool check(int t1, int t2){
	if (t1 < 1 || t2 < 1 || t1 > n || t2 > n) return false;
	return true;
}
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

int main(){
	std::memset(map,-1,sizeof(map));
	bool flag;
	std::cin >> n;
	int i, j, t1, t2;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			std::cin >> map[i][j];
	std::queue<int> x;
	std::queue<int> y;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++){
			if (map[i][j] == 0){
				flag = true;
				cur++;
				x.push(i);
				y.push(j);
				map[i][j] = cur;
				while (!x.empty()){
					for (i = 0; i < 4; i++){
						t1 = x.front() + dir[i][0];
						t2 = y.front() + dir[i][1];
						if (map[t1][t2] == -1) flag = false;
						if (!check(t1,t2)) continue;
						if ((map[t1][t2] == 0) && (map[x.front()][y.front()] != map[t1][t2])){
							map[t1][t2] = cur;
							x.push(t1);
							y.push(t2);
						}
					}
					x.pop();
					y.pop();
				}
			}
			if (flag){
				for (i = 1; i <= n; i++){
					for (j = 1; j <= n; j++)
						if (map[i][j] == cur){
							std::cout << "2 ";
						}
						else{
							if (map[i][j] == 1)
								std::cout << "1 ";
							else std::cout << "0 ";
						}
					std::cout << std::endl;
				}
				return 0;
			}
		}
	return 0;
}
