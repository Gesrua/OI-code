#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;

const int n = 46341;

int p[n], c[n+10], cnt = 0;

void init(){
    c[1] = 1;
    rep(i, 2, n){
        if (!c[i]) p[++cnt] = i;
        for(int j = 1; j <= cnt && p[j]*i <= n; ++j){
            c[p[j]*i] = 1;
            if (i%p[j] == 0) continue;
        }
    }
}

int s[1000010];

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    init();
    int l, r;
    while(cin >> l >> r){
        std::memset(s,0,sizeof(s));
        if (l == 1) s[0] = 1;
        rep(i, 1, cnt){
            int k = std::max(2,l/p[i]);
            if (p[i] * k < l) ++k;
            for(int K = r/p[i]; k <= K; ++k){
                // cerr << k << ' ' << p[i] << endl;
                s[k*p[i]-l] = 1;
            }
        }
        int d = r - l, mind = 2e9, maxd = 0, lst = -1, cnt = 0;
        pii mins, maxs;
        rep(i, 0, d){
            if (s[i] == 0){
                ++cnt;
                if (lst != -1){
                    int dis = i - lst;
                    if (dis < mind){
                        mind = dis;
                        mins = {lst, i};
                    }
                    if (dis > maxd){
                        maxd = dis;
                        maxs = {lst , i};
                    }
                }
                lst = i;
            }
        }
        if (cnt <= 1) cout << "There are no adjacent primes.\n";
        else cout << mins.first+l << "," << mins.second+l << " are closest, " << maxs.first+l << "," << maxs.second+l << " are most distant.\n";
    }
    return 0;
}
