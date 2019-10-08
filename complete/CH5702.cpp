#include <cmath>
#include <cstring>
#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
typedef long long ll;
const int N = 103, M = 1e6, K = 27;

ll f[N][28];
char s1[N], s2[N];

int main() {
    int l1, l2, n1, n2;
    while (cin >> s2 >> n2 >> s1 >> n1) {
        // init
        l1 = strlen(s1), l2 = strlen(s2);
        for (int i = 0; i < l1; ++i) {
            int x = 0, cnt = 0;
            f[i][0] = 0;
            for (int y = 0; y < l2 && cnt <= l1; f[i][0]++, cnt++) {
                if (s2[y] == s1[(i + f[i][0]) % l1]) ++y, cnt = 0;
            }
            if (cnt > l1) f[i][0] = 1e9;
        }

        // double
        for (int j = 1; j <= K; ++j)
            for (int i = 0; i < l1; ++i) f[i][j] = f[i][j - 1] + f[(i + f[i][j - 1]) % l1][j - 1];

        // get ans
        ll m = 0, x = 0, ans = 0;
        for (int k = K; k >= 0; --k)
            if (x + f[x % l1][k] <= l1 * n1) x += f[x % l1][k], ans += (1 << k);
        m = std::max(m, ans);
        cout << (m / n2) << endl;
    }
    return 0;
}