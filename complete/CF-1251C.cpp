#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;

char s1[300010], s2[300010], s[300010], res[300010];

void solve(){
    int pt1 = 0, pt2 = 0;
    cin >> s;
    int n = strlen(s);
    for(int i = 0; i < n; ++i)
        if ((s[i]-'0')&1) s2[pt2++] = s[i];
        else s1[pt1++] = s[i];
    std::merge(s1, s1+pt1, s2, s2+pt2, s);
    cout << s << endl;
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
