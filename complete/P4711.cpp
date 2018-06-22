#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <cctype>
std::map<std::string, double> sheet;
// using std::cin;using std::cout;
std::string s, h2o;
int i;
using namespace std;
inline int getNum(){
	int ans = 0;
	do {
		ans *= 10;
		ans += s[i++] - '0';
	} while (isdigit(s[i]));
	return ans;
}
inline double getElement(){
	std::string ele = "";
	do {
		ele += s[i++];
	} while (islower(s[i]) && i < s.size());
	double ans = sheet[ele];
	if (i == s.size()) return ans;
	if (s[i] == '_'){
		i += 2;
		ans *= getNum();
		++i;
		return ans;
	}
	return ans;
}
void init();
int main(){
	init();
	cin >> s;
	if (s.find('~') == string::npos){
		h2o = "";
	}else{
		h2o = s.substr(s.find('~') + 1, s.size());
		s = s.substr(0, s.find('~'));
	}
	double ele = 0;
	double ans = 0;
	for (i = 0; i < s.size(); ){
		if (isupper(s[i])){
			ele = getElement();
			ans += ele;
		}else{
			if (s[i] == '('){
				ele = 0;
				while (s[i] != ')'){
					ele += getElement();
				}
				if (s[++i] == '_'){
					i += 2;
					ele *= getNum();
					++i;
				}
				ans += ele;
			}
		}
	}
	if (!h2o.empty()){
		if (isdigit(h2o[0])){
			int t = 0;
			int i = 0;
			do {
				t *= 10;
				t += h2o[i++] - '0';
			} while (isdigit(h2o[i]));
			ans += t * 18;
		}else{
			ans += 18;
		}
	}
	int t = ans;
	if (t == ans) cout << t;
	else{
		cout.setf(ios::fixed);
		cout << setprecision(1) << ans;
	}
	return 0;
}
void init(){
	sheet["H"] = 1;
	sheet["C"] = 12;
	sheet["N"] = 14;
	sheet["O"] = 16;
	sheet["F"] = 19;
	sheet["Na"] = 23;
	sheet["Mg"] = 24;
	sheet["Al"] = 27;
	sheet["Si"] = 28;
	sheet["P"] = 31;
	sheet["S"] = 32;
	sheet["Cl"]  = 35.5;
	sheet["K"] = 39;
	sheet["Ca"]  = 40;
	sheet["Mn"]  = 55;
	sheet["Fe"]  = 56;
	sheet["Cu"]  = 64;
	sheet["Zn"]  = 65;
	sheet["Ag"]  = 108;
	sheet["I"] = 127;
	sheet["Ba"]  = 137;
	sheet["Hf"]  = 178.5;
	sheet["Pt"]  = 195;
	sheet["Au"]  = 197;
	sheet["Hg"]  = 201;
}
