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
#define rep(i, l, r) for (register int i = (l); i <= (r); ++i)
#define per(i, l, r) for (register int i = (l); i >= (r); --i)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
typedef pair<int, int> pii;

const int pri[] = {2, 3, 5, 7, 11, 13, 17, 19};
const int N = 2000, M = 7;

int n, m, k, t, fac[N + 9][8], ans[N + 1][N + 1], sum[N + 1][N + 1], l[8];

void init() {
    rep(i, 2, n) {
        int t = i, cnt;
        // cerr << "fac = " << i << ' ';
        rep(j, 0, 7) {
            cnt = 0;
            while (t && t % pri[j] == 0) {
                t /= pri[j];
                ++cnt;
            }
            fac[i][j] = fac[i - 1][j] + cnt;
            // cerr << fac[i][j] << ' ';
        }
        // cerr << endl;
    }

    int t = k;
    rep(j, 0, 7) {
        while (t && t % pri[j] == 0) {
            t /= pri[j];
            ++l[j];
        }
    }

    rep(i, 0, n) {
        rep(j, 0, std::min(i, m)) {
            //   j
            // c
            //   i
            register int tmp, t = i - j;
            bool flag = 1;
            rep(k, 0, 7) {
                tmp = fac[i][k] - fac[j][k] - fac[t][k];
                if (tmp < l[k]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) ans[i][j] = 1;
        }
    }

    sum[0][0] = 0;
    rep(i, 1, n) sum[0][i] = sum[0][i - 1] + ans[0][i];
    rep(i, 1, n) {
        sum[i][0] = sum[i - 1][0] + ans[i][0];
        rep(j, 1, n) { sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + ans[i][j]; }
    }

    // rep(i, 0, 10){
    //     rep(j, 0, 10){
    //         cerr << ans[i][j] << ' ';
    //     }
    //     cerr << endl;
    // }
    // cerr << "-----" << endl;
    // rep(i, 0, 10){
    //     rep(j, 0, 10){
    //         cerr << sum[i][j] << ' ';
    //     }
    //     cerr << endl;
    // }
}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    n = N;
    m = N;
    cin >> t >> k;
    init();
    rep(i, 1, t) {
        cin >> n >> m;
        cout << sum[n][m] << '\n';
    }
    return 0;
}