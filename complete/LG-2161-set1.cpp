#include <algorithm>
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
std::set<int> s;
int end[100100];
int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        char opt;
        int st, ed, t;
        cin >> opt;
        if (opt == 'A') {
            cin >> st >> ed;
            auto cur = s.lower_bound(st);
            int ret = 0;
            if (cur != s.begin()) {
                cur--;
                t = *cur;
                cur++;
                if (end[t] >= st) s.erase(t), end[t] = 0, ret++;
            }
            while (cur != s.end() && *cur <= ed) {
                t = *cur;
                cur++;
                s.erase(t);
                ret++;
            }
            s.insert(st);
            end[st] = ed;
            cout << ret << endl;
        } else {
            cout << s.size() << endl;
        }
    }
    return 0;
}