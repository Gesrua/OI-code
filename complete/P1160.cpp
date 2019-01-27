#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
const int N = 100002;
struct node {
    int left, right;
} a[N];
int n, m;
void merge(int x, int y) {
    a[x].right = y;
    a[y].left = x;
}
int main() {
    int k, p;
    std::ios::sync_with_stdio(false);
    cin >> n;
    std::memset(a, 0, sizeof(a));
    a[1].left = N - 1;
    a[N - 1].right = 1;
    for (int i = 2; i <= n; ++i) {
        cin >> k >> p;
        if (p == 1) {
            if (a[k].right != 0) merge(i, a[k].right);
            merge(k, i);
        } else {
            if (a[k].left != 0) merge(a[k].left, i);
            merge(i, k);
        }
    }
    int pos = N - 1;
    /*
       cout << endl;
       for (int i=0;i<n;++i){
        pos = a[pos].right;
        cout << pos << ' ';
       }
       cout << endl;
     */
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> k;
        if (a[k].left == a[k].right) continue;
        a[a[k].left].right = a[k].right;
        a[a[k].right].left = a[k].left;
        a[k].left = a[k].right = 0;
    }
    pos = N - 1;
    // cout << endl;
    while (a[pos].right != 0) {
        pos = a[pos].right;
        cout << pos << ' ';
    }
    return 0;
}