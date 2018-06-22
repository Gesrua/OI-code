#include <bits/stdc++.h>
int n, m, ans, dp[40][40] = {};
int left(int pos){
	if (pos == 1) return n;
	else return pos - 1;
}
int right(int pos){
	if (pos == n) return 1;
	else return pos + 1;
}
int solve(int pos, int k){
	if (dp[pos][k] != -1) return dp[pos][k];
	if (k == 0) return dp[pos][k] = pos == 1 ? 1 : 0;
	return dp[pos][k] = solve(left(pos), k - 1) + solve(right(pos), k - 1);
}
int main(){
	using std::cin;
	using std::cout;
	using std::endl;
	cin >> n >> m;
	std::memset(dp,-1,sizeof(dp));
	dp[1][0] = 1;
	cout << solve(1, m);
	return 0;
}