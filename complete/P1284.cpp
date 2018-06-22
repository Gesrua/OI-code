#include <iostream>
#include <algorithm>
#include <ctime>
#include <cmath>
using std::cin; using std::cout; using std::cerr; using std::endl; using std::sqrt; using std::max;
inline bool isTri(const int a, const int b, const int c){
	if (a + b > c && b + c > a && a + c > b && a > 0 && b > 0 && c > 0) return true;
	return false;
}
inline double calc(const int i, const int j, const int k){
	double p = (i + j + k) / 2.0;
	return sqrt(p * (p - i) * (p - j) * (p - k));
}
int n, l[50], lim, tot;
bool flag[550][550] = {};
double ans;
int main(){
	unsigned int s = std::clock();
	cin >> n;
	register int i, j, k;
	double p;
	tot = 0;
	for (i = 0; i < n; ++i){
		cin >> l[i];
		tot += l[i];
	}
	lim = tot / 2 + 1;
	// cerr << "Comp\n";
	// std::sort(l, l+n);
	ans = -1;
	flag[0][0] = true;
	for (k = 0; k < n; ++k){
		for (i = lim; i >= 0; --i){
			for (j = lim; j >= 0; --j){
				if (flag[i][j]){
					flag[i + l[k]][j] = true;
					flag[i][j + l[k]] = true;
				}
			}
		}
	}
	for (i = 1; i < lim; ++i){
		for (j = 1; j < lim; ++j){
			if (!flag[i][j]) continue;
			k = tot - i - j;
			if (isTri(i, j, k)){
				ans = std::max(ans, calc(i, j, k));
			}
		}
	}
	if (ans == -1){
		cout << "-1";
		return 0;
	}
	int out = ans * 100;
	cout << out;
	// cerr << endl << (std::clock()-s);
	return 0;
}
