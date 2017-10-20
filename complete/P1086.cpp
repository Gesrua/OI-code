#include <bits/stdc++.h>
int m, n, k, x = 0, y = 0;
struct cell
{
	int x, y, p;
	bool operator<(cell & CMP){
		return p < CMP.p;
	}
	bool operator>(cell & CMP){
		return p > CMP.p;
	}
}cache;
std::vector<cell> v;
void push(cell &S){
	v.push_back(S);
	std::push_heap(v.begin(), v.end());
}
cell pop(){
	std::pop_heap(v.begin(), v.end());
	cell tmp = v.back();
	v.pop_back();
	return tmp;
}
void init(){
	std::make_heap(v.begin(), v.end());
	using std::cin;
	int t;
	cin >> m >> n >> k;
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++){
			cin >> cache.p;
			if (cache.p == 0) continue;
			cache.x = i;
			cache.y = j;
			push(cache);
		}
}
int check(const cell &target){
	int ans = 0;
	if ((x==0) && (y==0)) ans += target.x;
	else ans += std::abs(target.x - x) + std::abs(target.y - y);
	// x = target.x; y = target.y;
	return ans += target.x + 1;
}
int main(){
	int ans = 0, t;
	init();
	while (!v.empty()){
		cache = pop();
		//std::cout << x << ' ' << y << ' '<< k << ' ' << cache.p << ' ';
		t = check(cache);
		//std::cout << t << '\n';
		if (k < t) break;
		k = k - t + cache.x;
		x = cache.x;
		y = cache.y;
		ans += cache.p;
	}
	std::cout << ans;
	return 0;
}