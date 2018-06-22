#include <bits/stdc++.h>
int n, mod = 10;
int main(){
	using std::cin;
	using std::cout;
	using std::endl;
	cin >> n;
	int a[200] = {}, tot = 1, i, j;
	a[1] = 1;
	for (i = 2; i <= n; ++i){
		// *2
		for (j = 1; j <= tot; ++j)
			a[j] *= 2;
		++a[1];
		for (j = 1; j <= tot; ++j){
			a[j + 1] = a[j + 1] + a[j] / mod;
			a[j] %= mod;
		}
		if (a[tot + 1] != 0) ++tot;

	}

	for (j = 1; j <= tot; ++j)
		a[j] *= 2;
	for (j = 1; j <= tot; ++j){
		a[j + 1] = a[j + 1] + a[j] / mod;
		a[j] %= mod;
	}
	if (a[tot + 1] != 0) ++tot;
	for (i = tot; i >= 1; i--){
		cout << a[i];
	}

	return 0;
}