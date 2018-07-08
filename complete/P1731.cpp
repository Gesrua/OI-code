#include <iostream>
#include <cmath>
const int INF = 2100000000;
using std::cin; using std::cout; using std::cerr; using std::endl; using std::min; using std::max;
int N, M, ans = INF;
int lim;
int minv[30], maxv[29][29], mins[30];

void dfs(int k, int v, int s, const int maxr, const int maxh){
	// cerr << s << endl;
	if (k == 0 && v == 0)
		ans = min(s, ans);
	if (v < minv[k] || k == 0 || s + mins[k] >= ans || (maxh - 1) * (maxr - 1) * (maxr - 1) * k < v) return;
	register int t, lim1 = min(maxr - 1, int(std::sqrt(v - minv[k - 1]))), lim2;
	for (register int i = k; i <= lim1; ++i){
		t = i * i;
		if (2 * v / i + s > ans) continue;
		lim2 = min(maxh - 1, (v - minv[k - 1]) / t);
		for (register int j = k; j <= lim2; ++j){
			// if (maxv[i-1][j-1]-maxv[i-k][j-k]<t*j) continue;
			if (s != 0)
				dfs(k - 1, v - j * t, s + 2 * i * j, i, j);
			else
				dfs(k - 1, v - j * t, i * i + 2 * i * j, i, j);
		}
	}
}

int main(){
	minv[0] = 0;
	for (int i = 1; i < 30; ++i){
		minv[i] = minv[i] + i * i * i;
		mins[i] = mins[i] + i * 2;
	}
	cin >> N >> M;
	lim = std::sqrt(N);
	dfs(M, N, 0, 30, 30);
	// solve(0, N, 0, 0, 0);
	if (ans == INF){
		cout << 0;
		return 0;
	}
	cout << ans;
	return 0;
}
