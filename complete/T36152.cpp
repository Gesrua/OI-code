#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using std::abs; using std::cin; using std::cerr; using std::cout; using std::endl; using std::sort; using std::max; using std::min;
int n, ans = 0;
struct p {
	int x, y;
	p (){
		x = 0, y = 0;
	}
	bool operator< (const p b){
		return x != b.x ? x < b.x : y < b.y;
	}
} a[1010];
struct node {
	bool a[300][300];
	inline bool at(const int x, const int y){
		if (x < -100 || x > 100 || y < -100 || y > 100) return false;
		return this->a[x + 100][y + 100];
	}
	inline void upd(const int x, const int y, const bool opt){
		this->a[x + 100][y + 100] = opt;
	}
	node (){
		std::memset(a, 0, sizeof(a));
	}
} map;
void dfs(int x, int s){
	if (x > n) return;
	// if (!map.at(a[x].x, a[x].y)){
	// dfs(x+1, sum);
	// return;
	// }
	int& x1 = a[x].x, y1 = a[x].y;
	// map.upd(x1, y1, false);
	for (int i = s; i <= n; ++i){
		int& x2 = a[i].x, y2 = a[i].y;
		if ((abs(x1 - x2) > abs(y1 - y2) || (x1 - x2 == y1 - y2 && x1 == x2 + y1 - y2)) && map.at(x2, y2) && map.at(x2 + y1 - y2,y2 + x2 - x1) && map.at(x1 + y1 - y2,y1 - x1 + x2)){
			// map.upd(x2, y2, false);
			// map.upd(x2+y1-y2,y2+x2-x1, false);
			// map.upd(x1+y1-y2,y1-x1+x2, false);
			++ans;
			dfs(x,  i + 1);
			return;
			// map.upd(x2, y2, true);
			// map.upd(x2+y1-y2,y2+x2-x1, true);
			// map.upd(x1+y1-y2,y1-x1+x2, true);
		}
	}
	dfs(x + 1, x + 2);
	// map.upd(x1, y1, true);
}
int main(){
	// freopen("/data/code/luogu-code/now/data.in", "r", stdin);
	cin >> n;
	for (register int i = 1; i <= n; ++i){
		cin >> a[i].x >> a[i].y;
		map.upd(a[i].x, a[i].y, true);
	}
	sort(a + 1, a + 1 + n);
	dfs(1, 2);
	cout << ans << endl;
	return 0;
}