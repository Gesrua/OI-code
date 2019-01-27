#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
bool flag[200][200] = {};
long long ans = 0;
int n;
void dfs(int cnt, int x, int y) {
    // cerr << cnt << ' ' << x << ' ' << y << endl;
    if (cnt == n) {
        ++ans;
        return;
    }
    if (!flag[x][y - 1]) {
        flag[x][y - 1] = true;
        // ++ans;
        dfs(cnt + 1, x, y - 1);
        flag[x][y - 1] = false;
    }
    if (!flag[x][y + 1]) {
        flag[x][y + 1] = true;
        // ++ans;
        dfs(cnt + 1, x, y + 1);
        flag[x][y + 1] = false;
    }
    if (!flag[x + 1][y]) {
        flag[x + 1][y] = true;
        // ++ans;
        dfs(cnt + 1, x + 1, y);
        flag[x + 1][y] = false;
    }
}
int main() {
    cin >> n;
    // flag[1][50] = true;
    // dfs(0, 1, 50);
    // cout << ans;
    int a[50];
    a[1] = 3;
    a[2] = 7;
    for (int i = 3; i <= n; ++i) a[i] = (a[i - 1] << 1) + a[i - 2];
    cout << a[n];
    return 0;
}