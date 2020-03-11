#include <algorithm>
#include <iostream>
struct node {
    int l = 0, w = 0;
    bool operator<(const node& b) { return (this->l != b.l) ? (this->l < b.l) : (this->w < b.w); }
} a[5001], tmp;
bool flag[5001] = {};
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;
int n;
int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].l >> a[i].w;
    }
    // cerr << "flag1\n";
    std::sort(a, a + n);
    // for (int i = 0; i < n; ++i){
    //  cout << a[i].l << ' ' << a[i].w << endl;
    // }
    int t, ans = 0;
    for (int i = 0; i < n;) {
        for (int j = n - 1; j >= 0; --j) {
            if (!flag[j]) {
                t = j;
                tmp = a[j];
                break;
            }
        }
        for (int j = t; j >= 0; --j) {
            if (!flag[j] && (a[j].l <= tmp.l) && (a[j].w <= tmp.w)) {
                // cerr << j << ' ';
                tmp = a[j];
                flag[j] = true;
                ++i;
            }
        }
        // cerr << "\ncerr complete\n";
        ++ans;
    }
    cout << ans;
    return 0;
}
