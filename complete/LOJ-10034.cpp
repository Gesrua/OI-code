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

struct Hash {
    int p, ratio;
    std::set<int> s;
    Hash() : p(998244353), ratio(127) {}
    Hash(int _p, int _r) : p(_p), ratio(_r) {}
    int calc(std::string& s, int st) {
        ll ret = 0;
        rep(i, st, s.size() - 1) { ret = (ret * ratio + s[i]) % p; }
        return ret;
    }
    void add(std::string& s, int st) { this->s.insert(calc(s, st)); }
    bool ask(std::string& s, int st) { return (this->s).count(calc(s, st)); }
} h1;

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n;
    cin >> n;
    std::string s;
    getline(cin, s);
    while (n--) {
        getline(cin, s);
        if (s[0] == 'a')
            h1.add(s, 4);
        else
            cout << (h1.ask(s, 5) ? "yes" : "no") << endl;
    }
    return 0;
}