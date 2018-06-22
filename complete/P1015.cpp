#include <bits/stdc++.h>
int a[1000], tot, t[1000], n;
void plus(){
	int i;
	for (i = 1; i <= tot; i++)
		t[i] = a[tot - i + 1];
	for (i = 1; i <= tot; i++){
		a[i] = a[i] + t[i];
		a[i + 1] += a[i] / n;
		a[i] = a[i] % n;
	}
	if (a[tot + 1] != 0) tot++;
}
bool check(){
	for (int i = 1; i <= tot; i++)
		if (a[i] != t[i]) return false;
	return true;
}
int main(int argc, char const *argv[]){
	using std::cin;
	using std::cout;
	using std::endl;
	int step = 0, i;
	std::string s;
	cin >> n >> s;
	tot = s.size();
	for (i = 1; i <= tot; i++){
		if (s[tot - i] > 58) a[i] = std::toupper(s[tot - i]) - 65 + 10;
		else a[i] = s[tot - i] - '0';
	}
	for (i = 1; i <= tot; i++)
		t[i] = a[tot - i + 1];
	while (step < 31){
		if (check()){
			cout << "STEP=" << step;
			return 0;
		}
		step++;
		plus();
		for (i = 1; i <= tot; i++){
			t[i] = a[tot - i + 1];
			//cout << t[i];
		}
		//cout << endl;
	}
	cout << "Impossible!";
	return 0;
}