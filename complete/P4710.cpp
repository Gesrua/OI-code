#include <iostream>
#include <cmath>
#include <iomanip>
using std::cin;using std::cout;
int main(){
    long double theta, t, v, v0, vert;
    cin >> v >> theta;
    vert = v * std::sin(theta);
    t = v * std::cos(theta) / 10;
    cout.setf(std::ios::fixed);
    cout << vert * t  << ' ' << v * std::cos(theta)/2*t;
}