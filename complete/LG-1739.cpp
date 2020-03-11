#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
int main() {
    int s;
    std::string str;
    while (cin >> str) {
        s = 0;
        bool flag = true;
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == '(') ++s;
            if (str[i] == ')') --s;
            if (s < 0) {
                flag = false;
                break;
            }
        }
        if (s != 0) flag = false;
        if (flag)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}