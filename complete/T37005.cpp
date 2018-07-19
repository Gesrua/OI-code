#include <iostream>
#include <cstring>
using std::cin; using std::cout; using std::cerr; using std::endl; using std::max; using std::min;
int c[30][30], n, ans = 2100000000;
bool flag[30];
void dfs(int x, int val){
	if (val > ans) return;
	if (x > n){
		ans = val;
		return;
	}
	for (int i = 1; i <= n; ++i){
		if (flag[i]){
			flag[i] = false;
			dfs(x + 1, val + c[x][i]);
			flag[i] = true;
		}
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	cin >> n;
	std::memset(flag, 1, sizeof(flag));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> c[i][j];
	dfs(1, 0);
	cout << ans;
	return 0;
}