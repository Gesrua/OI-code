#include <bits/stdc++.h>
int main(){
	bool flag;
	int n, a[101], i, j, k, ans = 0;
	std::cin >> n;
	for (i = 0; i < n; i++) std::cin >> a[i];
	std::sort(a,a + n);
	for (i = 2; i < n; i++){
		flag = false;
		for (j = 0; j < i; j++){
			for (k = 0; k < i; k++){
				if (j == k || j == i || k == i) continue;
				if (a[j] + a[k] == a[i]){
					flag = true;
				}
			}
		}
		if (flag) ans++;
	}
	std::cout << ans;
	return 0;
}
