#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
int main()
{
	std::ios::sync_with_stdio(false);
	int i,j,n,k,a[200000];
	std::cin >> n >> k;
	std::memset(a,0,sizeof(a));
	for (i = 1; i <= k; i++) a[i] = 1;
	for (i = 1; i < n; i++)
		for (j = 1; j <= k; j++)
			if (a[i] != 0){
				a[i + j] += a[i];
				a[i + j] = a[i + j] % 100003;
			}
	std::cout << a[n];
	return 0;
}
