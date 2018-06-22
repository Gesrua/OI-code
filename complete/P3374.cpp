#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
const int N = 500000;
int n, m, a[N + 1] = {}, c[N + 1] = {};
inline int lowbit(int x){
	return x & (-x);
}
void add(int x, int k){
	while (x <= n){
		c[x] += k;
		x += lowbit(x);
	}
}
int find(int k){
	int ans = 0;
	while (k){
		ans += c[k];
		k -= lowbit(k);
	}
	return ans;
}
int main(){
	std::ios::sync_with_stdio(false);
	cin >> n >> m;

	for (int i = 1; i <= n; ++i){
		cin >> a[i];
		add(i, a[i]);
	}
	int x, k, y, op;
	for (int i = 0; i < m; ++i){
		cin >> op;
		if (op == 1){
			cin >> x >> k;
			add(x, k);
		}
		if (op == 2){
			cin >> x >> y;
			cout << find(y) - find(x - 1) << endl;
		}
	}
	return 0;
}
