#include <iostream>
using std::cout; using std::cerr; using std::endl;
char s[20000001]; int stl = 0;
inline void rd(int&);
int n, g[100010] = {}, tmp[100010] = {}, ans[100010] = {}, tag[100010];
int main(){
	fread(s, 20000000, 1, stdin);
	rd(n);
	for (int i = 1; i <= n; ++i) rd(g[i]);
	for (int i = 1; i <= n; ++i){
		// cerr << "Handle " << i << endl;
		// if (loop[i] != 0) { cout << loop[i] << ' '; continue; }
		int cnt = 0, loop_point;
		for (int j = i;; j = g[j]){
			// cerr << j << ' ';
			if (ans[j] != 0){
				cnt += ans[j];
				ans[i] = cnt;
				for (int k = i; k != j; k = g[k]){
					ans[k] = cnt;
					--cnt;
				}
				cout << ans[i] << endl;
				break;
			}

			if (tag[j] == i){
				loop_point = j;
				ans[i] = cnt;
				int k;
				for (k = g[i]; k != g[loop_point]; k = g[k]){
					--cnt;
					ans[k] = cnt;
				}
				for (; k != loop_point; k = g[k]) ans[k] = cnt;
				cout << ans[i] << endl;
				break;
			}
			++cnt;
			tag[j] = i;
			tmp[j] = cnt;
		}
	}
	return 0;
}

inline void rd(int &x){
	x = 0;
	for (; !isdigit(s[stl]); ++stl);
	for (; isdigit(s[stl]); ++stl) x = (x << 3) + (x << 1) + s[stl] - '0';
}