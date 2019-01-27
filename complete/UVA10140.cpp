#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define rep(i, l, r) for (register unsigned int i = (l); i <= (r); ++i)
#define per(i, l, r) for (register unsigned int i = (l); i >= (r); --i)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
typedef pair<int, int> pii;
bool book[2000009], flag[70000];
unsigned int prime[70000];
int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cerr.tie(0);
    unsigned int tot = 0, l, r, n;
    n = 47000;
    flag[0] = flag[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (!flag[i]) prime[++tot] = i;
        for (int j = 1; j <= tot && i * prime[j] <= n; ++j) {
            flag[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    while (cin >> l >> r) {
        std::memset(book, 0, sizeof(book));
        if (l == 1) book[0] = 1;
        for (int i = 1; i <= tot && r >= prime[i]; ++i) {
            unsigned int j;
            if (l <= prime[i])
                j = prime[i] * 2;
            else if (l % prime[i] == 0)
                j = l;
            else
                j = (l / prime[i] + 1) * prime[i];
            // cerr << j << ' ';
            for (; j <= r; j += prime[i]) {
                // cerr << j << ' ';
                if (j < 0) {
                    cout << "-";
                }
                book[j - l] = 1;
            }
        }
        int minl, minr, maxl, maxr, minlen = 2100000000, last = -1, maxlen = 0;
        int out = 1;
        rep(i, 0, r - l) {
            if (!book[i]) {
                last = i;
                break;
            }
        }
        // cout << last << endl;
        rep(i, last + 1, r - l) {
            if (!book[i]) {
                out = 0;
                if (maxlen < i - last) {
                    maxl = last;
                    maxr = i;
                    maxlen = i - last;
                }
                if (minlen > i - last) {
                    minl = last;
                    minr = i;
                    minlen = i - last;
                }
                last = i;
            }
        }
        if (out)
            cout << "There are no adjacent primes.\n";
        else
            cout << minl + l << ',' << minr + l << " are closest, " << maxl + l << ',' << maxr + l << " are most distant.\n";
    }
    return 0;
}