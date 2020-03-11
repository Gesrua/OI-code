#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::sort;
int is_prime(long long x) {
    if (x == 1) return 0;
    if (x == 2) return 1;
    long long lim = std::sqrt(x) + 1e-3;
    for (long long i = 2; i <= lim; ++i)
        if (x % i == 0) return 2;

    return 1;
}
int N, M;
long long a[100010], b[100010];
long long t;
int main() {
    int T;
    std::ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> N >> M;
        for (register int i = 0; i < N; ++i) cin >> a[i];
        sort(a, a + N);
        for (register int j = 0; j < M; ++j) cin >> b[j];
        sort(b, b + M);
        for (register int i = 0, j = 0; j < M;) {
            if (a[i] == b[j]) {
                a[i] = 1;
                ++i, ++j;
                continue;
            }
            if (a[i] < b[j]) ++i;
        }
        int cnt = 0;
        for (register int i = 0; i < N; ++i) {
            cnt += is_prime(a[i]);
            if (cnt > 1) break;
        }
        if (cnt == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}