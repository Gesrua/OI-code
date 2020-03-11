#include <bits/stdc++.h>
int main() {
    int l, r, ans = 0, t;
    std::cin >> l >> r;
    for (; l <= r; l++) {
        t = l;
        while (t) {
            if (t % 10 == 2) ans++;
            t /= 10;
        }
    }
    std::cout << ans;
    return 0;
}
