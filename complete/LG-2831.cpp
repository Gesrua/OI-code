#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;

const int N = 19;
int line[N][N];
int f[1<<N];
typedef std::pair<double, double> pdd;
std::set<pdd> s;

struct Pt{
    double x, y;
} a[N];

const double eps = 1e-6;
inline bool eq(double a, double b){
    return fabs(a-b)<eps;
}

void solve(){
    std::memset(line, 0, sizeof(line));
    std::memset(f, 0x3f, sizeof(f));
    int n, m; cin >> n >> m;
    s.clear();
    for(int i = 0; i < n; ++i){
        cin >> a[i].x >> a[i].y;
        if (s.count({a[i].x, a[i].y})) --i, --n;
        else s.insert({a[i].x, a[i].y});
    }
    for(int i = 0; i < n; ++i){
        line[i][i] = (1<<i);
        for(int j = 0; j < n; ++j){
            if (i == j || eq(a[i].x, a[j].x)) continue;
            double p = (a[i].y/a[i].x-a[j].y/a[j].x)/(a[i].x-a[j].x), q = a[i].y/a[i].x-p*a[i].x;
            if (p >= 0) continue; 
            for(int k = 0; k < n; ++k){
                if (eq(p*a[k].x*a[k].x+q*a[k].x, a[k].y)){
                    line[i][j] |= (1<<k);
                }
            }
            // cerr << line[i][j] << ' ';
        }
        // cerr << endl;
    }
    f[0] = 0;
    for(int i = 0; i < (1<<n)-1; ++i){
        int j = 0;
        for(; i&(1<<j); ++j) ;
        for(int k = j; k < n; ++k){
            f[i|(line[j][k])] = std::min(f[i|(line[j][k])], f[i] + 1);
        }
    }
    cout << f[(1<<n)-1] << endl;
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int t; cin >> t; while(t--) solve();
    return 0;
}
