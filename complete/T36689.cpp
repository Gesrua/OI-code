#include <cstring>
#include <iostream>
const int MOD = 1000000007;
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;
struct matrix {
    int a[110][110], m, n;
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
        matrix ans;
        ans.init(this->m, s.n);
        for (int i = 1; i <= this->m; ++i) {
            for (int j = 1; j <= s.n; ++j) {
                for (int k = 1; k <= this->n; ++k) {
                    ans.a[i][j] += (long long)this->a[i][k] % MOD * ((long long)s.a[k][j] % MOD) % MOD;
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
};
int main() {
    long long n;
    cin >> n;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    --n;
    if (n <= 2) {
        cout << 1;
        return 0;
    }
    n -= 2;
    A.init(1, 2);
    A.a[1][1] = A.a[1][2] = 1;
    B.init(2, 2);
    B.a[1][1] = 0;
    B.a[2][1] = B.a[2][2] = B.a[1][2] = 1;
    C = B;
    // for (int i = 0; i <= n; ++i){
    //     A = A * B;
    //     cerr << A;
    // }
    while (n > 0) {
        if (n & 1) {
            C = C * B;
        }
        B = B * B;
        n >>= 1;
    }
    A = A * C;
    cout << A.a[1][1] % MOD;
    return 0;
}