#include <cstdio>
#include <iostream>
#include <cctype>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::isdigit;
char s[20000001]; int stl = 0;
inline void rd(int&);
struct heap {
	int tree[1000001], tot;
	heap () : tot(0){
	};
	inline void siftup(const int s){
		for (register int i = s, j = s >> 1; j > 0; i = j, j >>= 1){
			if (tree[i] < tree[j]) std::swap(tree[i], tree[j]); // 玄学分支优化
			else return;
		}
	}
	inline void siftdown(const int s){
		for (register int i = s, j = s << 1; j <= tot; i = j, j <<= 1){
			if (j + 1 <= tot && tree[j] > tree[j + 1]) ++j;
			if (tree[i] > tree[j]) std::swap(tree[i], tree[j]);
			else return;
		}
	}
	inline void push(const int x){
		this->tree[++tot] = x;
		this->siftup(tot);
	}
	void pop(){
		this->tree[1] = this->tree[tot];
		--tot;
		siftdown(1);
	}
	inline int top(){
		return this->tree[1];
	}
} t;
int main(){
	fread(s, 20000000, 1, stdin);
	int n, x;
	rd(n);
	for (int i = 0; i < n; ++i){
		rd(x);
		if (x == 1){
			rd(x);
			t.push(x);
			continue;
		}
		if (x == 2){
			cout << t.top() << endl;
			continue;
		}
		if (x == 3){
			t.pop();
		}
	}
	return 0;
}
inline void rd(int &x){
	x = 0;
	for (; !isdigit(s[stl]); ++stl);
	for (; isdigit(s[stl]); ++stl) x = (x << 3) + (x << 1) + s[stl] - '0';
}