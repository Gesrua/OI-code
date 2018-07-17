#include <iostream>
void g(int n){
    if (n == 0) return;
    g(n/8);
    std::cout << n%8;
}
int main(){
    int n;
    std::cin >> n;
    if (n == 0) std::cout << 0;
    else g(n);
    return 0;
}