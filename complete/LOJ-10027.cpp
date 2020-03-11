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

int md = 0, gh;
std::vector<char> seq;
std::set<int> exc;

struct Node {
    int a[9], d;
    std::vector<char> seq;

    void swap() {
        std::swap(a[1], a[8]), std::swap(a[2], a[7]), std::swap(a[3], a[6]),
            std::swap(a[4], a[5]);
    }
    void insert() {
        int x = a[4], y = a[5];
        a[4] = a[3], a[3] = a[2], a[2] = a[1], a[1] = x;
        a[5] = a[6], a[6] = a[7], a[7] = a[8], a[8] = y;
    }
    void rotate() {
        int x = a[2];
        a[2] = a[7], a[7] = a[6], a[6] = a[3], a[3] = x;
    }
    int hash() {
        int ret = 0;
        rep(i, 1, 8) { ret = ret * 8 + a[i] - 1; }
        return ret;
    }
    void print() {
        rep(i, 1, 4) cout << a[i] << ' ';
        cout << endl;
        per(i, 8, 5) cout << a[i] << ' ';
        cout << endl;
    }
} goal, s;

std::queue<Node> q;

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    rep(i, 1, 8) cin >> goal.a[i], s.a[i] = i;
    gh = goal.hash();
    q.push(s);
    Node tmp;

    while (1) {
        s = q.front();
        // cerr << s.hash() << ' ';
        q.pop();
        int h = s.hash();
        if (h == gh) {
            cout << s.d << endl;
            for (auto c : s.seq) cout << c;
            exit(0);
        }

        tmp = s, tmp.seq.push_back('A'), tmp.swap(), tmp.d++;
        if (exc.count(tmp.hash()) == 0) q.push(tmp), exc.insert(tmp.hash());

        tmp = s, tmp.seq.push_back('B'), tmp.insert(), tmp.d++;
        if (exc.count(tmp.hash()) == 0) q.push(tmp), exc.insert(tmp.hash());

        tmp = s, tmp.seq.push_back('C'), tmp.rotate(), tmp.d++;
        if (exc.count(tmp.hash()) == 0) q.push(tmp), exc.insert(tmp.hash());
    }
    return 0;
}