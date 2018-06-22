#include <bits/stdc++.h>
long long mod = 2147483648;
int main(){
	int i, n, fbi[50], m;
	std::cin >> n;
	fbi[1] = fbi[2] = 1;
	for (i = 3; i <= n; i++)
		fbi[i] = (fbi[i - 1] + fbi[i - 2]) % mod;
	m = fbi[n];
	std::cout << m << '=';
	i = 2;
	while (m){
		while (m % i == 0){
			m /= i;
			if (m == 1){
				std::cout << i;
				return 0;
			}else{
				std::cout << i << '*';
			}
		}
		i++;
	}
	return 0;
}