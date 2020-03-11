#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
int main() {
    int map[10][5] = {{4, 0, 4, 3, 3}, {0, 0, 0, 1, 1}, {4, 4, 4, 1, 2}, {4, 4, 4, 1, 1}, {0, 4, 0, 3, 1}, {4, 4, 4, 2, 1}, {4, 4, 4, 2, 3}, {4, 0, 0, 1, 1}, {4, 4, 4, 3, 3}, {4, 4, 4, 3, 1}};
    int n = 0, k, a[50], i, j;
    char c;
    cin >> k;

    while (cin >> c) {
        if ((c >= '0') && (c <= '9')) {
            a[n] = c - '0';
            ++n;
        }
    }

    // while (cin >> a[n++]);
    std::string ans[5];
    ans[0].append(k + 2, ' ');
    ans[1].append(k + 1, ' ');
    ans[1].append(1, '|');
    ans[2].append(1, '|');
    ans[2].append(k + 1, ' ');
    ans[3].append(1, '|');
    ans[3].append(k, ' ');
    ans[3].append(1, '|');
    ans[4].append(1, ' ');
    ans[4].append(k, '-');
    ans[4].append(1, ' ');
    for (i = 0; i < 2 * k + 3; ++i) {
        for (j = 0; j < n; ++j) {
            if (i == 0)
                cout << ans[map[a[j]][0]];
            else if (i == k + 1)
                cout << ans[map[a[j]][1]];
            else if (i == k * 2 + 2)
                cout << ans[map[a[j]][2]];
            else if (i < k + 1)
                cout << ans[map[a[j]][3]];
            else
                cout << ans[map[a[j]][4]];

            cout << ' ';
        }
        cout << endl;
    }
    return 0;
}