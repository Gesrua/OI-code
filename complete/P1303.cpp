#include <bits/stdc++.h>
int main(){
	using std::cin;
	using std::cout;
	using std::endl;
	short a[4002] = {}, ans[4002] = {};
	std::string s1, s2;
	cin >> s1 >> s2;
	int t1, t2, i, j;
	if (s1.size() < s2.size()) std::swap(s1, s2);
	t1 = s1.size();
	t2 = s2.size();
	for (i=1;i<=t2;++i){
		for (j=1;j<=t1;++j){
			//cout << i << ' ' << j << ' ' << s2[i-1] << ' ' << s1[j-1] << ' ' << ans[i+j-1]<< ' '; 
			ans[i+j-1] += (s2[t2-i] - '0') * (s1[t1-j] - '0');
			//cout << ans[i+j-1] <<endl;
		}
	}
	
	t1 += t2;
	for (i=1;i<=t1;++i){
		ans[i+1] += ans[i]/10;
		ans[i] %= 10;
	}
	while((ans[t1] == 0) && (t1>0)) --t1;
	if (t1<=0)
		cout << '0';
		
	for (i=t1;i>=1;--i)
		cout << ans[i];
	return 0;
}