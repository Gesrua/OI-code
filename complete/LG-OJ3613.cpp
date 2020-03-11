#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;
namespace matrix {
template <typename T, int N>
struct matrix {
    T a[N + 1][N + 1];
    int m, n;
    void init(const int &nM, const int &nN) {
        std::memset(this->a, 0x3f, sizeof(this->a));
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
        for (int i = 1; i <= this->m; ++i)
            for (int j = 1; j <= s.n; ++j)
                for (int k = 1; k <= this->n; ++k)
                    ans.a[i][j] = std::min(ans.a[i][j], this->a[i][k] + s.a[k][j]);
        return ans;
    }
    friend std::ostream &operator<<(std::ostream &out, const matrix<T, N> &s) {
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
};
}  // namespace matrix

matrix::matrix<ll, 202> a, t;

int uq[1009];
int tot = 1;
#define get(x) (uq[x]?uq[x]:(uq[x]=tot++))

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    std::memset(a.a, 0x3f, sizeof(a));

    int n, m, s, e;
    cin >> n >> m >> s >> e;
    s = get(s), e = get(e);
    while(m--){
        int u, v, w;
        cin >> w >> u >> v;
        u = get(u), v = get(v);
        a.a[u][v] = a.a[v][u] = w;
    }
    a.m = a.n = tot;
    // cout << a << endl;
    t = a;
    --n;
    while(n){
        if (n&1) t = t * a;
        a = a * a;
        n >>= 1;
    }
    // cout << t << endl;
    cout << t.a[s][e];
    return 0;
}
