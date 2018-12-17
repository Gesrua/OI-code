#include <cstdio>
#include <iostream>
#include <utility>
#include <cmath>
#include <cstring>
#include <string>
#include <complex>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#define rep(i, l, r) for (int i = (l); i < (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cin; using std::cout; using std::cerr; using std::endl;
using std::make_pair; using std::pair;
typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned int ui;

const double PI = acos(-1);
const int N = 2097152;

struct cp{
    double real, imag;
    cp(){real = 0, imag = 0;}
    cp(double _real, double _imag){real = _real, imag = _imag;}
}a[N], b[N];
cp operator+ (const cp& a, const cp& b){return cp(a.real+b.real, a.imag+b.imag);}
cp operator* (const cp& a, const cp& b){return cp(a.real*b.real-a.imag*b.imag, a.real*b.imag+a.imag*b.real);}
cp operator- (const cp& a, const cp& b){return cp(a.real-b.real, a.imag-b.imag);}

struct FastFourierTransform{
    int r[N];
    cp omega[N], invomega[N];
    int n, pow; // n = 2^k;
    void init(){
        // this->n = n;
        rep(i, 0, n) r[i] = (r[i>>1]>>1)|((i&1)<<(pow-1));
        rep(i, 0, n) omega[i] = cp(cos(2*PI/n*i), sin(2*PI/n*i));
        rep(i, 0, n) invomega[i] = cp(cos(2*PI/n*i), sin(-2*PI/n*i));
    }
    void transform(cp a[], int n, cp omega[]){
        rep(i, 0, n) if (i < r[i]) std::swap(a[i], a[r[i]]);
        for (int l = 2; l <= n; l *= 2){
            int m = l/2;
            for(cp* p = a; p != a+n; p += l){
                rep(i, 0, m){
                    cp t = omega[n/l*i] * p[i+m];
                    p[i+m] = p[i] - t;
                    p[i] = p[i] + t;
                }
            }
        }
    }

    void dft(cp a[], const int n){
        transform(a, n, omega);
    }

    void idft(cp a[], const int n){
        transform(a, n, invomega);
        rep(i, 0, n) a[i].real /= n;
    }

    void multiply(cp a1[], const int n1, cp a2[], const int n2){
        n = 1;
        pow = 0;
        while(n < n1 + n2) ++pow, n *= 2;
        // cerr << n << ' ' << pow << endl;
        init();
        // rep(i, 0, n) cerr << r[i] << ' ';
        // cerr << endl;
        cerr << "begin dft" << endl;
        dft(a1, n); dft(a2, n);
        rep(i, 0, n) a1[i] = a1[i] * a2[i];
        cerr << "begin idft" << endl;
        idft(a1, n);
    }
} fft;

int main(){
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, m;
    cin >> n >> m; ++n; ++m;
    rep(i, 0, n) cin >> a[i].real;
    rep(i, 0, m) cin >> b[i].real;
    cerr << "begin FFT" << endl;
    fft.multiply(a, n, b, m);
    rep(i, 0, n+m-1) cout << int(floor(a[i].real+0.5)) << ' ';
    return 0;
}