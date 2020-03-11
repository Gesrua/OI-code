#include <algorithm>
#include <bitset>
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
int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }
int solve(int a) {
    int ret = 0;
    rep(b, 1, a - 1) ret = std::max(ret, gcd(a ^ b, a & b));
    // cout << std::bitset<32>(a) << ' ' << std::bitset<32>(ret) << endl;
    // cout << std::bitset<32>(ret) << ' ' << a << endl;
    return ret;
}
int ans[33554532];
int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int q;
    ans[7] = 7;
    rep(i, 3, 24) {
        int s = 1 << i, e = (1 << (i + 1)) - 1;
        ans[s] = ans[s - 1] * 2 + 1;
        rep(j, s + 1, e) ans[j] = ans[j - 1];
    }
    ans[15] = 5;
    ans[31] = 1;
    ans[63] = 21;
    ans[127] = 1;
    ans[255] = 85;
    ans[511] = 73;
    ans[1023] = 341;
    ans[2047] = 89;
    ans[4095] = 1365;
    ans[8191] = 1;
    ans[16383] = 5461;
    ans[32767] = 4681;
    ans[65535] = 21845;
    ans[131071] = 1;
    ans[262143] = 87381;
    ans[524287] = 1;
    ans[1048575] = 349525;
    ans[2097151] = 299593;
    ans[4194303] = 1398101;
    ans[8388607] = 178481;
    ans[16777215] = 5592405;
    ans[33554431] = 1082401;
    rep(i, 2, 8) ans[i] = solve(i);
    // rep(i, 2, 5000) { cout << ans[i] << endl; }
    cin >> q;
    while (q--) {
        int a;
        cin >> a;
        cout << ans[a] << endl;
    }

    return 0;
}
