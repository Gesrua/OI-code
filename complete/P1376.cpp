#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::scanf;
int main(){
	long long ans=0;
	int n,s,c, y, last;
	scanf("%d%d", &n, &s);
	scanf("%d%d", &c, &y);
	ans = c*y;
	last = c;
	for (int i = 2; i <= n; ++i){
		scanf("%d%d", &c, &y);
		if (last+s < c) c = last+s;
		ans += c*y;
		last = c;
	}
	cout << ans;
	return 0;
}