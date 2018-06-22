#include <iostream>
#include <cstring>
#include <algorithm>
struct node {
	int f, h, t;
} r[101];
bool cmp(const node &a, const node &b){
	return a.t < b.t;
}
int main(){
	r[0].f = 0;
	int D, G, dp[2501] = {};
	using namespace std;
	cin >> D >> G;
	int v = 0;
	for (register int i = 1; i <= G; ++i){
		cin >> r[i].t >> r[i].f >> r[i].h;
		v += r[i].h;
	}
	sort(r + 1, r + 1 + G, cmp);
	int ans = 0;
	memset(dp, -1, sizeof(dp));
	dp[0] = 10;
	for (register int i = 1; i <= G; ++i){
		for (register int j = D; j >= 0; --j){
			if (dp[j] >= r[i].t){
				if (j + r[i].h >= D){
					cout << r[i].t;
					return 0;
				}
				dp[j + r[i].h] = max(dp[j + r[i].h], dp[j]);
				dp[j] += r[i].f;
			}
		}
	}
	cout << dp[0];
	return 0;
}
