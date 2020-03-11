#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
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
typedef unsigned long long ull;

ll gcd(ll x, ll y){
    return x&&y?gcd(y, x%y):std::max(std::abs(x),std::abs(y));
}
const int N = 500000;
ll d[N+10], a[N+10];
int lowbit(int x){ return x&(-x); }
struct SpecialBIT{
    ll c[N+10];
    void _e(int i, ll x){ for(; i <= N; i+=lowbit(i)) c[i] += x; }
    ll ask(int i){ ll ret = 0; for(; i > 0; i-=lowbit(i)) ret += c[i]; return ret; }
    void edit(int l, int r, ll x){ _e(l, x), _e(r+1, -x); }
} seg;
#define ls (c<<1)
#define rs ((c<<1)|1)
#define s T[c]
struct Node{ int l, r; ll g; } T[N*4];
void build(int c, int l, int r){
    s.l = l, s.r = r;
    if (l == r){ s.g = d[l]; return; }
    int mid = (l+r)>>1;
    build(ls, l, mid), build(rs, mid+1, r);
    T[c].g = gcd(T[ls].g, T[rs].g);
}
int L, R;
ll query(int c){
    if (s.r < L || R < s.l || L > R) return 0;
    if (L <= s.l && s.r <= R) return s.g;
    return gcd(query(ls), query(rs));
}
void edit(int P, ll X){
    int c = 1;
    if (P > s.r) return;
    for (; s.l != s.r; c = (P <= ((s.l+s.r) >> 1))?ls:rs) ;
    s.g += X; c >>= 1;
    for (; c != 1; c >>= 1) s.g = gcd(T[ls].g, T[rs].g);
}
void print(int c){
    if (s.l == s.r){
        cout << s.g << ' ';
        return ;
    }
    print(ls), print(rs);
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    rep(i, 1, n){
        cin >> a[i]; seg.edit(i,i,a[i]); d[i] = a[i] - a[i-1];
    }
    build(1, 1, n);
    while(m--){
        char opt;
        cin >> opt;
        if (opt == 'C'){
            int l, r; ll d;
            cin >> l >> r >> d;
            seg.edit(l, r, d);
            edit(l, d), edit(r+1, -d);
            // print(1); cout << endl;
        } else {
            cin >> L >> R; L++;
            cout << gcd(seg.ask(L-1), query(1)) << '\n';
        }
    }
    return 0;
}