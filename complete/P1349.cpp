#include <iostream>
#include <cstring>
using std::cin; using std::cout; using std::cerr; using std::endl; using std::min; using std::max;
int MOD = 1000000007;
struct matrix {
	long long a[110][110], m, n;
	void init(const int &nM, const int &nN){
		std::memset(this->a, 0, sizeof(this->a));
		this->m = nM;
		this->n = nN;
	}
	matrix operator=(const matrix &s){
		this->init(s.m, s.n);
		for (int i = 0; i <= s.m; ++i)
			for (int j = 0; j <= s.n; ++j)
				this->a[i][j] = s.a[i][j];
		return *this;
	}
	matrix operator*(const matrix &s){
		matrix ans;
		ans.init(this->m, s.n);
		for (int i = 1; i <= this->m; ++i){
			for (int j = 1; j <= s.n; ++j){
				for (int k = 1; k <= this->n; ++k){
					ans.a[i][j] += (long long)this->a[i][k] % MOD * ((long long)s.a[k][j] % MOD) % MOD;
				}
			}
		}
		return ans;
	}
} A, B, C;
std::ostream& operator<<(std::ostream &out,  matrix &s){
	for (int i = 1; i <= s.m; ++i){
		// out << '[';
		for (int j = 1; j <= s.n; ++j){
			out << s.a[i][j] % MOD << ' ';
		}
		out << "\n";
	}
	return out;
}
int main(){
	std::ios::sync_with_stdio(false);
	int n;
	A.init(1, 2);
	B.init(2, 2);
	B.a[1][1] = 0;
	B.a[2][1] = 1;
	cin >> B.a[2][2] >> B.a[1][2] >> A.a[1][1] >> A.a[1][2] >> n >> MOD;
	// MOD = 10000000;
	if (n <= 2){
		cout << A.a[1][n];
		return 0;
	}
	n -= 3;
	C = B;
	while (n > 0){
		if (n & 1){
			C = C * B;
		}
		B = B * B;
		n >>= 1;
	}
	A = A * C;

	cout << A.a[1][2] % MOD;
	return 0;
}