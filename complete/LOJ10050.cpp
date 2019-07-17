#include <iostream>
using std::cin;
using std::cout;
const int N = 100100;

int ch[N * 32][2], cnt = 1;

int main() {
    int n;
    int ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int t;
        cin >> t;
        int cur = 0, ac = 0, tot = 0;
        for (int i = 31; i >= 0; --i) {
            int s = 1 & (t >> i);
            if (!ch[cur][s]) ch[cur][s] = cnt++;
            cur = ch[cur][s];
            if (ch[ac][s ^ 1])
                ac = ch[ac][s ^ 1], tot += 1 << i;
            else
                ac = ch[ac][s];
        }
        if (ans < tot) ans = tot;
    }
    cout << ans;
    return 0;
}