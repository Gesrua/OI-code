#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl; using std::make_pair; using std::pair;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull; typedef pair<int, int> pii; 

struct Vector{
    double x, y;
    Vector(){ x = y = 0; }
    Vector(double _x, double _y){ x = _x, y = _y; }
    Vector operator+(const Vector& rhs) const {
        Vector ret(x + rhs.x, y + rhs.y);
        return ret;
    }
    Vector operator-(const Vector& rhs) const {
        Vector ret(x - rhs.x, y - rhs.y);
        return ret;
    }
    double operator*(const Vector& rhs) const {
        return x*rhs.y - y*rhs.x;
    }
    Vector operator>>(const Vector& rhs){
        return rhs - *this;
    }
    bool operator<(const Vector& rhs) const {
        return x == rhs.x ? y < rhs.y : x < rhs.x;
    }
    double len(){
        return std::sqrt(x*x+y*y);
    }
};

Vector a[int(1e5+10)];
int used[int(1e5+10)];

Vector convex[int(1e5+10)]; int sz, stk[int(1e5+10)];

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n;
    cin >> n;
    rep(i, 1, n) cin >> a[i].x >> a[i].y;
    std::sort(a+1, a+1+n);
    stk[sz=1] = 1;
    rep(i, 2, n){
        while(sz >= 2 && (a[stk[sz-1]] >> a[stk[sz]]) * (a[stk[sz]] >> a[i]) < 0){
            used[stk[sz--]] = 0;
        }
        used[i] = 1;
        stk[++sz] = i;
    }
    int dh = sz;
    per(i, n, 1){
        if (used[i]) continue;
        while(sz > dh && (a[stk[sz-1]] >> a[stk[sz]]) * (a[stk[sz]] >> a[i]) < 0)
            used[stk[sz--]] = 0;
        used[i] = 1;
        stk[++sz] = i;
    }
    double ans = 0;
    rep(i, 1, sz-1){
        // ans += a[stk[i]]*a[stk[i+1]];
        ans += (a[stk[i]]>>a[stk[i+1]]).len();
    }
    cout.setf(std::ios::fixed);
    cout << std::setprecision(2) << ans << endl;
    return 0;
}