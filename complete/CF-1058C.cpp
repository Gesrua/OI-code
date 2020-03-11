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
    int n, a[200] = {}, pre[200] = {};
    cin >> n;
    char c;
    rep(i, 1, n) {
        cin >> c;
        a[i] = c - '0';
        pre[i] = a[i] + pre[i - 1];
    }
    // rep (i, 1, n){
    //     cout << pre[i] << ' ';
    // }
    // cout << endl;
    rep(i, 1, n - 1) {
        int goal = pre[i];
        int j = i + 1, now = 0;
        bool flag = true;
        while (j <= n) {
            if (now > goal) {
                flag = false;
                break;
            }
            if (now == goal && a[j] != 0)
                now = a[j];
            else
                now += a[j];
            ++j;
        }
        if (now != goal) flag = false;
        if (flag) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
