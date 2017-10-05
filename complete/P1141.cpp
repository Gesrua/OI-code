#include <iostream>
#include <string>
#include <vector>
#include <queue>
// std::vector<int> a(1000,0);
int a[100000] = {};
bool map[1001][1001] = {};
int n, m, s[1001][1001] = {}, cur = 0;
void read(){
    int i, j;
    using namespace std;
    string t;
    cin >> n >> m;
    for (i=1; i<=n; i++) {
        cin >> t;
        for (j=1; j<=n; j++) {
            s[i][j] = -1;
            if (t[j-1] == '1') map[i][j] = true;
        }
    }
    return;
}
int t_x, t_y;
bool check(int t1, int t2){
    if (t1 < 1 || t2 < 1 || t1 > n || t2 > n) return false;
    return true;
}
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int solve(){
    if (s[t_x][t_y] != -1) {
        return a[s[t_x][t_y]];
    }
    cur++;
    std::queue<int> x, y;
    x.push(t_x);
    y.push(t_y);
    s[t_x][t_y] = cur;
    a[cur]++;
    int t1, t2, i;
    while (!x.empty()) {
        for (i=0; i<4; i++) {
            t1 = x.front() + dir[i][0];
            t2 = y.front() + dir[i][1];
            // std::cout << "debug " << t1 << ' ' << t2 << ' ' << check(t1,t2) << ' ' << (map[x.front()][y.front()] != map[t1][t2]) << ' ' << (s[t1][t2] == 0)  << std::endl;
            // std::cout << "debug " << t1 << ' ' << t2 << std::endl;
            if (!check(t1,t2)) continue;
            if ((s[t1][t2] == -1) && (map[x.front()][y.front()] != map[t1][t2])) {
                // std::cout << "debug " << t1 << ' ' << t2 << std::endl;
                s[t1][t2] = cur;
                x.push(t1);
                y.push(t2);
                a[cur]++;
            }
        }
        x.pop();
        y.pop();
    }
    return a[cur];
}
int main(){
    read();
    for (int i=0; i<m; i++) {
        std::cin >> t_x >> t_y;
        std::cout << solve() << std::endl;
    }
    return 0;
}
