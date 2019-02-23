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
const int N = 1005;
char opt[N][N];
int f[2 * N];
int find(int x) {
    if (x == f[x])
        return x;
    else
        return f[x] = find(f[x]);
}
void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) f[x] = y;
}
std::vector<int> g[N * 2];
int in[N * 2];
int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    rep(i, 1, n + m) f[i] = i;
    rep(i, 1, n) {
        rep(j, 1, m) {
            cin >> opt[i][j];
            if (opt[i][j] == '=') {
                merge(i, n + j);
            }
        }
    }
    rep(i, 1, n + m) find(i);
    rep(i, 1, n) rep(j, 1, m) {
        if (opt[i][j] == '<') {
            g[f[i]].push_back(f[n + j]);
            in[f[n + j]]++;
        } else if (opt[i][j] == '>') {
            g[f[n + j]].push_back(f[i]);
            in[f[i]]++;
        }
    }

    std::queue<int> q;
    int cnt = 0, val[N * 2];
    rep(i, 1, n + m) {
        if (f[i] != i)
            ++cnt;
        else if (in[i] == 0)
            q.push(i), val[i] = 1;
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cnt++;
        for (auto v : g[u]) {
            in[v]--;
            if (in[v] == 0) {
                val[v] = val[u] + 1;
                q.push(v);
            }
        }
    }
    if (cnt == n + m) {
        cout << "Yes" << endl;
        rep(i, 1, n) cout << val[f[i]] << ' ';
        cout << endl;
        rep(i, n + 1, n + m) cout << val[f[i]] << ' ';
    } else
        cout << "No" << endl;
    return 0;
}
