#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
int N, M, L, dis[50010] = {};
bool check(int x) {
    int cnt = 0, len, l, r, mid;
    for (int i = 0; i <= N;) {
        // cerr << "i = " << i << endl;
        l = i + 1;
        r = N + 1;
        len = dis[i] + x;
        if (L < len) return false;
        while (l != r) {
            // cerr << "HERE" << ' ';
            mid = (l + r) >> 1;
            if (dis[mid] >= len) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        // cerr << " l = " << l << endl;
        cnt += l - i - 1;
        if (cnt > M) return false;
        i = l;
    }
    return true;
}
int main() {
    std::ios::sync_with_stdio(false);
    cin >> L >> N >> M;
    dis[0] = 0;
    dis[N + 1] = L;
    dis[N + 2] = 2100000000;
    for (int i = 1; i <= N; ++i) {
        cin >> dis[i];
    }
    int l = 0, r = 210000000, mid;
    while (l != r) {
        // cerr << l << ' ' << r << endl;
        // cerr << "here" << ' ';
        mid = ((l + r) >> 1) + 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l;
    return 0;
}