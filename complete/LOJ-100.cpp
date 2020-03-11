#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
const long long MOD = 1000000000 + 7;
long long A[510][510], B[510][510], C[510][510];
#define rep(i, l, r) for (register int i = (l); i <= (r); ++i)
int main() {
    int n, p, m;
    std::ios::sync_with_stdio(false);
    cin >> n >> p >> m;
    rep(i, 1, n) rep(j, 1, p) {
        cin >> A[i][j];
        A[i][j] = (A[i][j] % MOD + MOD) % MOD;
    }
    rep(i, 1, p) rep(j, 1, m) {
        cin >> B[i][j];
        B[i][j] = (B[i][j] % MOD + MOD) % MOD;
    }
    rep(i, 1, n) rep(j, 1, m) {
        C[i][j] = 0;
        rep(k, 1, p) { C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD; }
    }
    rep(i, 1, n) {
        rep(j, 1, m) cout << C[i][j] << ' ';
        cout << endl;
    }
    return 0;
}