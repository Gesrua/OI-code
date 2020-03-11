#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
// const int N = 200000;
std::queue<int> q;
int main() {
    std::ios::sync_with_stdio(false);
    int t, n, ans, max = -2100000000, sum = 0;
    cin >> n;
    while (n) {
        cin >> t;
        if (sum < 0) {
            std::queue<int> empty;
            std::swap(empty, q);
            sum = 0;
        }
        q.push(t);
        sum += t;
        if (sum > max) max = sum;
        --n;
    }
    cout << max;
    return 0;
}