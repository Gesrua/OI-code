#include <iostream>
#include <algorithm>
using std::cin; using std::cout; using std::cerr; using std::endl; using std::min; using std::max;
int N, M, P, L, R;
long long K;
const int MAXN = 100000;
long long a[MAXN + 10], T[MAXN << 2], c[MAXN << 2], s[MAXN << 2];
void build(int idx, int l, int r){
	if (l == r){
		c[idx] = 1;
		T[idx] = a[l];
		return;
	}
	// cerr << idx << ' ' << l << ' ' << r << endl;
	int mid = (l + r) >> 1;
	c[idx] = 1;
	build(idx << 1, l, mid);
	build((idx << 1) | 1, mid + 1, r);
	T[idx] = T[idx << 1] + T[(idx << 1) | 1];
}
void add(int idx, int l, int r){
	if (r < L || R < l){
		return;
	}
	if (l == r){
		T[idx] += K;
		T[idx] %= P;
		return;
	}
	if (L <= l && r <= R){
		s[idx] += K;
		s[idx] %= P;
		T[idx] += (r - l + 1) * K;
		T[idx] %= P;
		return;
	}
	// lazy 下放
	int lson = idx << 1, mid = (l + r) >> 1;
	int rson = (idx << 1) | 1;
	T[lson] = T[lson] * c[idx] % P;
	T[rson] = T[rson] * c[idx] % P;
	c[lson] = c[lson] * c[idx] % P;
	c[rson] = c[rson] * c[idx] % P;
	s[lson] = s[lson] * c[idx] % P;
	s[rson] = s[rson] * c[idx] % P;
	c[idx] = 1;
	T[lson] = (T[lson] + (mid - l + 1) * s[idx]) % P;
	T[rson] = (T[rson] + (r - mid) * s[idx]) % P;
	s[lson] = (s[lson] + s[idx]) % P;
	s[rson] = (s[rson] + s[idx]) % P;
	s[idx] = 0;

	add(idx << 1, l, mid);
	add((idx << 1) | 1, mid + 1,r);
	T[idx] = T[lson] + T[rson];
}
void multiply(int idx, int l, int r){
	if (r < L || R < l){
		return;
	}
	if (l == r){
		T[idx] *= K;
		T[idx] %= P;
		return;
	}
	if (L <= l && r <= R){
		s[idx] *= K; // debug 一开始没写导致WA
		s[idx] %= P; // debug
		c[idx] *= K;
		c[idx] %= P;
		T[idx] *= K;
		T[idx] %= P;
		return;
	}

	// lazy 下放
	int lson = idx << 1, mid = (l + r) >> 1;
	int rson = (idx << 1) | 1;
	T[lson] = T[lson] * c[idx] % P;
	T[rson] = T[rson] * c[idx] % P;
	c[lson] = c[lson] * c[idx] % P;
	c[rson] = c[rson] * c[idx] % P;
	s[lson] = s[lson] * c[idx] % P;
	s[rson] = s[rson] * c[idx] % P;
	c[idx] = 1;
	T[lson] = (T[lson] + (mid - l + 1) * s[idx]) % P;
	T[rson] = (T[rson] + (r - mid) * s[idx]) % P;
	s[lson] = (s[lson] + s[idx]) % P;
	s[rson] = (s[rson] + s[idx]) % P;
	s[idx] = 0;

	multiply(lson, l, mid);
	multiply(rson, mid + 1, r);
	T[idx] = (T[lson] + T[rson]) % P;
}
long long query(int idx, int l, int r){
	if (r < L || R < l){
		return 0;
	}
	if (l == r){
		return T[idx];
	}
	if (L <= l && r <= R){
		return T[idx];
	}

	int lson = idx << 1, mid = (l + r) >> 1;
	int rson = (idx << 1) | 1;
	T[lson] = T[lson] * c[idx] % P;
	T[rson] = T[rson] * c[idx] % P;
	c[lson] = c[lson] * c[idx] % P;
	c[rson] = c[rson] * c[idx] % P;
	s[lson] = s[lson] * c[idx] % P;
	s[rson] = s[rson] * c[idx] % P;
	c[idx] = 1;
	T[lson] = (T[lson] + (mid - l + 1) * s[idx]) % P;
	T[rson] = (T[rson] + (r - mid) * s[idx]) % P;
	s[lson] = (s[lson] + s[idx]) % P;
	s[rson] = (s[rson] + s[idx]) % P;
	s[idx] = 0;
	return query(lson, l, mid) % P + query(rson, mid + 1, r) % P;
}
void print_cell(int idx, int l, int r){
	cerr << l << " " << r << " " << T[idx] << " " << s[idx] << " " << c[idx] << endl;
	if (l == r) return;
	int mid = (l + r) >> 1;
	print_cell(idx << 1, l, mid);
	print_cell((idx << 1) | 1, mid + 1, r);
}
void print(){
	cerr << "------\n";
	print_cell(1, 1, N);
	cerr << "------\n";
}
int main(){
	// std::freopen("/home/chaigidel/code/luogu-code/now/data.in", "r", stdin);
	cin >> N >> M >> P;
	for (register int i = 1; i <= N; ++i){
		cin >> a[i];
	}
	build(1, 1, N);
	int opt;
	// 约定 先乘后加
	// print();
	while (M--){
		cin >> opt >> L >> R;
		if (opt == 1){
			// cerr << "cheng\n";
			cin >> K;
			K %= P;
			multiply(1, 1, N);
		}else if (opt == 2){
			// cerr << "jia\n";
			cin >> K;
			K %= P;
			add(1, 1, N);
		}else{
			// cerr << "chaxun\n";
			cout << query(1, 1, N) % P << endl;
		}
		// print();
	}
	return 0;
}
