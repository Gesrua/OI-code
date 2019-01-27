#include <algorithm>
#include <iostream>
#include <string>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::string;
std::string t, a[100000];
int n;
int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    cin >> t;
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        if (a[i].size() < t.size()) continue;
        if (a[i].substr(0, t.size()) == t) {
            cout << a[i] << endl;
            flag = true;
            continue;
            if (flag) break;
        }
    }
    return 0;
}