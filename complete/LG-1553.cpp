#include <iostream>
#include <string>
using namespace std;
string s, s1, s2, ans;
string inverse(string s) {
    string ans;
    int i;
    bool flag;
    flag = true;
    while (flag) {
        if (s[0] == '0')
            s.erase(0, 1);
        else
            flag = false;
    }
    flag = true;
    for (i = s.length() - 1; i >= 0; i--) {
        if (flag)
            if (s[i] != '0') flag = false;
        if (flag) continue;
        ans = ans + s[i];
    }
    if (ans.empty()) ans = '0';
    return ans;
}
void tell_apart(int where) {
    s1 = s;
    s1.erase(where, s1.length() - where + 1);
    s2 = s;
    s2.erase(0, where + 1);
    return;
}
void solve() {
    int where;
    if ((s.find('.') == string::npos) && (s.find('/') == string::npos) && (s.find('%') == string::npos)) {
        ans = inverse(s);
        return;
    } else {
        where = s.find('.');
        if (where != -1) {
            tell_apart(where);
            ans = inverse(s1) + "." + inverse(s2);
            return;
        }
        where = s.find('/');
        if (where != -1) {
            tell_apart(where);
            ans = inverse(s1) + "/" + inverse(s2);
            return;
        } else {
            s = s.erase(s.length() - 1);
            ans = inverse(s) + "%";
        }
    }
    return;
}
int main() {
    getline(cin, s);
    solve();
    cout << ans;
    return 0;
}
