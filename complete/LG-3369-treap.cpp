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

const int N = 100100;

const int inf = 2000000005;

#define ls (son[c][0])
#define rs (son[c][1])

int siz[N], son[N][2], num[N], rd[N], v[N], cnt = 1;

void pushup(int c) { siz[c] = siz[ls] + siz[rs] + num[c]; }

// d = 0 左旋
// d = 1 右旋
void rotate(int& c, int d) {
    int n = son[c][d ^ 1];
    son[c][d ^ 1] = son[n][d];
    son[n][d] = c;
    pushup(c);
    pushup(n);
    c = n;
}

void ins(int& c, int x) {
    if (!c) {
        c = cnt++;
        v[c] = x, rd[c] = rand(), num[c] = siz[c] = 1;
        return;
    }
    if (v[c] == x) {
        num[c]++, siz[c]++;
        return;
    }
    int d = (x > v[c]);
    ins(son[c][d], x);
    if (rd[c] < rd[son[c][d]]) rotate(c, d ^ 1);
    pushup(c);
}

void del(int& c, int x) {
    if (!c) return;
    if (x < v[c])
        del(ls, x);
    else if (x > v[c])
        del(rs, x);
    else {
        if (!ls && !rs) {  // leaf
            num[c]--, siz[c]--;
            c = num[c] == 0 ? 0 : c;
        } else if (ls && rs) {
            int d = (v[rs] > v[ls]);  // 重儿子
            rotate(c, d ^ 1);
            del(son[c][d ^ 1], x);
        } else if (ls)
            rotate(c, 1), del(rs, x);
        else if (rs)
            rotate(c, 0), del(ls, x);
    }
    pushup(c);
}

int rank(int c, int x) {
    if (!c) return 0;
    if (v[c] == x) return siz[ls] + 1;
    if (x < v[c]) return rank(ls, x);
    if (v[c] < x) return siz[ls] + num[c] + rank(rs, x);
}

int find(int c, int k) {
    if (!c) return 0;
    if (k <= siz[ls]) return find(ls, k);
    if (siz[ls] + num[c] < k) return find(rs, k - siz[ls] - num[c]);
    return v[c];
}

int pre(int c, int x) {
    if (!c) return -inf;
    if (x <= v[c]) return pre(ls, x);
    return std::max(v[c], pre(rs, x));
}

int suc(int c, int x) {
    if (!c) return inf;
    if (v[c] <= x) return suc(rs, x);
    return std::min(v[c], suc(ls, x));
}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    srand((ui)time(nullptr));
    int n, rt = 0;
    cin >> n;
    while (n--) {
        int opt, x;
        cin >> opt >> x;
        switch (opt) {
            case 1:
                ins(rt, x);
                break;
            case 2:
                del(rt, x);
                break;
            case 3:
                cout << rank(rt, x) << '\n';
                break;
            case 4:
                cout << find(rt, x) << '\n';
                break;
            case 5:
                cout << pre(rt, x) << '\n';
                break;
            case 6:
                cout << suc(rt, x) << '\n';
                break;
        }
    }
    return 0;
}