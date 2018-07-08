#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using std::cin; using std::cout; using std::cerr; using std::endl; using std::min; using std::max; using std::sort;
int stack[200], pos, n;
std::set<std::string> flag;
void print(){
	std::string s;
	int tmp[200];
	for (int i = 0; i < pos; ++i){
		tmp[i] = stack[i];
	}
	sort(tmp, tmp + pos);
	for (int i = 0; i < pos; ++i){
		s += tmp[i];
	}
	if (flag.count(s) == 1){
		return;
	}
	// cout << n << '=';
	flag.insert(s);
	for (int i = 0; i < pos - 1; ++i){
		cout << tmp[i] << '+';
	}
	cout << tmp[pos - 1] << endl;
}
void solve(int n){
	// cerr << n;
	if (n == 0){
		// cout << endl;
		print();
		return;
	}
	if (n == 1){
		stack[pos++] = 1;
		print();
		--pos;
		return;
	}

	if (n == 2){
		stack[pos++] = 1;
		stack[pos++] = 1;
		print();
		--pos;
		--pos;
		stack[pos++] = 2;
		print();
		--pos;
		return;
	}

	int lim = n;
	for (int i = 1; i <= lim; ++i){
		stack[pos++] = i;
		solve(n - i);
		--pos;
	}
}
int main(){
	int lim;
	cin >> n;
	lim = n / 2;
	std::string s;
	s += n;
	flag.insert(s);
	solve(n);
	return 0;
}
