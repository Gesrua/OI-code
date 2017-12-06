#include <iostream>
using std::cin;
using std::cout;
int main(){
    long long type, num, x, turn;
    cin >> type;
    cin >> x;
    if (type == 1) num = x * 16;
    if (type == 2) num = x * 64;
    if (type == 3) num = x;
    cin >> x;
    num += x;
    cin >> turn;
    if (turn == 1){
        cout << num/16 << ' ' << num%16;
    }
    if (turn == 2){
        cout << num/64 << ' ' << num % 64;
    }
    if (turn == 3){
        cout << num << " 0";
    }
    return 0;
}