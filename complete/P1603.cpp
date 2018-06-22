#include <bits/stdc++.h>
std::map<std::string, int> map;
int main(){
	using std::cin;
	using std::cout;
	using std::endl;
	std::string s;
	long long i, ans = 0;
	map.insert(std::make_pair("one",        1));
	map.insert(std::make_pair("two",        4));
	map.insert(std::make_pair("three",      9));
	map.insert(std::make_pair("four",       16));
	map.insert(std::make_pair("five",       25));
	map.insert(std::make_pair("six",        36));
	map.insert(std::make_pair("seven",      49));
	map.insert(std::make_pair("eight",      64));
	map.insert(std::make_pair("nine",       81));
	map.insert(std::make_pair("ten",        0));
	map.insert(std::make_pair("eleven",     21));
	map.insert(std::make_pair("twelve",     44));
	map.insert(std::make_pair("thirteen",   69));
	map.insert(std::make_pair("fourteen",   96));
	map.insert(std::make_pair("fifteen",    25));
	map.insert(std::make_pair("sixteen",    56));
	map.insert(std::make_pair("seventeen",  89));
	map.insert(std::make_pair("eighteen",   89));
	map.insert(std::make_pair("nineteen",   61));
	map.insert(std::make_pair("twenty",     0));
	map.insert(std::make_pair("a",          1));
	map.insert(std::make_pair("both",       4));
	map.insert(std::make_pair("third",      9));
	map.insert(std::make_pair("second",     4));
	map.insert(std::make_pair("first",      1));
	map.insert(std::make_pair("another",    1));

	for (i = 0; i < 6; i++){
		cin >> s;
		if (map.count(s) != 0)
			ans = ans * 100 + map[s];
	}
	if (ans < 10 && ans != 0) cout << '0';
	cout << ans;
	return 0;
}