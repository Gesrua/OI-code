#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
struct cow {
	int w, s, sum;
} a[50000];
bool cmp(cow a, cow b){
	return a.sum < b.sum;
}
int main(){
	int ans = -2100000000, n, w = 0;
	std::scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		std::scanf("%d%d", &a[i].w, &a[i].s);
		a[i].sum = a[i].w + a[i].s;
	}
	std::sort(a, a + n, cmp);
	for (int i = 0; i < n; ++i){
		ans = std::max(ans, w - a[i].s);
		w += a[i].w;
	}
	std::cout << ans;
	return 0;
}
