#include <iostream>
#include <cmath>
using std::cin; using std::cout; using std::cerr; using std::endl; using std::max; using std::min;
int n, m, k, h[1001][1001], t[1001][1003];
inline int read(){
	int s = 0;
	char ch = getchar();
	while (ch <= '0' || ch > '9'){ch = getchar();}
	while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0',ch = getchar();
	return s;
}
int main(){
	// std::ios::sync_with_stdio(false);
	// cin >> n >> m >> k;
	n = read();
	m = read();
	k = read();
	for (register int i = 1; i <= n; ++i)
		for (register int j = 1; j <= m; ++j)
			// cin >> h[i][j];
			h[i][j] = read();
	for (register int i = 1; i <= n; ++i)
		for (register int j = 1; j <= m; ++j){
			t[i][j] = t[i][j - 1];
			if (h[i][j] >= h[i - 1][j] && h[i][j] >= h[i][j - 1] && h[i][j] >= h[i + 1][j] && h[i][j] >= h[i][j + 1])
				++t[i][j];
		}

	for (register int i = 1; i <= n; ++i)
		t[i][m + 1] = t[i][m] > 0 ? i : t[i - 1][m + 1];

	int x, y;
	while (k--){
		cin >> x >> y;
		register int a = y - 1, b = y, lim = max(0, min(a - b, a + b - m));
		for (register int i = x; i > lim; --i){
			if (t[i][b] - t[i][a] > 0){
				cout << x - i << endl;
				goto point1;
			}
			if (a != 0) --a;
			if (b < m) ++b;
		}
		if (t[lim][m + 1] > 0) cout << x - t[lim][m + 1] << endl;
		else cout << "Pool Babingbaboom!\n";
		point1 : 1;
	}
	return 0;
}