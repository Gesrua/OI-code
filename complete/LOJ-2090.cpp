#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl; using std::make_pair; using std::pair;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull; typedef pair<int, int> pii; 

const int N = 2e4+10, M = 150, Q = 1e5+10;

std::vector< std::vector<int> > r, c;
int n, m;

ll ans[Q];

struct Node{
    int id, x1, y1, x2, y2;
} ask[Q], ask1[Q], ask2[Q];

ll dis[M][N]; const ll inf = 2e9;

typedef pair<ll, pair<int, int> > pipii;

std::priority_queue< pipii , std::vector<pipii>, std::greater<pipii> > que;

void cdq(int xl, int xr, int yl, int yr, int ql, int qr){
    // cerr << xl << ' ' << xr << ' ' << yl << ' ' << yr << ' ' << ql << ' ' << qr << endl;
    // rep(i, ql, qr){
    //     cerr << ask[i].x1 << ' ' << ask[i].y1 << ' ' << ask[i].x2 << ' ' << ask[i].y2 << endl;
    // }
    // cerr << ask[ql].x1 << 
    // rep(i, ql, qr) assert(xl <= ask[i].x1 && ask[i].x1 <= xr && xl <= ask[i].x2 && ask[i].x2 <= xr && yl <= ask[i].y1 && ask[i].y1 <= yr &&  yl <= ask[i].y2 && ask[i].y2 <= yr);
    if (ql > qr) return;
    if (xl == xr && yl == yr){ rep(i, ql, qr) ans[ask[i].id] = 0; return; }
    if (xr - xl > yr - yl){
        // cerr << "x" << endl;
        // cut x
        int mid = (xl + xr) / 2;
        rep(i, yl, yr) {

            rep(i, yl, yr) rep(j, xl, xr) dis[i-yl][j] = inf;
            dis[i-yl][mid] = 0;
            assert(que.empty());
            que.push({0, {mid, i}});
            while(que.size()){
                ll d = que.top().first; int x = que.top().second.first, y = que.top().second.second; que.pop();
                if (d > dis[y-yl][x]) continue;

                int nx, ny, edge;

                // up
                nx = x-1, ny = y, edge = c[nx][ny];
                if (xl <= nx && nx <= xr && yl <= ny && ny <= yr &&
                    dis[ny-yl][nx] > d + edge){
                    dis[ny-yl][nx] = d + edge;
                    que.push({dis[ny-yl][nx], {nx, ny}});
                }

                // down
                nx = x+1, ny = y, edge = c[x][y];
                if (xl <= nx && nx <= xr && yl <= ny && ny <= yr &&
                    dis[ny-yl][nx] > d + edge){
                    dis[ny-yl][nx] = d + edge;
                    que.push({dis[ny-yl][nx], {nx, ny}});
                }

                // left
                nx = x, ny = y-1, edge = r[nx][ny];
                if (xl <= nx && nx <= xr && yl <= ny && ny <= yr &&
                    dis[ny-yl][nx] > d + edge){
                    dis[ny-yl][nx] = d + edge;
                    que.push({dis[ny-yl][nx], {nx, ny}});
                }

                // right
                nx = x, ny = y+1, edge = r[x][y];
                if (xl <= nx && nx <= xr && yl <= ny && ny <= yr &&
                    dis[ny-yl][nx] > d + edge){
                    dis[ny-yl][nx] = d + edge;
                    que.push({dis[ny-yl][nx], {nx, ny}});
                }
            }

            rep(i, ql, qr)
                ans[ask[i].id] = std::min(ans[ask[i].id], dis[ask[i].y1-yl][ask[i].x1] + dis[ask[i].y2-yl][ask[i].x2]);
        }

        int cnt1 = 0, cnt2 = 0;
        rep(i, ql, qr){
            if (ask[i].x1 <= mid && ask[i].x2 <= mid) ask1[++cnt1] = ask[i];
            else if (ask[i].x1 > mid && ask[i].x2 > mid) ask2[++cnt2] = ask[i];
        }
        rep(i, 1, cnt1) ask[ql+i-1] = ask1[i];
        rep(i, 1, cnt2) ask[ql+cnt1+i-1] = ask2[i];
        cdq(xl, mid, yl, yr, ql, ql+cnt1-1);
        cdq(mid+1, xr, yl, yr, ql+cnt1, ql+cnt1+cnt2-1);

    } else {
        // cerr << "y" << endl;
        // cut y
        int mid = (yl + yr) / 2;
        rep(i, xl, xr) {

            rep(i, xl, xr) rep(j, yl, yr) dis[i-xl][j] = inf;
            dis[i-xl][mid] = 0;
            assert(que.empty());
            que.push({0, {i, mid}});
            while(que.size()){
                ll d = que.top().first; int x = que.top().second.first, y = que.top().second.second; que.pop();
                if (d > dis[x-xl][y]) continue;

                int nx, ny, edge;

                // up
                nx = x-1, ny = y, edge = c[nx][ny];
                if (xl <= nx && nx <= xr && yl <= ny && ny <= yr &&
                    dis[nx-xl][ny] > d + edge){
                    dis[nx-xl][ny] = d + edge;
                    que.push({dis[nx-xl][ny], {nx, ny}});
                }

                // down
                nx = x+1, ny = y, edge = c[x][y];
                if (xl <= nx && nx <= xr && yl <= ny && ny <= yr &&
                    dis[nx-xl][ny] > d + edge){
                    dis[nx-xl][ny] = d + edge;
                    que.push({dis[nx-xl][ny], {nx, ny}});
                }

                // left
                nx = x, ny = y-1, edge = r[nx][ny];
                if (xl <= nx && nx <= xr && yl <= ny && ny <= yr &&
                    dis[nx-xl][ny] > d + edge){
                    dis[nx-xl][ny] = d + edge;
                    que.push({dis[nx-xl][ny], {nx, ny}});
                }

                // right
                nx = x, ny = y+1, edge = r[x][y];
                if (xl <= nx && nx <= xr && yl <= ny && ny <= yr &&
                    dis[nx-xl][ny] > d + edge){
                    dis[nx-xl][ny] = d + edge;
                    que.push({dis[nx-xl][ny], {nx, ny}});
                }
            }

            rep(i, ql, qr)
                ans[ask[i].id] = std::min(ans[ask[i].id], dis[ask[i].x1-xl][ask[i].y1] + dis[ask[i].x2-xl][ask[i].y2]);
        }

        int cnt1 = 0, cnt2 = 0;
        rep(i, ql, qr){
            if (ask[i].y1 <= mid && ask[i].y2 <= mid) ask1[++cnt1] = ask[i];
            else if (ask[i].y1 > mid && ask[i].y2 > mid) ask2[++cnt2] = ask[i];
        }
        rep(i, 1, cnt1) ask[ql+i-1] = ask1[i];
        rep(i, 1, cnt2) ask[ql+cnt1+i-1] = ask2[i];

        cdq(xl, xr, yl, mid, ql, ql+cnt1-1);
        cdq(xl, xr, mid+1, yr, ql+cnt1, ql+cnt1+cnt2-1);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n >> m;
    r.resize(n+1); c.resize(n+1);
    rep(i, 0, n) r[i].resize(m+1), c[i].resize(m+1);
    rep(i, 1, n) rep(j, 1, m-1) cin >> r[i][j];
    rep(i, 1, n-1) rep(j, 1, m) cin >> c[i][j];
    int q; cin >> q;
    rep(i, 1, q){
        ask[i].id = i; ans[i] = inf;
        cin >> ask[i].x1 >> ask[i].y1 >> ask[i].x2 >> ask[i].y2;
    }
    cdq(1, n, 1, m, 1, q);
    rep(i, 1, q) cout << ans[i] << '\n';
    return 0;
}