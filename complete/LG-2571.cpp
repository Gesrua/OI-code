#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define Rn(n) for (int i = 0; i < (n); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int ui;

const int cnt = 100, inf = 0x3f3f3f3f;

inline double dis(double a, double b) { return std::sqrt(a * a + b * b); }

struct Vector {
    double x, y, len;
    Vector() { x = 0, y = 0, len = 0; }
    Vector(double _x, double _y) { x = _x, y = _y, calc(); }
    void calc() { len = dis(x, y); }
    Vector& operator+=(const Vector& b) {
        x += b.x;
        y += b.y;
        calc();
        return *this;
    }
    Vector operator+(const Vector& b) const {
        Vector n(x + b.x, y + b.y);
        return n;
    }
    Vector operator-(const Vector& b) const {
        Vector n(x - b.x, y - b.y);
        return n;
    }
    Vector operator*(double k) const {
        Vector n(x * k, y * k);
        return n;
    }
} gb, a, b, c, d, uab, udc;

double gb_a, p, q, r, mx, my;

inline double dis(Vector a, Vector b) { return dis(a.x - b.x, a.y - b.y); }

double omega = 0.6, c1 = 1.4, c2 = 1.4;

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<> qwq(0, 1);

double rr() { return qwq(gen); }

struct Unit {
    Vector p, v, pb;
    double pb_a;
    double ans() { return p.x + p.y + dis(a + uab * p.x, d + udc * p.y) / r; }
    void upd_v() {
        v = v * omega + (pb - v) * c1 * rr() + (gb - v) * c2 * rr();
    }
    void upd() {
        upd_v();
        p += v;
        if (p.x < 0 || p.x > mx) p.x -= v.x * 2;
        if (p.y < 0 || p.y > my) p.y -= v.y * 2;

        if (p.x < 0) p.x = 0;
        if (p.y < 0) p.y = 0;
        if (p.x > mx) p.x = mx;
        if (p.y > my) p.y = my;
        double c = ans();
        // cout << c << endl;
        if (c <= pb_a) {
            pb = p, pb_a = c;
            if (c <= gb_a) gb = p, gb_a = c;
        }
    }
} u[cnt];

int main() {
    // #ifdef LOCAL
    //     freopen("input", "r", stdin);
    // #endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int t1, t2;
    cin >> t1 >> t2;
    a = Vector(t1, t2);
    cin >> t1 >> t2;
    b = Vector(t1, t2);
    cin >> t1 >> t2;
    c = Vector(t1, t2);
    cin >> t1 >> t2;
    d = Vector(t1, t2);
    uab = b - a;
    udc = c - d;
    cin >> p >> q >> r;
    mx = uab.len / p;
    my = udc.len / q;
    uab = (uab.len == 0 ? Vector(0, 0) : uab * (p / uab.len));
    udc = (udc.len == 0 ? Vector(0, 0) : udc * (q / udc.len));
    gb_a = inf;
    Rn(cnt) {
        u[i].p = u[i].pb = Vector(mx * rr(), my * rr());
        u[i].pb_a = u[i].ans();
        if (u[i].pb_a < gb_a) gb_a = u[i].pb_a, gb = u[i].p;
    }
    cerr.setf(std::ios::fixed);
    rep(ewq, 1, 5) {
        Rn(cnt) { u[i].upd(); }
    }
    cout.setf(std::ios::fixed);
    cout << std::setprecision(2) << gb_a << endl;
    return 0;
}