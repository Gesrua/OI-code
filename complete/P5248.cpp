#include <iostream>
long long a[102], n, m, f;
int main() {
    std::cin >> m >> f;
    while (f) {
        a[n++] = f % m;
        f /= m;
    }
    std::cout << n << std::endl;
    for (int i = 0; i < n; ++i) std::cout << a[i] << ' ';
    return 0;
}