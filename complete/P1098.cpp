#include <bits/stdc++.h>
int p1, p2, p3;
std::string s;
int typ(char c){
    if (c >= 'a' && c <= 'z') return 2;
    if (c >= '0' && c <= '9') return 1;
    return 0;
}
void write(char c, int x){
    for (int i=0; i<x; ++i) std::cout << c;
}
int main(){
    using std::cout;
    using std::string;
    std::cin >> p1 >> p2 >> p3;
    std::cin >> s;
    int pos = 0, t1, t2;
    cout << s[0];
    int i = 1;
    int end = s.size() - 1;
    while (i != end){
        if (s[i] == '-'){
            t1 = typ(s[i-1]); t2 = typ(s[i+1]);
            if (s[i-1]+1 == int(s[i+1])) {++i; continue;}
            if (t1 != t2 || s[i-1] >= s[i+1] || t1 == 0 || t2 == 0){
                cout << '-';
                ++i;
                continue;
            }
            if (p1 == 3){
                write('*', (s[i+1] - s[i-1] - 1)*p2); 
            }else{
                char start, end, step;
                if (p3 == 1) {start = s[i-1]+1;end=s[i+1];step = 1;}
                else {start = s[i+1]-1; end = s[i-1];step = -1;}
                if (p1 == 2 && t1 == 2) {start -= 'a' - 'A'; end -= 'a' - 'A';}
                for (;start!=end;start = start + step){
                    write(start, p2);
                }

            }
        }else cout << s[i];
        ++i;
    }
    cout << s[s.size()-1];
    return 0;
}