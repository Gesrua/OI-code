#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
int n, m, ans, dp[200001];
std::vector<int> map[200001];
void init(){
	using namespace std;
	int u, v;
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i){
		scanf("%d%d", &u, &v);
		map[v].push_back(u);
		map[u].push_back(v);
	}
}
int solve(int k){
	if (dp[k] != -1) return dp[k];
	dp[k] = 0;
	int& ans = dp[k];
	for (auto i = map[k].begin(); i != map[k].end(); ++i){
		if (*i < k) ans = std::max(ans, solve(*i) + 1);
	}
	return ans;
}
int main(){
	init();
	int ans = 0;
	for (int i = 1; i <= n; ++i){
		//ans = std::max(solve(i, 0), ans);
		ans = std::max(ans, int((solve(i) + 1) * map[i].size()));
		//std::cout << solve(i) << ' ';
	}
	std::cout << ans;
	return 0;
}
