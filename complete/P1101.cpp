#include <bits/stdc++.h>
int dir[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
int n;
bool check(int x, int y) {
    if (x < 1 || y < 1 || x > n || y > n) return false;
    return true;
}
int main() {
    bool flag, book[102][102] = {};
    int j, i, k, t1, t2, l;
    char map[102][102] = {};
    char target[10] = "yizhong";
    std::cin >> n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) std::cin >> map[i][j];
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) {
            if (map[i][j] == 'y') {
                for (k = 0; k < 8; k++) {
                    flag = false;
                    t1 = i + dir[k][0];
                    t2 = j + dir[k][1];
                    if (check(t1, t2) && map[t1][t2] == 'i') {
                        flag = true;
                        for (l = 2; l < 7; l++) {
                            t1 = t1 + dir[k][0];
                            t2 = t2 + dir[k][1];
                            if (map[t1][t2] != target[l]) {
                                flag = false;
                                break;
                            }
                        }
                    }
                    if (flag) {
                        t1 = i;
                        t2 = j;
                        for (l = 0; l < 7; l++) {
                            book[t1][t2] = true;
                            t1 += dir[k][0];
                            t2 += dir[k][1];
                        }
                    }
                }
            }
        }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            if (book[i][j])
                std::cout << map[i][j];
            else
                std::cout << '*';
        std::cout << std::endl;
    }
    return 0;
}
