#include <math.h>
#include <iostream>
using namespace std;
int sum;
void rule(int n) {
    sum++;
    for (int i = 1; i <= n / 2; i++) {
        rule(i);
    }
}
int main() {
    sum = 0;
    int n;
    cin >> n;
    rule(n);
    cout << sum;
}
