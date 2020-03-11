#include <cmath>
#include <iostream>
int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= int(std::sqrt(n)); i++) {
        std::cout << i * i << ' ';
    }
}
