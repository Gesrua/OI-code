#include <deque>
#include <iostream>
#include <utility>

#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::max;
using std::pair;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int ui;

const int N = 1000100;

int a[N * 2];

int q[N * 2];

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n;
    cin >> n;
    rep(i, 1, n) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    int ans = 0;

    int l = 1, r = 1;
    q[1] = 1;
    rep(i, 2, n * 2) {
        while (l <= r && q[l] < i - n / 2) l++;
        ans = std::max(ans, a[i] + i + a[q[l]] - q[l]);
        while (l <= r && a[i] - i >= a[q[r]] - q[r]) r--;
        q[++r] = i;
    }

    cout << ans;
    return 0;
}