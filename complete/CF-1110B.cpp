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
const int INF = 1000000001;
int pos[N], dis[N];
int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    cin >> pos[1];
    rep(i, 2, n) {
        cin >> pos[i];
        dis[i - 1] = pos[i] - pos[i - 1] - 1;
    }
    std::sort(dis + 1, dis + n);
    int ans = n;
    rep(i, 1, n - k) ans += dis[i];
    cout << ans;
    return 0;
}
