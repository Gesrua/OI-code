#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;
const int N =  600010;
const int T = 15000250;
int ch[T][2], latest[T], tot = 0, root[N], TIME, x, l;
void add(int i, int c, int n){
    int b = (x>>i)&1;
    ch[n][b^1] = ch[c][b^1];
    ch[n][b] = ++tot;
    latest[ch[n][b]] = TIME;
    if (i > 0) add(i-1, ch[c][b], ch[n][b]);
}
int query(int i, int c){
    if (i<0) return 0;
    int b = ((x>>i)&1)^1;
    if (latest[ch[c][b]] < l) b ^= 1;
    return (b<<i)|query(i-1, ch[c][b]);
}
void print(int c, int i, int x){
    // if (!c) return;
    // cerr << c << ' ';
    if (!c) return;
    if (i < 0 && c > 0) cerr << x << ' ';
    print(ch[c][0], i-1, x);
    print(ch[c][1], i-1, (1<<(i))|x);
}
int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int s = 0, n, m; cin >> n >> m;
    add(23, 0, root[0]=++tot);
    rep(i, 1, n){
        cin >> x; TIME = i; s ^= x;
        x = s, add(23, root[i-1], root[i]=++tot);
    }
    latest[0] = -100;
    while(m--){
        char opt;
        cin >> opt;
        if (opt == 'A'){
            ++TIME; cin >> x; s ^= x;
            x = s, add(23, root[TIME-1], root[TIME]=++tot);
        } else {
            int r;
            cin >> l >> r >> x;
            x ^= s, l--;
            cout << (query(23, root[r-1])^x) << endl;
        }
    }
    return 0;
}