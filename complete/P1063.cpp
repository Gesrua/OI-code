#include <iostream>
#include <cmath>
using std::max;
using std::cin; using std::cerr; using std::cout; using std::endl;
int n, dp[205][205] = {};
struct node {
	int m, n;
} a[205];
inline int add(int i, int k, int j){
	if (i >= k || k > j) return 0;
	return a[i].m * a[k].m * a[j].n;
}
int main(){
	cin >> n;
	for (int i = 1; i <= n; ++i){
		cin >> a[i].m;
		a[i + n].m = a[i].m;
		a[i - 1].n = a[i].m;
		a[i + n - 1].n = a[i].m;
	}
	a[n << 1].n = a[1].m;
	for (register int j = 1; j < n; ++j){
		for (register int i = 1; i < 2 * n - j + 1; ++i){
			for (register int k = i; k < i + j; ++k){
				int l = i, r = i + j;
				dp[l][r] = max(dp[l][r], dp[l][k] + dp[k + 1][r] + add(l, k + 1, r));
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i){
		if (ans < dp[i][i + n - 1]) ans = dp[i][i + n - 1];
	}
	cout << ans;
	return 0;
}