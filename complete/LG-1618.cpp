#include <cstring>
#include <iostream>
using namespace std;
int a, b, c, ans[100000][4], cur = 0;
void check(int x, int y, int z) {
    int l = x, m = y, n = z;
    int book[10] = {0};
    book[l % 10]++;
    book[m % 10]++;
    book[n % 10]++;
    l = l / 10;
    m = m / 10;
    n = n / 10;
    book[l % 10]++;
    book[m % 10]++;
    book[n % 10]++;
    l = l / 10;
    m = m / 10;
    n = n / 10;
    book[l % 10]++;
    book[m % 10]++;
    book[n % 10]++;
    for (int i = 1; i <= 9; i++)
        if (book[i] != 1) return;
    if (book[0] == 1) return;
    ans[cur][0] = x;
    ans[cur][1] = y;
    ans[cur][2] = z;
    cur++;
}
int main() {
    memset(ans, 0, sizeof(ans));
    int temp, i, j, k;
    cin >> a >> b >> c;
    ios::sync_with_stdio(false);
    k = 0;
    temp = 0;
    while (true) {
        temp++;
        i = temp * a;
        if (i < 100) continue;
        j = temp * b;
        k = temp * c;
        if (k < 1000)
            check(i, j, k);
        else
            break;
    }
    if (cur == 0)
        cout << "No!!!";
    else
        for (i = 0; i < cur; i++) cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << ' ' << endl;
    return 0;
}
