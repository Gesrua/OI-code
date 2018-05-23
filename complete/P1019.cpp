#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
using std::min;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
int n, ans = 0;
std::string s[22];
int a[22][22];
int book[22];
void solve(int sum, int prev){
    // cerr << prev << endl;
    if (sum > ans) ans = sum;
    for (int i = 1; i <= n; ++i){
        if (book[i] != 0 && a[prev][i] != -1){
            --book[i];
            solve(sum + s[i].size() - a[prev][i], i);
            ++book[i];
        }
    }
}
int main(){
    char c;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> s[i];
        book[i] = 2;
    }
    cin >> c;
    //cout << s[2][0];
    for (int i = 1; i <= n; ++i){
        // cerr << "i = " << i << endl;
        for (int  j = 1; j <= n; ++j){
            // cerr << "j = " << j << endl;
            a[i][j] = -1;
            int l, pos = -1;
            while ( (pos = s[i].find(s[j][0], pos + 1)) != std::string::npos){
                // cerr << "pos = " << pos << endl;
                if ((l = s[i].size() - pos) >= s[j].size()) continue;
                if (s[j].find(s[i].substr(pos, l)) == 0){
                    a[i][j] = l;
                }
            }
        }
    }
    /*
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j)
            cerr << a[i][j] << ' ';
        cerr << endl;
    }
    */
    for (int i = 1; i <= n; ++i){
        // cerr << "i = " << i << endl;
        if (s[i][0] == c){
            // cerr << "right" << endl;
            --book[i];
            solve(s[i].size(), i);
            ++book[i];
        }
    }
    cout << ans << endl;
    return 0;
}
