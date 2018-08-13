#include <iostream>
#include <string>
int a[200], dp[200][200];
extern inline bool match(const int x, const int y){
	return ((x == 0) && (y == 3)) || (x == 1 && y == 2) ? true : false;
}
int main(){
	std::string s;
	std::cin >> s;
	for (int i = 0; i < s.size(); ++i){
		switch (s[i]){
		case '[': a[i + 1] = 1; break;
		case ']': a[i + 1] = 2; break;
		case ')': a[i + 1] = 3; break;
		};
	}
	int n = s.size();
	for (int i = 1; i <= n; ++i) dp[i][i] = 1;
	for (int i = 1; i < n; ++i)
		if (match(a[i],a[i + 1])) dp[i][i + 1] = 0;
		else dp[i][i + 1] = 2;
	for (int k = 2; k <= n; ++k){
		for (int i = 1; i + k <= n; ++i){
			int j = i + k;
			if (match(a[i],a[j])) dp[i][j] = dp[i + 1][j - 1];
			else dp[i][j] = dp[i + 1][j - 1] + 2;
			for (int mid = i; mid < j; ++mid){
				dp[i][j] = std::min(dp[i][j], dp[i][mid] + dp[mid + 1][j]);
			}
		}
	}
	std::cout << dp[1][n];
	return 0;
}