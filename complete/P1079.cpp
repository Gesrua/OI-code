#include <iostream>
#include <cctype>
using std::cin; using std::cout; using std::cerr; using std::endl;
int main(){
	// char k[1010], m[1010], c[1010];
	std::string k, m, c;
	bool flag;
	cin >> k;
	cin >> c;
	int lc = c.size(), lk = k.size();
	for (int i = lk; i < lc; ++i){
		k.push_back(k[i % lk]);
	}
	for (int i = 0; i < lc; ++i){
		k[i] = std::tolower(k[i]);
		if (isupper(c[i])) flag = true;
		else flag = false;
		c[i] = std::tolower(c[i]);
		m.push_back((c[i] - k[i] + 26) % 26 + 'a');
		if (flag)
			m[i] = std::toupper(m[i]);
	}
	cout << m;
	return 0;
}