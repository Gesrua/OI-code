#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int T;
    cin >> T;
    std::bitset<25> a;
    while (T--) {
        int n;
        cin >> n;
        int ans = 0;
        rep(i, 1, n) {
            a = 0;
            int m;
            cin >> m;
            rep(i, 1, m) {
                int x;
                cin >> x;
                a[x] = 1;
            }
            int cnt = 0, tot = 0, ans1 = 0;
            per(i, 20, 0) {
                if (a[i] == 0) {
                    if (cnt & 1) ans1 ^= tot;
                    cnt++, tot = 0;
                } else
                    tot++;
            }
            ans ^= ans1;
        }
        cout << (ans ? "YES" : "NO") << endl;
    }
    return 0;
}