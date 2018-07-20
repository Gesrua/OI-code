// 必须用 C++11 编译
#include <cstdio>
#include <iostream>
#include <cmath>
using std::cin; using std::cout; using std::cerr; using std::endl; using std::cbrt;
int s[6], lim;
void dfs(int cnt, int val){
	if (val < 0) return;
	if (cnt == 3){
		int x = 1e-3 + cbrt(val);
		if (x < s[2] || x * x * x != val) return;
		std::printf("Cube = %d, Triple = (%d,%d,%d)\n", s[5], s[1], s[2], x);
		return;
	}
	for (int i = s[cnt - 1]; i <= s[5]; ++i){
		s[cnt] = i;
		dfs(cnt + 1, val - i * i * i);
	}
}
int main(){
	int n;
	cin >> n;
	lim = n * n * n;
	s[0] = 2;
	for (int i = 2; i <= n; ++i){
		lim = i * i * i;
		s[5] = i;
		dfs(1, lim);
	}
	return 0;
}