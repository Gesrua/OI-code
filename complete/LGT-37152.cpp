#include <iostream>
const int N = 5;
const int M = 6;
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
int map[10][10], ori[10][10], action[10][10];
void print() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cout << action[i][j] % 2 << ' ';
        }
        cout << endl;
    }
}
inline void act(int x, int y) {
    action[x][y] = 1;
    map[x][y] ^= 1, map[x + 1][y] ^= 1, map[x - 1][y] ^= 1, map[x][y + 1] ^= 1, map[x][y - 1] ^= 1;
}
int main() {
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int xiw = 1; xiw <= t; xiw++) {
        cout << "PUZZLE #" << xiw << endl;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                cin >> ori[i][j];
            }
        }
        for (int i = 0; i < 64; ++i) {
            for (int i = 1; i <= N; ++i) {
                for (int j = 1; j <= M; ++j) {
                    action[i][j] = 0;
                    map[i][j] = ori[i][j];
                }
            }
            // cerr << i << endl;
            bool flag = true;
            for (int j = 0; j < 6; ++j)
                if (i & (1 << j)) act(1, j + 1);
            for (int k = 2; k <= 5; ++k)
                for (int j = 1; j <= 6; ++j)
                    if (map[k - 1][j]) act(k, j);
            for (int j = 1; j <= 6; ++j)
                if (map[5][j]) {
                    flag = false;
                    break;
                }
            if (flag) print();
        }
    }
    return 0;
}