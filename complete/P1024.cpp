#include <iostream>
#include <iomanip>
#include <cmath>
#include <set>
using std::cin; using std::cout; using std::cerr; using std::endl;
inline bool equal(const double x, const double y){
	return std::abs(x - y) < 1e-5;
}
double a, b, c, d;
inline double f(double x){
	return a * x * x * x + b * x * x + c * x + d;
}
int main(){
	int t;
	std::set<int> flag;
	std::setprecision(2);
	cout.setf(std::ios::fixed);
	cin >> a >> b >> c >> d;
	for (int i = -100; i < 100; ++i){
		double l = i, r = i + 1, mid;
		// cerr << l << ' ' << r << ' ';
		// cerr << f(l) << ' ' << f(r) << endl;
		if (equal(f(l), 0)){
			t = (l + 1e-5) * 100;

			if (flag.count(t) != 0) continue;
			flag.insert(t);
			cout.setf(std::ios::fixed);
			cout << std::setprecision(2) << l << ' ';
			continue;
		}
		while (f(l) * f(r) < 0){
			if (equal(l, r)){
				t = (l + 1e-5) * 100;
				// cerr << "t=" << t << endl;
				if (flag.count(t) != 0) break;
				flag.insert(t);
				cout.setf(std::ios::fixed);
				cout << std::setprecision(2) << l << ' ';
				break;
			}
			mid = (l + r) / 2;
			if (f(l) * f(mid) < 0){
				r = mid;
				continue;
			}
			if (f(mid) * f(r) < 0){
				l = mid;
				continue;
			}
		}
	}
	if (equal(f(100), 0) && flag.count(10000) != 0){
		// std::setprecision(2);
		cout.setf(std::ios::fixed);
		cout << std::setprecision(2) << 100 << ' ';
		// continue;
	}
	return 0;
}