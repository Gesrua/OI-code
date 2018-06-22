#include <iostream>
using std::cin;
using std::cout;
int main(){
	long long b, p, k, ans = 1;
	cin >> b >> p >> k;
	cout << b << "^" << p << " mod " << k << "=";
	while (p > 0){
		if (p % 2 != 0){
			ans = ans * b % k;
		}
		b = b * b % k;
		p = p >> 1;
	}
	cout << ans % k;
	return 0;
}