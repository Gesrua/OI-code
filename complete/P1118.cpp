#include <bits/stdc++.h>
bool book[13] = {}, flag = true;
int trangle[100][100];
int n, s;
std::stack<int> stack;
void dfs(int now,int sum){
	int i;
	if (now == n + 1){
		if (sum == s){
			flag = false;
			int a[20];
			for (i = n; i > 0; i--){
				a[i] = stack.top();
				stack.pop();
			}
			for (i = 1; i <= n; i++)
				std::cout << a[i] << ' ';
			return;
		}
		else return;
	}
	if (!flag || sum > s) return;
	for (i = 1; i <= n; i++){
		if (flag && !book[i]){
			book[i] = true;
			stack.push(i);
			dfs(now + 1, sum + i * trangle[n][now]);
			stack.pop();
			book[i] = false;
		}
	}
	return;
}
int main(){
	std::cin >> n >> s;
	trangle[1][1] = 1;
	for (int i = 2; i <= 12; i++){
		trangle[i][1] = 1;
		for (int j = 2; j < i; j++)
			trangle[i][j] = trangle[i - 1][j] + trangle [i - 1][j - 1];
		trangle[i][i] = 1;
	}
	// for (int i=1;i<=12;i++){
	//   for (int j=1;j<=i;j++)
	//     std::cout << trangle[i][j] << ' ';
	//   std::cout << std::endl;
	// }
	dfs(1, 0);
	return 0;
}
