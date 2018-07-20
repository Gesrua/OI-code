#include <iostream>
#include <cstring>
using std::cin; using std::cout; using std::endl; using std::cerr; using std::min; using std::max;
int q[300010], flag[300010];
int main(){
	int t;
	cin >> t;
	while (t--){
		std::memset(flag, -1, sizeof(flag));
		int x, y;
		cin >> x >> y;
		int l = 1, r = 2;
		q[1] = x;
		flag[x] = 0;
		int &ans = flag[y];
		while (l < r){
			// cerr << l << ' ' << r << endl;
			int &now = q[l];
			if (ans != -1) break;
			if (now - 1 >= 0 && flag[now - 1] == -1) flag[now - 1] = flag[now] + 1, q[r++] = now - 1;
			if (now < y && flag[now << 1] == -1) flag[now << 1] = flag[now] + 1, q[r++] = now << 1;
			if (flag[now + 1] == -1) flag[now + 1] = flag[now] + 1, q[r++] = now + 1;
			++l;
		}
		cout << ans << endl;
	}
	return 0;
}