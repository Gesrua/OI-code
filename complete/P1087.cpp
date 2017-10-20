#include <bits/stdc++.h>
std::string s;
char check(int l, int r){
	bool ans_i = true, ans_b = true;
	for (;l<=r && (ans_b || ans_i);l++){
		if (s[l] == '1') ans_b = false;
		if (s[l] == '0') ans_i = false;
	}
	if (ans_i) return 'I';
	else 
		if (ans_b) return 'B';
		else return 'F';
}
void solve(int l, int r){
	if (l == r){
		if (s[l] == '1') std::cout << 'I';
		else std::cout << 'B';
		return;
	}
	int mid = (l+r)/2;
	solve(l,mid);
	solve(mid+1,r);
	std::cout << check(l,r);
}
int main(int argc, char const *argv[])
{
	int n;
	std::cin >> n;
	std::cin >> s;
	solve(0, std::pow(2,n)-1);
	return 0;
}