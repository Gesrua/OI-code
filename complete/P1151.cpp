#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
int main(){
    std::ios::sync_with_stdio(false);
    int k, i, ans, sub1, sub2, sub3;
    cin >> k;
    bool flag = true;
    for (i = 10000; i <= 30000; ++i){
        sub1 = i / 100;
        sub2 = (i % 10000) / 10;
        sub3 = i % 1000;
        if (sub1 % k == 0 && sub2 % k == 0 && sub3 % k == 0){
            cout << i << endl;
            flag = false;
        }
    }
    if (flag) cout << "No";
    return 0;
}
