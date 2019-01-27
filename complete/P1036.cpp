#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
int n, ans, k, x[25];
bool book[25];
bool is_prime(int n) {
    int i;
    int s = sqrt(double(n));
    for (i = 2; i <= s; i++)
        if (n % i == 0) return false;
    return true;
}
void dfs(int last_step, int number, int sum) {
    int i;
    if (number == k)
        if (is_prime(sum)) ans++;
    for (i = last_step + 1; i <= n; i++)
        if (book[i]) {
            book[i] = false;
            dfs(i, number + 1, sum + x[i]);
            book[i] = true;
        }
}
int main() {
    ans = 0;
    memset(x, 0, sizeof(x));
    memset(book, 1, sizeof(book));
    int i;
    cin >> n >> k;
    for (i = 1; i <= n; i++) cin >> x[i];
    sort(x, x + n);
    dfs(0, 0, 0);
    cout << ans;
    return 0;
}
