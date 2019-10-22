#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;
const char c[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false); cout.tie(0);
    int n, r, _n;
    cin >> n >> r;
    _n = n;
    r = -r;
    std::vector<int> ans;
    while(n){
        int x = (n%r+r)%r;
        ans.push_back(x);
        n = (x - n)/r;
    }
    cout << _n << '=';
    for(int i = ans.size()-1; i>=0; --i){
        cout << c[ans[i]];
    }
    cout << "(base" << -r << ")";
    return 0;
}