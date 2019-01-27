#include <cmath>
#include <iostream>
using namespace std;
int stack[20], n, m, long_n, long_m;
bool book[100000001] = {0};
bool is_prime(int n) {
    int i;
    int s = sqrt(double(n));
    for (i = 2; i <= s; i++)
        if (n % i == 0) return false;
    return true;
}
void solve() {
    book[2] = book[3] = book[5] = book[7] = book[11] = true;
    int i, j, k, l, temp;
    if (m <= 100) return;
    for (i = 1; i <= 9; i += 2)
        for (j = 0; j <= 9; j++) {
            temp = i * 100 + j * 10 + i;
            if (is_prime(temp)) book[temp] = true;
        }
    if (m <= 10000) return;
    for (i = 1; i <= 9; i += 2)
        for (j = 0; j <= 9; j++)
            for (k = 0; k <= 9; k++) {
                temp = i * 10000 + j * 1000 + k * 100 + j * 10 + i;
                if (is_prime(temp)) book[temp] = true;
            }
    if (m <= 1000000) return;
    for (i = 1; i <= 9; i += 2)
        for (j = 0; j <= 9; j++)
            for (k = 0; k <= 9; k++)
                for (l = 0; l <= 9; l++) {
                    temp = i * 1000000 + j * 100000 + k * 10000 + l * 1000 + k * 100 + j * 10 + i;
                    if (is_prime(temp)) book[temp] = true;
                }
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    solve();
    int i;
    for (i = n; i <= m; i++)
        if (book[i]) cout << i << endl;
    return 0;
}
