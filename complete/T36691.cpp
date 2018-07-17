#include <iostream>
void f(int n){
    if (n == 0) return;
    std::cout << n%10;
    f(n/10);
}
int main(){
    int n;
    std::cin >> n;
    if (n == 0) std::cout << 0;
    f(n);
    return 0;
}