#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;

namespace Euler_Prime{
template <int n>
struct Euler_Prime{
    int c[n+10], p[n], cnt = 0;
    void init(){
        c[1] = 1;
        rep(i, 2, n){
            if (!c[i]) p[++cnt] = i;
            for(int j = 1; j <= cnt && p[j]*i <= n; ++j){
                c[p[j]*i] = 1;
                if (i%p[j] == 0) break;
            }
        }
    }
};
};

Euler_Prime::Euler_Prime<44723> e;

int a0, a1, b0, b1, ma0, ma1, mb0, mb1;

int work(int p){
    if (p == 1) return 1;
    ma0 = ma1 = mb0 = mb1 = 0;
    while(a0 % p == 0) ++ma0, a0 /= p;
    while(a1 % p == 0) ++ma1, a1 /= p;
    while(b0 % p == 0) ++mb0, b0 /= p;
    while(b1 % p == 0) ++mb1, b1 /= p;
    if (ma0 == ma1 && mb0 == mb1){
        int x = mb1 - ma1 + 1;
        if (x < 0){ return 0; }
        return x;
    } else if (
        (ma0 == ma1 && mb0 < mb1 && ma1 <= mb1) || 
        (ma0 > ma1 && mb0 == mb1 && ma1 <= mb0) ||
        (ma0 > ma1 && mb0 < mb1 && mb1 == ma1) ) return 1;
    else { return 0;}
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int n; cin >> n; e.init();
    rep(i, 1, n){
        cin >> a0 >> a1 >> b0 >> b1;
        ll cnt = 1;
        for (int i = 1; i <= e.cnt && cnt; ++i){
            cnt *= work(e.p[i]);
        }
        cnt *= work(a0)*work(a1)*work(b0)*work(b1);
        cout << cnt << endl;
        
    }
    cout << endl;
    return 0;
}
