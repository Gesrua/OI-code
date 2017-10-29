#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
int main(){
	int i=1, j, k=0, t=0, x=0, ans_x, ans_k;
	bool nagative=false;
	char c, last='+', letter;
	bool flag=false, num=false;
	while (cin >> c){
		if (c>='0' && c<='9'){
			t = t*10 + c - '0';
            num = true;
            last = c;
			continue;
		}
		if (c == '+' || c == '='){
			if (nagative) t = -t;
			i *= t;
			if (flag){
                if (num == false) i = 1;
				x += i;
            }
			else
				k += i;
			t = 0;
			i = 1;
			nagative = false;
			flag = false;
            num = false;
            if (c == '=') break;
		}
		if (c == '-'){
			if (last == '+'){
				nagative = true;
                last = c;
				continue;
			}
			if (nagative) t = -t;
			i *= t;
			nagative = true;
			if (last == '*') continue;
			if (flag) x += i;
			else k+=i;
			i = 1;
			t = 0;
			flag = false;
            num = false;
		}
		if (c == '*'){
			if (nagative) t = -t;
			i *= t;
			t = 0;
			nagative = false;
		}
		if ((c >= 'a' && c<='z') || (c >= 'A' && c<= 'Z')){
            flag = true;
            letter = c;
        }
		last = c;
	}
    //cout << x << ' ' << k << endl;
    ans_x = x;
    ans_k = -k;

	i=1;k=0;t=0;x=0;
	nagative=false;
	last='+';
	flag=false;
    num = false;
    while (cin >> c){
		if (c>='0' && c<='9'){
			t = t*10 + c - '0';
            num = true;
            last = c;
			continue;
		}
		if (c == '+' || c == '='){
			if (nagative) t = -t;
			i *= t;
			if (flag){
                if (num == false) i = 1;
				x += i;
            }
			else
				k += i;
			t = 0;
			i = 1;
			nagative = false;
			flag = false;
            num = false;
            if (c == '=') break;
		}
		if (c == '-'){
			if (last == '+'){
				nagative = true;
                last = c;
				continue;
			}
			if (nagative) t = -t;
			i *= t;
			nagative = true;
			if (last == '*') continue;
			if (flag) x += i;
			else k+=i;
			i = 1;
			t = 0;
			flag = false;
            num = false;
		}
		if (c == '*'){
			if (nagative) t = -t;
			i *= t;
			t = 0;
			nagative = false;
		}
		if ((c >= 'a' && c<='z') || (c >= 'A' && c<= 'Z')){
            flag = true;
            letter = c;
        }
		last = c;
	}
	if (nagative) t = -t;
		i *= t;
	if (flag)
		x += i;
	else
		k += i;
    //cout << x << ' ' << k << endl;
	ans_x = ans_x - x;
	ans_k = ans_k + k;
    //cout << ans_x << ' ' << ans_k << endl;
    cout << letter << '=';
	std::printf("%.3f",ans_k/double(ans_x));
    //cout << ans_k/double(ans_x);
	return 0;
}
