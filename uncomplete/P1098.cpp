#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
int p1, p2, p3;
std::string s;
int type(char x){
    if (x>='0' && x<='9') return 1;
    if (x>='a' && x<='z') return 2;
    return 0;
}
int main(){
    int pos = 0;
    cin >> p1 >> p2 >> p3;
    cin >> s;
    pos = s.find('-');
    if (pos == 0) pos = s.find('-', pos+1);
    while (pos != -1){
        if (type(s[pos-1]) == type(s[pos+1])){
            if (s[pos-1] >= s[pos+1]) continue;
            if (s[pos-1]+1 == s[pos+1]){
                s.erase(pos, 1);
                continue;
            }
        }
        s.find('-', pos+1);
    }
    return 0;
}
