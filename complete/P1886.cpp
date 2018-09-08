#include <cstdio>
#include <iostream>
#include <utility>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#define rep(i, l, r) for (register int i = (l); i <= (r); ++i)
#define per(i, l, r) for (register int i = (l); i >= (r); --i)
using std::cin; using std::cout; using std::cerr; using std::endl;
using std::make_pair; using std::pair;
typedef pair< int, int > pii;
const int N = 2000000;
std::deque< pii > q;
int a[N + 10];
char s[50000001]; int stl = 0;
inline void rd(int &x){
	bool flag = false;
	x = 0;
	for (; !isdigit(s[stl]); ++stl);
	if (s[stl - 1] == '-') flag = true;
	for (; isdigit(s[stl]); ++stl) x = (x << 3) + (x << 1) + s[stl] - '0';
	if (flag) x = -x;
}
inline void _put(int x){
	if (x >= 10) _put(x / 10);
	s[stl++] = x % 10 + '0';
}
inline void put(int x){
	if (x >= 0) _put(x);
	else{
		s[stl++] = '-';
		_put(-x);
	}
	s[stl++] = ' ';
}
int main(){
	std::ios::sync_with_stdio(false);
	fread(s, 50000000, 1, stdin);
	int n, k;
	rd(n); rd(k);
	rep (i, 1, n) rd(a[i]);
	stl = 0;
	rep (i, 1, n){
		while (!q.empty() && q.front().first <= i - k) q.pop_front();
		while (!q.empty() && q.back().second >= a[i]) q.pop_back();
		q.push_back(make_pair(i, a[i]));
		if (i >= k) put(q.front().second);
	}
	s[stl++] = '\n';
	fwrite(s, stl, 1, stdout);
	q.clear();
	stl = 0;
	rep (i, 1, n){
		while (!q.empty() && q.front().first <= i - k) q.pop_front();
		while (!q.empty() && q.back().second <= a[i]) q.pop_back();
		q.push_back(make_pair(i, a[i]));
		if (i >= k) put(q.front().second);
	}
	fwrite(s, stl, 1, stdout);
	return 0;
}