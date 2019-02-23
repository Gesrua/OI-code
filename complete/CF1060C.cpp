#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define rep(i, l, r) for (register int i = (l); i <= (r); ++i)
#define per(i, l, r) for (register int i = (l); i >= (r); --i)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
typedef pair<int, int> pii;
int n, m;
int a[2009] = {}, b[2009] = {};
int pa[2009] = {}, pb[2009] = {};
struct node {
    int sum, len;
    bool operator<(const node& b) {
        return (sum == b.sum) ? (len > b.len) : (sum < b.sum);
    }
    bool operator==(const node& b) { return sum == b.sum; }
    node() {}
    node(int _sum) { sum = _sum; }
} s[4000009];
int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n >> m;
    // cin >> n;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, m) cin >> b[i];
    s[0].len = s[0].sum = 0;
    node* end;
    {
        register int x;
        register node* p = s + 1;
        rep(i, 1, n) {
            x = 0;
            rep(j, i, n) {
                x += a[j];
                p->sum = x;
                p->len = j - i + 1;
                ++p;
            }
        }
        end = p;
    }
    // cout << "-----\n";
    std::sort(s, end);
    // end = std::unique(s, end);
    {
        int len = -1;
        node* p1 = s;
        for (node* i = s; i != end; ++i) {
            if (i->len > len) {
                len = i->len;
                *p1 = *i;
                ++p1;
            }
        }
        end = p1;
    }
    // for(node* i = s; i != end; ++i)
    // cout << i->sum << ' ' << i->len << endl;
    // cout << "----\n";
    int x, ans = 0;
    cin >> x;
    int st = 0, en = end - s - 1;
    // cout << "---" << x << endl;
    // cout << st << ' ' << en << endl;
    rep(i, 1, m) {
        int sum = 0;
        rep(j, i, m) {
            sum += b[j];
            // cout << i << ' ' << j << ' ' << sum << ' ' << std::lower_bound(s,
            // end, node(x/sum))->sum << ' ' << std::lower_bound(s, end,
            // node(x/sum))->len << endl;
            int mid, l = st, r = en, target = x / sum;
            // cerr << target << endl;
            while (l < r) {
                mid = (l + r) / 2 + 1;
                // cerr << l << ' ' << r << ' ' << mid << endl;
                if (s[mid].sum <= target)
                    l = mid;
                else
                    r = mid - 1;
            }
            // cerr << "ans = " <<  mid << endl;
            int size = s[l].len * (j - i + 1);
            // cout << i << ' ' << j << ' ' << sum << ' ' << x/sum << ' ' <<
            // s[mid].sum << ' ' << s[mid].len << ' ' << size << endl;
            if (size > ans) ans = size;
        }
    }
    cout << ans;
    return 0;
}
