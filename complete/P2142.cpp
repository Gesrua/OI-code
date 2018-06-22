#include <bits/stdc++.h>
int main(){
	using std::cin;
	using std::cout;
	using std::endl;
	std::string s1, s2;
	int tot;
	cin >> s1;
	cin >> s2;
	int a[100000];

	if (s1.size() < s2.size()){
		cout << '-';
		std::swap(s1, s2);
	}
	if (s1.size() == s2.size()){
		for (int i = 0; i < s1.size(); ++i){
			if (s1[i] < s2[i]){
				std::swap(s1, s2);
				cout << '-';
				break;;
			}
			if (s1[i] > s2[i]) break;
		}
	}
	//cout << endl << s1 << ' ' << s2;

	tot = s1.size();
	for (int i = 1; i <= s1.size(); ++i)
		a[i]  = s1[tot - i] - '0';

	for (int i = 1; i <= s2.size(); ++i)
		a[i] -= s2[s2.size() - i] - '0';

	for (int i = 1; i <= tot; ++i){
		if (a[i] < 0){
			--a[i + 1];
			a[i] += 10;
		}
	}
	while ((a[tot] == 0) && (tot > 0)) --tot;
	if (tot <= 0){
		cout << '0';
		return 0;
	}
	for (int i = tot; i > 0; --i)
		cout << a[i];
	return 0;
}