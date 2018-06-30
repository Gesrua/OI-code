#include <iostream>
using std::cin; using std::cout; using std::cerr; using std::endl; using std::min; using std::max;
int main(){
    int n, s = 0, a[200], t;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> t;
        s += t/100000000;
        t %= 100000000;
        s += t/50000000;
        t %= 50000000;
        s += t/20000000;
        t %= 20000000;
        s += t/10000000;
        t %= 10000000;
        s += t/5000000;
        t %= 5000000;
        s += t/2000000;
        t %= 2000000;
        s += t/1000000;
        t %= 1000000;
        s += t/500000;
        t %= 500000;
        s += t/200000;
        t %= 200000;
        s += t/100000;
        t %= 100000;
        s += t/50000;
        t %= 50000;
        s += t/20000;
        t %= 20000;

        s += t/10000;
        t %= 10000;
        s += t/5000;
        t %= 5000;
        s += t/2000;
        t %= 2000;

        s += t/1000;
        t %= 1000;
        s += t/500;
        t %= 500;
        s += t/200;
        t %= 200;
        s += t/100;
        t %= 100;
        s += t/50;
        t %= 50;
        s += t/20;
        t %= 20;
        s += t/10;
        t %= 10;
        s += t/5;
        t %= 5;
        s += t/2;
        t %= 2;
        s += t;
    }
    cout << s;
    return 0;
}
