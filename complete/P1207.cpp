#include <iostream>
#include <string>
using namespace std;
string change(int n, int m) {
    // int n,m;
    string ans;
    char num[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    // cin>>n>>m;
    while (n) {
        ans = num[n % m] + ans;
        n = n / m;
    }
    // cout<<ans;
    return ans;
}
bool check(string s) {
    int i, l = s.length();
    // cout<<s<<endl;
    for (i = 0; i < l / 2; i++)
        if (s[i] == s[l - i - 1])
            continue;
        else
            return false;
    return true;
}
int main() {
    int n, s, sum, i;
    cin >> n >> s;
    // cout<<check("1101");
    while (n > 0) {
        s++;
        sum = 0;
        i = 1;
        while (sum < 2 && i < 10) {
            i++;
            // temp=change(s,i);
            // cout<<temp;
            if (check(change(s, i))) sum++;
        }
        if (sum == 2) {
            n--;
            cout << s << endl;
        }
    }
    return 0;
}
