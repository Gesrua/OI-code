#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using std::cin; using std::cout; using std::cerr; using std::endl; using std::min; using std::max; using std::sort;
int stack[200], pos = 0, n;
void dfs(int x){
	if (x == 0){
		for (int i = 1; i < pos; ++i){
			cout << stack[i] << '+';
		}
		cout << stack[pos] << endl;
		return;
	}
	for (int i = stack[pos]; i < min(x + 1,n); ++i){
		stack[++pos] = i;
		dfs(x - i);
		--pos;
	}
}
int main(){
	cin >> n;
	stack[0] = 1;
	dfs(n);
	return 0;
}