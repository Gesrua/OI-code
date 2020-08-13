#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;
const int N = 16010, M = 109;
int f[N];
struct Worker{ int l, s, p; } a[M];
bool cmp_s(const Worker&a, const Worker& b){ return a.s < b.s; }
std::deque<pii> q;
int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    rep(i, 1, m) cin >> a[i].l >> a[i].p >> a[i].s;
    std::sort(a+1,a+1+m,cmp_s);
    rep(i, 1, m){
        q.clear();
        q.push_back({0, 0});
        rep(j, 1, n){
            if (j < a[i].s){
                int x = f[j]-j*a[i].p;
                while(q.size() && q.back().second <= x) q.pop_back();
                q.push_back({j, x});
            }
            while(q.size() && q.front().first<j-a[i].l) q.pop_front();
            f[j] = std::max(f[j], f[j-1]);
            if (q.size() && q.front().first < a[i].s && a[i].s <= j) 
                f[j] = std::max(f[j], q.front().second + j * a[i].p);
        }
    }
    cout << f[n];
    return 0;
}