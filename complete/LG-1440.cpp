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
const int N = 2000000;
std::deque<pii> q;
int a[N + 10];
char s[50000001];
int stl = 0;
inline void rd(int &x) {
    x = 0;
    for (; !isdigit(s[stl]); ++stl)
        ;
    for (; isdigit(s[stl]); ++stl) x = (x << 3) + (x << 1) + s[stl] - '0';
}
inline void put(int x) {
    if (x >= 10) put(x / 10);
    s[stl++] = x % 10 + '0';
}
int main() {
    std::ios::sync_with_stdio(false);
    fread(s, 50000000, 1, stdin);
    int n, m;
    rd(n);
    rd(m);
    rep(i, 1, n) rd(a[i]);
    stl = 0;
    put(0);
    s[stl++] = '\n';
    q.push_back(make_pair(1, a[1]));
    rep(i, 2, n) {
        put(q.front().second);
        s[stl++] = '\n';
        while (!q.empty() && q.front().first <= i - m) q.pop_front();
        while (!q.empty() && q.back().second >= a[i]) q.pop_back();
        q.push_back(make_pair(i, a[i]));
    }
    s[stl++] = '\0';
    fwrite(s, stl, 1, stdout);
    return 0;
}
