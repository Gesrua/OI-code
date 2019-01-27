#include <cmath>
#include <iostream>
int main() {
    int H, V, K, S, n, L;
    std::cin >> H >> S >> V >> L >> K >> n;
    std::cout << H - K << std::endl;
    std::cout << std::max(std::ceil(S - V * std::sqrt(H / 5.0) - 1e-5), 0.0) << std::endl;
    std::cout << std::max(std::min(std::floor(S + L - V * std::sqrt((H - K) / 5.0) + 1e-5), n - 1.0) - std::max(std::ceil(S - V * std::sqrt(H / 5.0) - 1e-5), 0.0) + 1, 0.0);
    return 0;
}