#include <iostream>
#include <cmath>
using std::cin; using std::cout; using std::cerr; using std::endl; using std::min; using std::abs;
int main(){
	int t, n, tot = 0, ave, ans = 0, a[101];
	std::ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> a[i];
		tot += a[i];
	}
	ave = tot / n;
	// cerr << ave << endl;
	for (int i = 0; i < n; ++i){
		t = a[i] - ave;
		if (t != 0) ++ans;
		a[i + 1] += t;
		// cerr << a[i+1] << ' ';
	}
	cout << ans;
	return 0;
}
