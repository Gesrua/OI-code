#include <iostream>
using std::cin;
using std::cout;
const unsigned long long mod = 2333333333333;
long long f(int x) { return x == 1 ? 1 : x * f(x - 1) % mod; }
int main() {
    int n;
    cin >> n;
    cout << n << "!=" << f(n);
    return 0;
}