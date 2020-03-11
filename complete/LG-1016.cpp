#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;

struct S{
    double d, p;
} a[10];

bool cmp(const S&a, const S&b){return a.d < b.d;}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    double d1, c, d2, p; int n;
    cin >> d1 >> c >> d2 >> p >> n;
    rep(i, 1, n){ cin >> a[i].d >> a[i].p; }
    a[n+1].d = d1, a[n+1].p = 0; ++n;
    a[n+1].d = 0, a[n+1].p = p; ++n;
    std::sort(a+1, a+1+n, cmp);
    double cur_c = 0, cost = 0;
    double max_d = d2 * c;
    int i = 1;
    cerr << max_d << endl;
    while(i < n){
        cerr << i << ' ' << a[i].d << ' ' << cost << endl;
        int j = i + 1;
        if (a[j].d - a[i].d > max_d){
            cout << "No Solution"; return 0;
        }
        int minj = j; bool flag = 0;
        for(; j <= n && a[j].d - a[i].d <= max_d; ++j){
            if (a[j].p < a[i].p) {flag = 1; break;}
            if (a[j].p < a[minj].p) minj = j;
        }
        if (flag){
            double use = (a[j].d - a[i].d)/d2;
            if (use >= cur_c){
                cost += (use - cur_c) * a[i].p;
                cur_c = 0;
            } else cur_c -= use;
            i = j;
        } else {
            j = minj;
            cost += (c-cur_c) * a[i].p;
            cur_c = c - (a[j].d - a[i].d)/d2;
            i = j;
        }
    }
    cout.setf(std::ios::fixed);
    cout << std::setprecision(2) << cost;
    return 0;
}
