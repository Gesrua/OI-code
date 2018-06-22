#include <iostream>
#include <cmath>
#include <cstring>
using std::cerr; using std::endl; using std::max;
const int INF = 210000000;
int n, M, T, dp[101][201][201] = {}, m[101], t[101];
void init(){
	using namespace std;
	memset(dp, -1, sizeof(dp));
	ios::sync_with_stdio(false);
	cin >> n >> M >> T;
	for (int i = 1; i <= n; ++i){
		cin >> m[i] >> t[i];
	}
}
int solve(int k, int v, int u){
	if (v < 0 || u < 0) return -INF;
	if (dp[k][v][u] != -1) return dp[k][v][u];
	//cerr << k << ' ' << v << ' ' << u << endl;
	if (k == 0) return dp[k][v][u] = 0;
	dp[k][v][u] = max(
		solve(k - 1, v, u),
		solve(k - 1, v - m[k], u - t[k]) + 1
		);
	return dp[k][v][u];
}
int main(){
	init();
	std::cout << solve(n, M, T);
	return 0;
}
