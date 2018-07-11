#include <iostream>
#include <cstring>
using std::cin; using std::cout; using std::cerr; using std::endl; using std::min; using std::max;
const int MOD = 1000000007;
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
} A, B;
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
	long long k;
	cin >> n >> k;
	A.init(n, n);
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j)
			cin >> A.a[i][j];
	}
	B = A;
	--k;
	while (k > 0){
		if (k & (long long)1){
			B = B * A;
		}
		A = A * A;
		k >>= 1;
	}
	cout << B;
	return 0;
}