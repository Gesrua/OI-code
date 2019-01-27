#include <cstring>
#include <iostream>
typedef long long LL;
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;
const int MOD = 1000000007;
struct matrix {
    long long a[5][5], m, n;
    void init(const int &nM, const int &nN) {
        std::memset(this->a, 0, sizeof(this->a));
        this->m = nM;
        this->n = nN;
    }
    matrix operator=(const matrix &s) {
        this->init(s.m, s.n);
        for (int i = 0; i <= s.m; ++i)
            for (int j = 0; j <= s.n; ++j) this->a[i][j] = s.a[i][j];
        return *this;
    }
    matrix operator*(const matrix &s) {
        // if (this->n != s.m)
        // cerr << "Matrixs Can't Time";
        matrix ans;
        ans.init(this->m, s.n);
        for (int i = 1; i <= this->m; ++i) {
            for (int j = 1; j <= s.n; ++j) {
                for (int k = 1; k <= this->n; ++k) {
                    ans.a[i][j] += this->a[i][k] * s.a[k][j] % MOD;
                }
            }
        }
        return ans;
    }
} A, B, C;
std::ostream &operator<<(std::ostream &out, const matrix &s) {
    for (int i = 1; i <= s.m; ++i) {
        out << '[';
        for (int j = 1; j <= s.n - 1; ++j) {
            out << s.a[i][j] << ' ';
        }
        out << s.a[i][s.n];
        out << "]\n";
    }
    return out;
}
int main() {
    int T, n;
    std::ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> n;
        if (n <= 3) {
            cout << 1 << endl;
            continue;
        }
        A.init(1, 3);
        A.a[1][1] = A.a[1][2] = A.a[1][3] = 1;
        B.init(3, 3);
        B.a[1][1] = B.a[1][2] = B.a[2][2] = B.a[2][3] = B.a[3][1] = 0;
        B.a[1][3] = B.a[2][1] = B.a[3][2] = B.a[3][3] = 1;
        n -= 4;
        C = B;
        while (n) {
            if (n & 1) {
                C = C * B;
            }
            B = B * B;
            n = n >> 1;
        }
        A = A * C;
        // cerr << A;
        cout << A.a[1][3] % MOD << endl;
    }
    return 0;
}