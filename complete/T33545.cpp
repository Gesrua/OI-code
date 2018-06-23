#include <iostream>
using std::cin; using std::cout; using std::cerr; using std::endl; using std::min; using std::max;
long long n, p, q, sum[100003], t;
int main(){
	std::ios::sync_with_stdio(false);
	cin >> n >> q >> p;
	for (register int i = 1; i <= n; ++i){
		cin >> t;
		// t %= p;
		// sum[i] = (sum[i-1]+t)%p;
		sum[i] = sum[i - 1] + t;
	}
	int l, r;
	for (register int i = 0; i < q; ++i){
		cin >> l >> r;
		cout << (sum[r] - sum[l - 1]) % p << endl;
	}
	return 0;
}
