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
int main() {
    std::ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    std::string s;
    cin >> s;
    int t = n + 1, len = n;
    for (int i = 1; i < len; ++i) {
        bool flag = true;
        for (int j = 0, k = len - i; j < i; ++j, ++k) {
            // cerr << j << ' ' << k << endl;
            if (s[j] != s[k]) {
                flag = false;
                break;
            }
        }
        // cerr << "----\n";
        if (flag) t = i;
    }
    // cerr << t << endl;
    if (t == n + 1) {
        rep(i, 1, k) cout << s;
        return 0;
    }
    std::string s_out = s.substr(t, n - t);
    // cerr << s_out;
    cout << s;
    --t;
    rep(i, 2, k) { cout << s_out; }
    // cerr << t << endl;
    return 0;
}
