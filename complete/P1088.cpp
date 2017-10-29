#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
int main(){
	int i=0, n, m, a[10000];
	cin >> n >> m;
	while(cin>>a[i])++i;
	for (i=0;i<m;++i)
		std::next_permutation(a, a+n);
	for (i=0;i<n;++i)
		cout << a[i] << ' ';
	return 0;
}