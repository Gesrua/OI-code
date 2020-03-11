#include <cstdio>
#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
int main() {
    int a, b, c, s;
    int cnt = 1;
    while (cin >> a >> b >> c >> s) {
        if (a == -1) return 0;
        int ori = s;
        for (++s; s < ori + 21253; ++s) {
            if ((s - a) % 23 == 0 && (s - b) % 28 == 0 && (s - c) % 33 == 0) {
                std::printf("Case %d: the next triple peak occurs in %d days.\n", cnt, s - ori);
                goto next;
            }
        }
    next:
        ++cnt;
    }
    return 0;
}