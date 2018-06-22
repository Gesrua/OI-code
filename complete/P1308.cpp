#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int main(){
	string word,s;
	getline(cin,word);
	transform(word.begin(), word.end(), word.begin(), ::toupper);
	word = ' ' + word + ' ';
	//cout<<word;
	getline(cin,s);
	transform(s.begin(), s.end(), s.begin(), ::toupper);
	s = ' ' + s + ' ';
	int first_where = s.find(word);
	//cout<<s;
	int where = first_where;
	if (where == -1){cout << -1; return 0; }
	int count,pos;
	count = 0;
	while (where != -1){
		pos = where + 1;
		count++;
		where = s.find(word,pos);
	}
	cout << count << ' ' << first_where;
	return 0;
}
