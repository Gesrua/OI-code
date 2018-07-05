#include <iostream>
#include <algorithm>
using std::cin; using std::cout; using std::cerr; using std::endl; using std::min; using std::max;
int N, W;
struct node {
	int x, b;
	bool operator< (node x){
		return this->x < x.x;
	}
} a[100000];
int search(int idx){
	int l = 0, r = N - 1, mid;
	while (l < r){
		// cerr << "dbg" << l << " " << r << endl;
		mid = ((l + r) >> 1) + 1;
		if (a[mid].x < idx){
			l = mid;
		}else{
			r = mid - 1;
		}
	}
	return l;
}
int p[100000];
int main(){
	cin >> N >> W;
	for (register int i = 0; i < N; ++i){
		cin >> a[i].x >> a[i].b;
	}
	std::sort(a, a + N);
	// cerr << "Sort";
	p[0] = a[0].b;
	for (register int i = 0; i < N; ++i){
		p[i] = p[i - 1] + a[i].b;
	}
	int ans = 0;
	if (W == 0){
		cout << "0";
		return 0;
	}
	for (register int i = 0; i < N; ++i){
		int idx = search(a[i].x + W);
		ans = max(ans, p[idx] - p[i] + a[i].b);
	}
	cout << ans;
	return 0;
}
