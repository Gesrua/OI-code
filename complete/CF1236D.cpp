#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl;
using std::make_pair; using std::pair; typedef pair<int, int> pii;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull;
const int N = 1e5 + 10;
std::set<int> hang[N], lie[N];
int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(0); cout.tie(0);
    int xmin = 0, xmax, ymin = 0, ymax, n, m, k, x = 1, y = 1, dir = 0;
    // 0 right
    // 1 down
    // 2 left
    // 3 up
    cin >> n >> m >> k; xmax = n+1, ymax = m+1; ll cnt = 0;
    rep(i, 1, k){
        int u, v; cin >> u >> v;
        hang[u].insert(v), lie[v].insert(u);
    }
    if (hang[1].find(2) != hang[1].end()) dir = 1, ymax = 2;
    while(hang[x].find(y) == hang[x].end() && xmin < x && x < xmax && ymin < y && y < ymax){
        // cerr << x << ' ' << y << ' ' << cnt << endl;
        if (dir == 0){
            int turn = ymax;
            auto it = hang[x].upper_bound(y);
            if (it != hang[x].end()) turn = std::min(turn, *it);
            cnt += abs(y - turn);
            xmin = x, ymax = turn;
            x++, y = turn-1, dir = 1;
        } else if (dir == 1){
            int turn = xmax;
            auto it = lie[y].upper_bound(x);
            if (it != lie[y].end()) turn = std::min(turn, *it);
            cnt += abs(turn - x);
            xmax = turn, ymax = y;
            x = turn-1, y--, dir = 2;
        } else if (dir == 2){
            int turn = ymin;
            auto it = hang[x].upper_bound(y);
            if (hang[x].size() != 0 && it != hang[x].begin())
                turn = std::max(turn, *--it);
            cnt += abs(y - turn);
            xmax = x, ymin = turn;
            x--, y = turn+1, dir = 3;
        } else if (dir == 3){
            int turn = xmin;
            auto it = lie[y].upper_bound(x);
            if (lie[y].size() != 0 && it != lie[y].begin())
                turn = std::max(turn, *--it);
            cnt += abs(x - turn);
            xmin = turn, ymin = y;
            x = turn+1, y++, dir = 0;
        }
        // cerr << x << ' ' << y << ' ' << cnt << endl;
    }
    cout << ((cnt == (ll)n*m-k)?"Yes":"No");
    return 0;
}
