#include <iostream>
using std::cin; using std::cerr; using std::cout; using std::endl;
const int N = 10000;
int num[N], prime[N];
bool flag[N + 100];
int main(){
	flag[0] = flag[1] = false;
	int cnt = 0;
	int n;
	cin >> n;
	for (int i = 2; i <= n; ++i){
		if (flag[i]) continue;
		prime[cnt++] = i;
		num[i] = 1;
		for (int j = i * 2; j <= n; j += i){
			flag[j] = true;
			int ori = num[i];
			for (int k = j; k % i == 0; k /= i) ++num[i];
			// cerr << "j = " << j << " delta = " << num[i] - ori << endl;
		}
	}
	for (int i = 2; i <= n; ++i){
		if (!flag[i]){
			cout << i << ' ' << num[i] << endl;
		}
	}
	return 0;
}