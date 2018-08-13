#include <iostream>
using std::cin; using std::cout; using std::cerr; using std::endl;
int lim = 0, n, a[100] = {}, ans, arr[100];
void dfs(int s){
	// if (arr[s-1] == 33) cerr << "w";
	// cerr << s << ' ';
	if (s - 1 >= ans || a[s - 1] > n) return;
	if (a[s - 1] == n){

		for (register int i = 0; i < s; ++i) arr[i] = a[i];
		ans = s - 1;
		return;
	}
	int lim = a[s - 1] / 2;
	for (int i = s - 1; i >= 0; --i){
		for (int j = i; j >= 0; --j){
			if (a[i] + a[j] <= a[s - 1]) break;
			a[s] = a[i] + a[j];
			dfs(s + 1);
		}
	}
}
int main(){
	while (cin >> n){
		if (n == 0) return 0;
		if (n == 1){cout << 1 << endl; continue;}
		lim = n;
		ans = 20;
		a[0] = 1;
		dfs(1);
		// cout << ans << endl;
		for (int i = 0; i <= ans; ++i){
			cout << arr[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}