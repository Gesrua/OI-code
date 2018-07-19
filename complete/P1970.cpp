#include <iostream>
using std::cin; using std::cout; using std::cerr; using std::endl; using std::max; using std::min;
int n, h[2], f[2], g[2], prev, now;
int main(){
	std::ios::sync_with_stdio(false);
	cin >> n;
	now  = 1;
	prev = 0;
	f[now] = 1; g[now] = 1;
	cin >> h[now];
	for (int i = 1; i < n; ++i){
		now ^= 1, prev ^= 1;
		cin >> h[now];
		if (h[prev] < h[now]){
			f[now] = max(f[prev], g[prev] + 1);
			continue;
		}
		if (h[prev] > h[now]){
			g[now] = max(g[prev], f[prev] + 1);
			continue;
		}
		f[now] = f[prev];
		g[now] = g[prev];
	}
	cout << max(f[now], g[now]);
	return 0;
}