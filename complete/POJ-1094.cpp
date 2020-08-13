#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;
int g[30][30];
pii edge[500];
pii p[30];

// -1 -> conflict
// 0 -> not determined
// 1 -> determined
int judge(int n, int k){
    std::memset(g, 0, sizeof(g));
    rep(i, 1, k) g[edge[i].first][edge[i].second] = 1;
    rep(k, 1, n) rep(i, 1, n) rep(j, 1, n) g[i][j] |= (g[i][k] & g[k][j]);
    rep(i, 1, n) if (g[i][i]) return -1;
    rep(i, 1, n) rep(j, i + 1, n) if ((g[i][j] | g[j][i]) == 0) return 0;
    return 1;
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int n, m;
    while(cin >> n >> m && n){
        rep(i, 1, m){
            char u, opt, v;
            cin >> u >> opt >> v;
            edge[i] = {u-'A'+1, v-'A'+1};
        }

        int l = 1, r = m, x, mid;
        while(l < r){
            x = judge(n, mid = (l+r)/2);
            if (x == -1) r = mid - 1;
            if (x == 1) r = mid;
            if (x == 0) l = mid + 1;
        }
        x = judge(n, l);
        if (x == 1){
            cout << "Sorted sequence determined after " << l << " relations: ";
            rep(i, 1, n){
                int cnt = 0;
                rep(j, 1, n) cnt += g[i][j];
                p[i] = {cnt, i};
            }
            std::sort(p+1, p+1+n, std::greater<pii>());
            rep(i, 1, n) cout << char(p[i].second + 'A' - 1);
            cout << ".\n";
        } else if (judge(n, m) == 0){
            cout << "Sorted sequence cannot be determined.\n";
        } else {
            l = 1, r = m;
            while(l < r){
                if (judge(n, mid = (l+r)/2) == -1) r = mid;
                else l = mid + 1;
            }
            cout << "Inconsistency found after " << l << " relations.\n";
        }
    }
    return 0;
}
