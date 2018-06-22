#include <cstdio>
int k, x, ans = 0, tot = 0;
int main(){
	std::scanf("%d%d", &x, &k);
	for (int i = 1; i <= x && tot < k; ++i){
		if (x % i == 0){
			ans += i;
			++tot;
		}
	}
	std::printf("%d", ans);
	return 0;
}
