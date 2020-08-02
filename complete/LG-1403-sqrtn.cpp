#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl; using std::make_pair; using std::pair;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull; typedef pair<int, int> pii; 
int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n; ll ans = 0;
    cin >> n;
    for(int l = 1, r, k; l <= n; l = r+1){
        k = n / l;
        r = n / k;
        ans += 1ll * (r - l + 1) * k;
    }
    cout << ans << endl;
    return 0;
}