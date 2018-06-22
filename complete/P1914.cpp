#include <iostream>
#include <string>
using namespace std;
int main()
{
	int i,n,temp;
	string s;
	cin >> n;
	getline(cin,s);
	getline(cin,s);
	int length = s.length();
	for (i = 0; i < length; i++)
	{
		temp = s[i] - 'a' + n;
		temp = temp % 26;
		s[i] = temp + 'a';
	}
	cout << s;
	return 0;
}
