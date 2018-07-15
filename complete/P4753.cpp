#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>
using std::cin; using std::cout; using std::cerr; using std::endl; using std::sort;
int a[100010], s1[100010], s2[100010], cnt1 = 0, cnt2 = 0;
int N, M, S;
int main(){
	cin >> N >> M >> S;
	for (int i = 1; i <= M; ++i){
		cin >> a[i];
	}
	a[M + 1] = N;
	int pos1 = 0, pos2 = 0, i;
	// cerr << "B1\n";
	for (i = 1; a[i] < S; ++i){
		// cerr << i << endl;
		if (pos1 + S > a[i]){
			cout << "NO\n";
			return 0;
		}
		s1[cnt1++] = i;
		pos1 = a[i];
	}
	// cerr << "B2\n";
	for (; a[i] <= N - S; ++i){
		// cerr << i << endl;
		if (pos1 + S <= a[i]){
			pos1 = a[i];
			s1[cnt1++] = i;
			continue;
		}
		if (pos2 + S <= a[i]){
			pos2 = a[i];
			s2[cnt2++] = i;
			continue;
		}
		cout << "NO\n";
		return 0;
	}
	// cerr << "B3\n";
	for (; i <= M + 1; ++i){
		// cerr << i << endl;
		if (pos2 + S > a[i]){
			cout << "NO\n";
			return 0;
		}
		pos2 = a[i];
		s2[cnt2++] = i;
	}
	// cerr << "dbg\n";
	cout << "YES\n";
	for (int i = 0; i < cnt1; ++i){
		cout << s1[i] << ' ';
	}
	for (int i = cnt2 - 1; i >= 0; --i){
		cout << s2[i] << ' ';
	}
	cout << 0;
	return 0;
}