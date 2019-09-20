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
typedef unsigned long long ull;

struct Process {
    int start, id, arrival, exec, pri, end;
    bool operator<(const Process& b) const { return pri != b.pri ? pri < b.pri : arrival > b.arrival; }
} cur, n, tmp;

std::priority_queue<Process> q;

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int t = 0;
    cur.exec = cur.end = 1e8 + 10;

    while (cin >> n.id >> n.arrival >> n.exec >> n.pri) {
        while (cur.end < n.arrival) {
            // stop
            cout << cur.id << ' ' << cur.end + 1 << endl;
            // add
            t = cur.end + 1;
            cur = q.top();
            q.pop();
            cur.start = std::max(t, cur.arrival);
            cur.end = cur.start + cur.exec - 1;
        }
        if (cur.pri < n.pri) {
            tmp = cur;
            cur.exec -= n.arrival - 1 - cur.start + 1;
            q.push(cur);
            cur = n;
            cur.start = n.arrival;
            cur.end = cur.start + cur.exec - 1;
        } else {
            q.push(n);
        }
    }

    while (q.size()) {
        // stop
        cout << cur.id << ' ' << cur.end + 1 << endl;
        // add
        t = cur.end + 1;
        cur = q.top();
        q.pop();
        cur.start = std::max(t, cur.arrival);
        cur.end = cur.start + cur.exec - 1;
    }
    return 0;
}