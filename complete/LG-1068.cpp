#include <algorithm>
#include <cmath>
#include <iostream>
struct cell {
    int num = 0, score = 0;
} a[5002];
bool cmp(struct cell a, struct cell b) {
    if (a.score != b.score) return a.score > b.score;
    return a.num < b.num;
}
int main() {
    using namespace std;
    int m, n, i, sum = 0;
    cin >> n >> m;
    for (i = 0; i < n; i++) cin >> a[i].num >> a[i].score;
    sort(a, a + n, cmp);
    m = floor(m * 1.5);
    cout << a[m - 1].score << ' ';
    for (i = 0; a[i].score >= a[m - 1].score; i++) sum++;
    cout << sum << endl;
    for (i = 0; i < sum; i++) cout << a[i].num << ' ' << a[i].score << endl;
    return 0;
}
