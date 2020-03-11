#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int ui;

inline bool is_vowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int a[2000], b[2000];

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    std::string s1, s2;
    cin >> s1;
    rep(i, 0, s1.size() - 1) a[i] = is_vowel(s1[i]);
    cin >> s2;
    rep(i, 0, s2.size() - 1) b[i] = is_vowel(s2[i]);
    if (s1.size() != s2.size()) {
        cout << "No";
    } else {
        rep(i, 0, s1.size() - 1) {
            if (a[i] != b[i]) {
                cout << "No";
                return 0;
            }
        }
        cout << "Yes";
    }
    return 0;
}
