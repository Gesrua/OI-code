#include <iostream>
#include <cstring>
using std::cin; using std::cout; using std::cerr; using std::endl;
int a[20], n, flag[201], book[20];
void dfs(int x){
	// cerr << x << endl;
	if (x > n){
		if (!flag[1 + a[n]]) return;
		for (int i = 1; i < n; ++i){
			cout << a[i] << ' ';
		}
		cout << a[n] << endl;
		return;
	}
	// for (int i = 1; i < x; ++i){
	//     cout << a[i] << ' ';
	// }
	// cout << endl;
	for (int i = 2; i <= n; ++i){
		if (book[i] && flag[i + a[x - 1]]){
			book[i] = false;
			a[x] = i;
			dfs(x + 1);
			book[i] = true;
		}
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	std::memset(flag, 1, sizeof(flag));
	flag[0] = flag[1] = false;
	for (int i = 2; i <= 101; ++i){
		for (int j = i * 2; j <= 200; j += i){
			flag[j] = false;
		}
	}
	int cnt = 0;
	// for (int i = 0; i <= 200; ++i)
	//     if (flag[i]) cout << i << ' ';
	while (cin >> n){
		++cnt;
		if (cnt != 1) cout << endl;
		std::memset(book, 1, sizeof(book));
		cout << "Case " << cnt << ":\n";
		a[1] = 1;
		dfs(2);
		// std::cerr << "done\n";
	}
	return 0;
}