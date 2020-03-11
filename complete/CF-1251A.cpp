#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;
char s[600];
int det[27];
void solve(){
    cin >> (s+1);
    int n = strlen(s+1);
    std::memset(det, 0, sizeof(det));
    for(int i = 1; i <= n; ++i){
        if (s[i] != s[i+1]) det[s[i] - 'a'] = 1;
        else ++i;
    }
    for(int i = 0; i < 26; ++i)
        if (det[i]) cout << char(i+'a');
    cout << endl;
}
int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        solve();
    }
    
    return 0;
}
