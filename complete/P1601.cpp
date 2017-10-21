#include <bits/stdc++.h>
int main(){
	using std::cin;
	using std::cout;
	using std::endl;
	std::string s;
	cin >> s;
	int a[1000] = {}, tot;
	tot = s.size();
	for (register int i=1;i<=tot;++i)
		a[i] = s[tot-i] - '0';
	cin >> s;
	int t = s.size();
	for (register int i=1;i<=t;++i){
		a[i] += s[t-i] - '0';
		a[i+1] += a[i] / 10;
		a[i] %= 10;
	}
	tot = std::max(tot, t);
	if (a[tot+1] != 0) ++tot;
	for (register int i=tot;i>0;--i)
		cout << a[i];
	return 0;
}