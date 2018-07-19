#include <iostream>
#include <cstring>
#include <iomanip>
bool flag[30] = {};
int n, r, s[30];
using std::cout; using std::endl; using std::cerr;
void dfs(int x){
	if (x > r){
		for (int i = 1; i <= r; ++i){
			cout << std::setw(3) << s[i];
		}
		cout << endl;
		return;
	}
	for (int i = s[x - 1] + 1; i <= n; ++i){
		if (flag[i]){
			// cerr << x << ' ' << i << endl;
			flag[i] = false;
			s[x] = i;
			dfs(x + 1);
			flag[i] = true;
		}
	}
}
int main(){
	cout.flags(std::ios::right);
	std::memset(flag, 1, sizeof(flag));
	std::cin >> n >> r;
	dfs(1);
	return 0;
}