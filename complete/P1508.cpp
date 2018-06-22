#include <iostream>
#include <cmath>
inline int max(int &a, int &b, int &c){
	return std::max(std::max(a, b), c);
}
int a[202][202] = {}, n, m, dp[202][202] = {};
using std::cin; using std::cout; using std::cerr; using std::endl;
int main(){
	cin >> m >> n;
	for (register int i = 1; i <= m; ++i){
		for (register int j = 1; j <= n; ++j){
			cin >> a[i][j];
		}
	}
	// dp[i][j] = max{dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]}
	// dp[m+1][n/2+1]
	for (register int i = 1; i <= m; ++i){
		for (register int j = 1; j <= n; ++j){
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1]) + a[i][j];
		}
	}
	cout << max(dp[m][n / 2], dp[m][n / 2 + 1], dp[m][n / 2 + 2]);
	return 0;
}