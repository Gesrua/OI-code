#include <iostream>
int a,n,m,x;
int fibo[22] = {0,1,1};
void init() {
    int i;
    for (i=3; i<22; i++)
        fibo[i] = fibo[i-2] + fibo[i-1];
    std::cin>>a>>n>>m>>x;
}
int p;
int main() {
    init();
    p = (fibo[n-3] * a + a - m) / (1 - fibo[n-2]);
    int ans = fibo[x-3]*a+fibo[x-2]*p+a-p+fibo[x-4]*a+fibo[x-3]*p;
    std::cout<<ans;
    return 0;
}
