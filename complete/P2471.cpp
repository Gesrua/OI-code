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

const int FIX = 1000000001;
const int N = 5000000;
const int INF = 1000000001;

struct SegmentTree {
    struct node {
        int max, min;
        node *ls, *rs;
        // node(const )
    } pool[N], *rt;
    int L, R, X, V, MAX, MIN;
    int cnt = 0;
    node* nn() { return &pool[cnt++]; }
    inline void pushup(node* cur) {
        assert(cur != nullptr);
        // assert(cur->ls != nullptr);
        // assert(cur->rs != nullptr);
        cur->max = std::max(cur->ls != nullptr ? cur->ls->max : 0, cur->rs != nullptr ? cur->rs->max : 0);
        cur->min = std::min(cur->ls != nullptr ? cur->ls->min : 0, cur->rs != nullptr ? cur->rs->min : 0);
    }
    node* _insert(node* cur, int l, int r) {
        if (X < l || r < X) return cur;
        if (cur == nullptr) {
            // cerr << l << ' ' << r << endl;
            cur = nn();
        }
        if (l == r) {
            cur->max = cur->min = V;
            return cur;
        }
        // int mid = (l + r) / 2;
        int mid = l + (r - l) / 2;
        cur->ls = _insert(cur->ls, l, mid);
        cur->rs = _insert(cur->rs, mid + 1, r);
        pushup(cur);
        return cur;
    }
    int _qmin(node* cur, int l, int r) {
        if (R < l || r < L) return INF;
        if (cur == nullptr) return 0;
        if (L <= l && r <= R) return cur->min;
        // int mid = (l + r) / 2;
        int mid = l + (r - l) / 2;
        return std::min(_qmin(cur->ls, l, mid), _qmin(cur->rs, mid + 1, r));
    }
    int _qmax(node* cur, int l, int r) {
        if (cur == nullptr || R < l || r < L) return 0;
        if (L <= l && r <= R) return cur->max;
        // int mid = (l + r) / 2;
        int mid = l + (r - l) / 2;
        return std::max(_qmax(cur->ls, l, mid), _qmax(cur->rs, mid + 1, r));
    }
    void init(int l, int r) {
        cnt = 0;
        rt = nn();
        MIN = l;
        MAX = r;
        // cerr << MIN << ' ' << MAX << endl;
    }
    void insert(int pos, int val) {
        X = pos;
        V = val;
        _insert(rt, MIN, MAX);
    }
    int qmin(int l, int r) {
        L = l, R = r;
        return _qmin(rt, MIN, MAX);
    }
    int qmax(int l, int r) {
        L = l, R = r;
        return _qmax(rt, MIN, MAX);
    }
    int get(int pos) { return qmin(pos, pos); }
} T;

void init() {
    T.init(-1000000000 + FIX, 1000000000 + FIX);
    int n;
    int y, r;
    cin >> n;
    while (n--) {
        cin >> y >> r;
        y += FIX;
        T.insert(y, r);
    }
}

void solve() {
    int from, to;
    cin >> from >> to;
    from += FIX;
    to += FIX;
    if (from + 1 == to) {
        from = T.get(from), to = T.get(to);
        if (from == 0 || to == 0)
            cout << "maybe\n";
        else if (from < to)
            cout << "false\n";
        else
            cout << "true\n";

        return;
    }
    int f = T.get(from), l = T.get(to), pm = T.qmax(from + 1, to - 1);
    if (f == 0 && l == 0) {
        cout << "maybe\n";
        return;
    }
    if (f == 0) {
        if (pm >= l)
            cout << "false\n";
        else
            cout << "maybe\n";
        return;
    }
    if (l == 0) {
        if (pm >= f)
            cout << "false\n";
        else
            cout << "maybe\n";
        return;
    }
    if (f < l || pm >= l)
        cout << "false\n";
    else if (T.qmin(from + 1, to - 1) == 0)
        cout << "maybe\n";
    else
        cout << "true\n";
}

int main() {
    // freopen("input", "r", stdin);
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    init();
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
    // cerr << T.cnt;
    return 0;
}
