#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
struct sys {
    int x, y, r;
} a, b;
struct node {
    int da, db;
} A[100001];
bool cmp(node x, node y) { return x.da < y.da; }
int dis(int x1, int y1, int x2, int y2) { return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2); }
unsigned int n, ans = 2100000000;
int main() {
    cin >> a.x >> a.y >> b.x >> b.y >> n;
    int t1, t2, i;
    for (i = 1; i <= n; i++) {
        cin >> t1 >> t2;
        A[i].da = dis(t1, t2, a.x, a.y);
        A[i].db = dis(t1, t2, b.x, b.y);
    }
    std::sort(A + 1, A + 1 + n, cmp);
    for (i = n; i; --i) {
        b.r = std::max(A[i + 1].db, b.r);
        if (ans > A[i].da + b.r) ans = A[i].da + b.r;
    }
    cout << ans;
    return 0;
}