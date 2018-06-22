#include <iostream>
int main(){
	int n, m, i, t, ans = 0, sum = 0;
	using namespace std;
	cin >> n >> m;
	for (i = 0; i < n; i++){
		cin >> t;
		if (m <= sum + t){
			if (m == sum + t){
				ans++;
				sum = 0;
			}
			else{
				ans++;
				sum = t;
			}
		}
		else{
			if (i == n - 1) ans++;
			else sum += t;
		}
	}
	cout << ans;
	return 0;
}
