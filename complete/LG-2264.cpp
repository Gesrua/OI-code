#include <algorithm>
#include <cassert>
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
typedef unsigned long long ull;
int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n;
    cin >> n;
    std::set<std::string> p;
    std::string a, s;
    rep(i, 1, n) {
        cin >> s;
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        p.insert(s);
    }
    std::getline(cin, a), std::getline(cin, a);
    std::set<std::string> cnt;
    a.push_back('.');
    s = "";
    int ans = 0;
    for (auto i : a) {
        if (i == '.') {
            if (p.count(s)) cnt.insert(s);
            // for (auto x : cnt) cerr << x << endl;
            ans += cnt.size();
            cnt.clear();
            s = "";
        } else if (i == ' ' || i == ',') {
            if (p.count(s)) cnt.insert(s);
            s = "";
        } else {
            s.push_back(tolower(i));
        }
    }
    cout << ans;
    return 0;
}