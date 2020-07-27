#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl; using std::make_pair; using std::pair;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull; typedef pair<int, int> pii; 

#define x first
#define y second

const int rqy = 998244353;

int inv(ll a){
    ll ret = 1; int n = rqy-2;
    while(n){
        if (n&1) ret = ret*a%rqy;
        a = a*a%rqy;
        n >>= 1;
    }
    return ret;
}

int lagrange(std::vector<pii>& p, int k){
    ll ret = 0;
    for(auto i : p){
        ll s1 = i.y, s2 = 1;
        for(auto j : p) if (i != j){
            s1 = s1 * (k-j.x) % rqy;
            s2 = s2 * (i.x-j.x) % rqy;
        }
        ret += s1*inv(s2) % rqy;
        ret %= rqy;
    }
    return (ret+rqy)%rqy;
}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    std::vector<pii> p(n);
    for(int i = 0; i < n; ++i){
        cin >> p[i].x >> p[i].y;
    }
    cout << lagrange(p, k);
    return 0;
}