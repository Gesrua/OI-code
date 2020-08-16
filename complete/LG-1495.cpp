#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl; using std::make_pair; using std::pair;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull; typedef pair<int, int> pii; 

void exgcd(ll a, ll b, ll& x, ll& y){
    if (b == 0){
        x = 1, y = 0;
        return;
    }
    exgcd(b, a%b, x, y);
    ll z = x;
    x = y;
    y = z - y * (a/b);
}

ll inv(ll a, ll p){
    ll x, y;
    exgcd(a, p, x, y);
    return x;
}

const int N = 100;

ll n, a[N], m[N];

ll CRT(){
    ll M = 1;
    rep(i, 1, n) M *= m[i];
    ll res = 0;
    rep(i, 1, n){
        ll r = M/m[i];
        res = (res + r * inv(r, m[i]) * a[i]) % M;
    }
    res = (res+M)%M;
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> m[i] >> a[i];
    cout << CRT();
    return 0;
}