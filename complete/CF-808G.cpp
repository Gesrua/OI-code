#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl; using std::make_pair; using std::pair;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull; typedef pair<int, int> pii;

const int N = 1e5+10;

int tr[N][26], fail[N];

char s[N], t[N];

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> (s+1) >> (t+1);
    int n = strlen(s+1), m = strlen(t+1);
    rep(i, 1, m){
        tr[i-1][t[i]-'a'] = i;
        rep(c, 0, 25){
            if (t[i+1]-'a' == c){
                fail[i] = tr[fail[i-1]][c];
            } else {
                tr[i][c] = tr[fail[i-1]][c];
            }
        }
    }
    std::vector< std::vector<int> > f(n+1, std::vector<int>(m+1, -1));
    f[0][0] = 0;
    rep(i, 0, n-1){
        rep(j, 0, m){
            if (f[i][j] == -1) continue;
            for(int c = (s[i+1] == '?' ? 0 : s[i+1]-'a'); c <= (s[i+1] == '?' ? 25 : s[i+1]-'a'); ++c){
                f[i+1][tr[j][c]] = std::max(f[i+1][tr[j][c]], f[i][j] + (tr[j][c] == m));
            }
        }
    }
    int ans = 0;
    rep(i, 0, m) ans = std::max(ans, f[n][i]);
    cout << ans << endl;
    return 0;
}