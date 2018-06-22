#include <iostream>
#include <cstring>
int cnt = 0, stack[17] = {}, n;
bool flag = true, lie[100], dui[100],dui2[100];
void dfs(int a){
	if (a == n + 1){
		cnt++;
		if (flag){
			for (int i = 1; i <= n; i++)
				std::cout << stack[i] << ' ';
			std::cout << std::endl;
		}
		if (cnt == 3) flag = false;
	}
	for (int i = 1; i <= n; i++){
		if (lie[i] && dui[a - i + 16] && dui2[a + i]){
			lie[i] = false;
			dui[a - i + 16] = false;
			dui2[a + i] = false;
			stack[a] = i;
			dfs(a + 1);
			dui2[a + i] = true;
			lie[i] = true;
			dui[a - i + 16] = true;
		}
	}
}
int main(){
	std::cin >> n;
	for (int i = 0; i < 100; i++) lie[i] = dui[i] = dui2[i] = true;
	dfs(1);
	std::cout << cnt;
	return 0;
}
