#include <cstring>
#include <iostream>
#include <string>
std::string opt;
using std::cin;
using std::cout;
int x[31] = {}, y[31], t[31], tmp, s[31];
int main() {
    s[0] = 1;
    for (int i = 1; i < 31; ++i) {
        s[i] = s[i - 1] * 2;
    }
    for (int i = 0; i < 31; ++i) {
        y[i] = 1;
    }
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> opt >> tmp;
        std::memset(t, 0, sizeof(t));
        for (int j = 30; j >= 0; --j) {
            if (tmp >= s[j]) {
                tmp -= s[j];
                t[j] = 1;
            } else {
                t[j] = 0;
            }
        }
        switch (opt[0]) {
            case 'A':
                for (int j = 30; j >= 0; --j) {
                    if (x[j] != 1 || t[j] != 1) {
                        x[j] = 0;
                    }
                    if (y[j] != 1 || t[j] != 1) {
                        y[j] = 0;
                    }
                }
                break;
            case 'O':
                for (int j = 30; j >= 0; --j) {
                    if (t[j] == 1) {
                        x[j] = 1;
                    }
                    if (t[j] == 1) {
                        y[j] = 1;
                    }
                }
                break;
            case 'X':
                for (int j = 30; j >= 0; --j) {
                    if (x[j] == t[j]) {
                        x[j] = 0;
                    } else {
                        x[j] = 1;
                    }
                    if (y[j] == t[j]) {
                        y[j] = 0;
                    } else {
                        y[j] = 1;
                    }
                }
                break;
        }
    }
    unsigned int ans = 0;
    for (int i = 30; i >= 0; --i) {
        if (x[i] == 1) {
            ans += s[i];
        } else {
            if ((m >= s[i]) && (y[i] == 1)) {
                m -= s[i];
                ans += s[i];
            }
        }
    }
    cout << ans;
    return 0;
}

// #include <iostream>
// #include <string>
// std::string opt;
// using std::cin;using std::cout;
// unsigned int x = 0, y, t;
// int main(){
//     y = -1;
//     int n, m;
//     cin >> n >> m;
//     for (int i = 0; i < n; ++i){
//         cin >> opt >> t;
//         switch(opt[0]){
//             case 'A':x&=t,y&=t;break;
//             case 'O':x|=t,y|=t;break;
//             case 'X':x^=t,y^=t;break;
//         }
//     }
//     unsigned int ans = 0;
//     for (int i = 30; i >= 0; --i){
//         if (x & (1<<i)){
//             ans |= 1 << i;
//         }else{
//             if ((m>=(1<<i))&&(y & (1 << i))){
//                 m -= 1<<i;
//                 ans += 1<<i;
//             }
//         }
//     }
//     cout << ans;
//     return 0;
// }
