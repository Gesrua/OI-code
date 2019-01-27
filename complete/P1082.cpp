#include <iostream>
typedef long long LL;
void exgcd(LL a, LL b, LL& x, LL& y) {
    if (b == 0) {
        x = 1, y = 0;
        return;
    }
    exgcd(b, a % b, x, y);
    LL k;
    k = x;
    x = y;
    y = k - a / b * x;
}
int main() {
    LL a, b;
    std::cin >> a >> b;
    LL x, y;
    exgcd(a, b, x, y);
    std::cout << (x % b + b) % b << std::endl;
    return 0;
}