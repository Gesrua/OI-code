#include <bits/stdc++.h>
int n, m;
struct cell
{
	int v, p;
} a[26];
int main(){
	using std::cin;
	cin >> n >> m;
	int t, i, dp[30001] = {}, j;
	for (i = 0; i < m; ++i){
		cin >> a[i].v >> t;
		a[i].p = a[i].v * t;
		for (j = n; j >= a[i].v; j--){
			if ((j - a[i].v == 0) && (dp[j] < a[i].p)) dp[j] = a[i].p;
			if (dp[j - a[i].v] == 0) continue;
			if (dp[j] < dp[j - a[i].v] + a[i].p) dp[j] = dp[j - a[i].v] + a[i].p;
		}
	}
	int ans = 0;
	for (i = 1; i <= n; i++)
		if (ans < dp[i]) ans = dp[i];
	std::cout << ans;
	return 0;
}