#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
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

const int N = 10005;

double a[2][N];
int n, pos;
double pow[N];

double p, q;

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> p >> n >> pos;
    q = 1 - p;
    pow[0] = 1;
    rep(i, 1, n) pow[i] = pow[i - 1] * q;
    int u = 0, v = 1;
    if (n == 1) {
        cout << 1;
    } else if (p == 0) {
        cout << 0;
    } else {
        a[v][1] = q / (q + 1);
        a[v][2] = 1 - a[v][1];
        double prev = q * q * a[v][1] + q * a[v][2];
        rep(k, 3, n) {
            u ^= 1, v ^= 1;
            a[v][1] = p * prev / (1 - pow[k]);
            prev = pow[k] * a[v][1];
            rep(i, 2, k) {
                a[v][i] = p * a[u][i - 1] + q * a[v][i - 1];
                prev += pow[k - i + 1] * a[v][i];
            }
        }
        cout << std::setprecision(14) << a[v][pos];
    }
    return 0;
}