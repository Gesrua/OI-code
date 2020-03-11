#include <bits/stdc++.h>
int main() {
    int n, i = 1;
    std::cin >> n;
    while (++i) {
        if (n % i == 0) {
            std::cout << n / i;
            return 0;
        }
    }
    return 0;
}
