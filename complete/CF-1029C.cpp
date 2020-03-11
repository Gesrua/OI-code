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
using std::max;
using std::pair;
typedef pair<int, int> pii;
int main() {
    std::ios::sync_with_stdio(false);
    std::multiset<int> l, r;
    int lx[300000], rx[300000], n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> lx[i] >> rx[i];
        l.insert(lx[i]);
        r.insert(rx[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        l.erase(l.find(lx[i]));
        r.erase(r.find(rx[i]));
        ans = max(ans, *(r.begin()) - *(--l.end()));
        l.insert(lx[i]);
        r.insert(rx[i]);
    }
    cout << ans;
    return 0;
}
