#include <iostream>
struct cell {
    int x, y;
} start, end;
int map[6][6] = {}, ans = 0, n, m, t, dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool book[6][6] = {};
void dfs(cell now) {
    if ((now.x == end.x) && (now.y == end.y)) {
        ans++;
        return;
    }
    if (now.x < 1 || now.x > n || now.y < 1 || now.y > m || !book[now.x][now.y]) return;
    for (int i = 0; i < 4; i++) {
        cell t;
        t.x = now.x + dir[i][0];
        t.y = now.y + dir[i][1];
        if (!book[t.x][t.y]) {
            book[t.x][t.y] = true;
            dfs(t);
            book[t.x][t.y] = false;
        }
    }
}
int main() {
    std::cin >> n >> m >> t;
    std::cin >> start.x >> start.y >> end.x >> end.y;
    for (int i = 0; i < t; i++) {
        int t1, t2;
        std::cin >> t1 >> t2;
        book[t1][t2] = true;
    }
    book[start.x][start.y] = true;
    dfs(start);
    std::cout << ans;
    return 0;
}
