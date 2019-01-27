#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
//#include <map>
using namespace std;
long long dp[21][21][21];
long long w(long long a, long long b, long long c) {
    if (0 < a && a <= 20 && 0 < b && b <= 20 && 0 < c && c <= 20 && dp[a][b][c] != -1) return dp[a][b][c];
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);
    // if (dp[a][b][c]!=-1) return dp[a][b][c];
    if (a < b && b < c) return dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    return dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}
int main() {
    ios::sync_with_stdio(false);
    memset(dp, -1, sizeof(dp));
    long long a, b, c;
    w(20, 20, 20);
    while (cin >> a >> b >> c && (a != -1 || b != -1 || c != -1)) cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
    return 0;
}
