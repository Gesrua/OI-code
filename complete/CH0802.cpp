#include <algorithm>
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
#define rep(i, l, r) for (register int i = (l); i <= (r); ++i)
#define per(i, l, r) for (register int i = (l); i >= (r); --i)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
typedef pair<int, int> pii;
std::deque<int> a[14];
int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    rep(i, 1, 13) {
        char c;
        rep(j, 1, 4) {
            cin >> c;
            if (c == '0')
                a[i].push_front(10);
            else if (c == 'J')
                a[i].push_front(11);
            else if (c == 'Q')
                a[i].push_front(12);
            else if (c == 'K')
                a[i].push_front(13);
            else if (c == 'A')
                a[i].push_front(1);
            else
                a[i].push_front(c - '0');
        }
    }
    int cnt[14] = {};
    while (!a[13].empty()) {
        int cur = *--a[13].end();
        a[13].pop_back();
        // cerr << cur << endl;
        while (cur != 13) {
            // cerr << cur << endl;
            cnt[cur]++;
            a[cur].push_back(cur);
            int tmp = cur;
            cur = a[cur].front();
            a[tmp].pop_front();
        }
        // rep (i, 1, 13){
        //     for (auto i: a[i]){
        //         cerr << i << ' ';
        //     }
        //     cerr << endl;
        // }
        // cerr << " ---- \n";
    }
    int ans = 0;
    rep(i, 1, 12) {
        if (cnt[i] == 4) ++ans;
    }
    cout << ans;
    return 0;
}