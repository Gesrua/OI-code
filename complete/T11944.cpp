#include <iostream>
#include <utility>
#include <algorithm>
using std::cin;using std::cout;using std::endl;using std::cerr;
int main(){
    int a[3];
    while(cin >> a[0] >> a[1] >> a[2]){
        std::sort(a, a+3);
        if (a[1] == 0){
            cout << "QAQ" << endl;
            continue;
        }
        if ((a[1] - a[0])%2 == 0){
            cout << a[1] << endl;
            continue;
        }else{
            cout << a[2] << endl;
        }
    }
    return 0;
}