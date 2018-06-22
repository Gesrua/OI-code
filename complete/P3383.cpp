#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
int main(){
	std::ios::sync_with_stdio(false);
	int obj, n, m, pos = 0;
	//int prime[10000001]={};
	//bool book[10000001];
	bool book[100001];
	int prime[100001] = {};
	std::memset(book, 1, sizeof(book));
	book[0] = book[1] = false;
	cin >> n >> m;
	for (int i = 2; i <= n / 2; ++i){
		if (book[i]) prime[pos++] = i;
		for (int j = 0; j < pos && i * prime[j] <= n; ++j)
			book[i * prime[j]] = false;
	}
	for (int i = 0; i < m; ++i){
		cin >> obj;
		if (book[obj]) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}