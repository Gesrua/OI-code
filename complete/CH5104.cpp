#include <cstdio>
#include <iostream>
#include <utility>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#define rep(i, l, r) for (i = (l); i <= (r); ++i)
#define per(i, l, r) for (i = (l); i >= (r); --i)
using std::cin; using std::cout; using std::cerr; using std::endl;
using std::make_pair; using std::pair;
typedef pair< int, int > pii;
int sum[20][20];
int ask(int i, int l, int r){
    return sum[i][r] - sum[i][l-1];
}
int i, j, k, p, q, x, y, l, r, left, K;
struct ref{
    int i, l, r, x, y, k;
}a[16][16][16][226][2][2], ans;
int f[16][16][16][226][2][2] = {}, max = 0;
void change(ref &a, int i, int l, int r, int k, int x, int y){
    a.i = i;
    a.l = l;
    a.r = r;
    a.x = x;
    a.y = y;
    a.k = k;
}
void update(int aa, int b, int x, int y){
    if (f[i][l][r][k][aa][b] < f[i-1][p][q][left][x][y] && f[i-1][p][q][left][x][y] > 0){
        f[i][l][r][k][aa][b] = f[i-1][p][q][left][x][y];
        change(a[i][l][r][k][aa][b], i-1, p, q, left, x, y);
    }
}
void work(int x, int y){
    if (f[i][l][r][K][x][y] > max){
        max = f[i][l][r][K][x][y];
        ans.i = i, ans.l = l, ans.r = r, ans.k = K, ans.x = x, ans.y = y;
    }
}
void print(ref &ans){
    if (ans.i == 0 || ans.k == 0) return;
    rep (i, ans.l, ans.r){
        cout << ans.i << ' ' << i << endl;
    }
    print(a[ans.i][ans.l][ans.r][ans.k][ans.x][ans.y]);
}
int main(){
    // std::freopen("input", "r", stdin);
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, m, a[20][20] = {};
    cin >> n >> m >> K;
    rep (i, 1, n){
        rep (j, 1, m){
            cin >> a[i][j];
            sum[i][j] = sum[i][j-1] + a[i][j];
        }
    }
    // int f[16][15][15][260][2][2] = {};
    // int max = 0
    rep (i, 1, n){
        rep (l, 1, m){
            rep (r, l, m){
                rep (k, r-l+1, K){
                    // 1 收缩
                    // 0 扩张
                    left = k-r+l-1;
                    auto cur = f[i][l][r][k];
                    // 0, 0
                    rep (p, l, r){
                        rep (q, p, r){
                            if (q-p+1 > left) break;
                            // cur[0][0] = std::max(cur[0][0], f[i-1][p][q][left][0][0]);
                            update(0, 0, 0, 0);
                        }
                    }
                    cur[0][0] += ask(i, l, r);
                    // max = std::max(max, cur[0][0]);

                    // 1, 1
                    rep (p, 1, l){
                        rep (q, r, m){
                            if (q-p+1 > left) break;
                            // cur[1][1] = std::max(cur[1][1], f[i-1][p][q][left][0][0]);
                            update(1, 1, 0, 0);
                            // cur[1][1] = std::max(cur[1][1], f[i-1][p][q][left][0][1]);
                            update(1, 1, 0, 1);
                            // cur[1][1] = std::max(cur[1][1], f[i-1][p][q][left][1][0]);
                            update(1, 1, 1, 0);
                            // cur[1][1] = std::max(cur[1][1], f[i-1][p][q][left][1][1]);
                            update(1, 1, 1, 1);
                        }
                    }
                    cur[1][1] += ask(i, l, r);
                    // max = std::max(max, cur[1][1]);

                    // 1, 0
                    rep (p, 1, l){
                        rep (q, l, r){
                            if (q-p+1 > left) break;
                            // cur[1][0] = std::max(cur[1][0], f[i-1][p][q][left][0][0]);
                            update(1, 0, 0, 0);
                            // cur[1][0] = std::max(cur[1][0], f[i-1][p][q][left][1][0]);
                            update(1, 0, 1, 0);
                        }
                    }
                    cur[1][0] += ask(i, l, r);
                    // max = std::max(max, cur[1][0]);

                    // 0, 1
                    rep (p, l, r){
                        rep (q, r, m){
                            // if (i == 3 && l == 1 && r == 2 && k == 4){
                            //     cout << p << ' ' << q << endl;
                            // }
                            if (q-p+1 > left) break;
                            // cur[0][1] = std::max(cur[0][1], f[i-1][p][q][left][0][1]);
                            update(0, 1, 0, 1);
                            // cur[0][1] = std::max(cur[0][1], f[i-1][p][q][left][0][0]);       
                            update(0, 1, 0, 0);                     
                        }
                    }
                    cur[0][1] += ask(i, l, r);
                    // max = std::max(max, cur[0][1]);
                }
                work(0, 0);
                work(0, 1);
                work(1, 0);
                work(1, 1);
                // max = std::max(max, f[i][l][r][K][0][0]);
                // max = std::max(max, f[i][l][r][K][0][1]);
                // max = std::max(max, f[i][l][r][K][1][0]);
                // max = std::max(max, f[i][l][r][K][1][1]);
            }
        }
    }
    // rep (i, 1, n){
    //     rep (l, 1, m){
    //         rep (r, l, m){
    //             rep (x, 0, 1){
    //                 rep (y, 0, 1){
    //                     max = std::max(max, f[i][l][r][K][x][y]);
    //                 }
    //             }
    //         }
    //     }
    // }

    cout << "Oil : " << max << endl;
    print(ans);
    return 0;
}