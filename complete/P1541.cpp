#include <cstring>
#include <iostream>
#include <map>
struct node {
    int cur, a, b, c, d;
    bool operator<(const node b) {
        if (this->cur < b.cur) return true;
        if (this->cur > b.cur) return false;
        if (this->a < b.a) return true;
        if (this->a > b.a) return false;
        if (this->b < b.b)
            return true;
        else
            return false;
    }
    node(node &x, int type) {
        switch (type) {
            case 1:
                *this = node(x.cur + 1, x.a - 1, x.b, x.c, x.d);
                break;
            case 2:
                *this = node(x.cur + 2, x.a, x.b - 1, x.c, x.d);
                break;
            case 3:
                *this = node(x.cur + 3, x.a, x.b, x.c - 1, x.d);
                break;
            case 4:
                *this = node(x.cur + 4, x.a, x.b, x.c, x.d - 1);
                break;
        }
    }
    node(int _cur, int _a, int _b, int _c, int _d) : cur(_cur), a(_a), b(_b), c(_c), d(_d) {}
};
// bool node::operator< (const node a, const node b){
//     if(a.cur < b.cur) return true;
//     if(a.cur > b.cur) return false;
//     if(a.a < b.a) return true;
//     if(a.a > b.a) return false;
//     if(a.b < b.b) return true;else return false;
// }
std::map<node, int> dp;
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
// int dp[31][13][13][13][13];
int v[31], n, m;
inline int max_yuan(int a, int b) { return a > b ? a : b; }
inline int max(int a, int b, int c, int d) { return max_yuan(max_yuan(a, b), max_yuan(c, d)); }
// int solve(int cur, int a, int b, int c, int d){
//     // cerr << cur << ' ' << a << ' ' << b << ' ' << c << ' ' << d << endl;
//     if (a < 0 || b < 0 || c < 0 || d < 0 || cur > n) return -2;
//     int &ans = dp[cur][a][b][c][d];
//     if (ans != -1) return ans;
//     if (cur == n) return ans = v[n];
//     ans =
//     max(solve(cur+1,a-1,b,c,d),solve(cur+2,a,b-1,c,d),solve(cur+3,a,b,c-1,d),solve(cur+4,a,b,c,d-1));
//     if (ans == -2) return -2;
//     return ans = (ans + v[cur]);
// }
int solve(node x) {
    // cerr << cur << ' ' << a << ' ' << b << ' ' << c << ' ' << d << endl;
    if (x.a < 0 || x.b < 0 || x.c < 0 || x.d < 0 || x.cur > n) return -2;
    std::map<node, int>::iterator ans = dp.find(x);
    if (ans != dp.end()) return dp[x];
    dp.insert(std::make_pair(x, -2));
    ans = dp.find(x);
    if (x.cur == n) {
        return ans->second = v[n];
    }
    ans->second = max(solve(node(x, 1)), solve(node(x, 2)), solve(node(x, 3)), solve(node(x, 4)));
    if (ans->second == -2) return -2;
    return ans->second = ans->second + v[x.cur];
}
int main() {
    // std::memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for (register int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    int a = 0, b = 0, c = 0, d = 0, tmp;
    for (register int i = 1; i <= m; ++i) {
        cin >> tmp;
        switch (tmp) {
            case 1:
                ++a;
                break;
            case 2:
                ++b;
                break;
            case 3:
                ++c;
                break;
            case 4:
                ++d;
                break;
        }
    }
    cout << solve(node(1, a, b, c, d));
    // cout << solve(1, a, b, c, d) << endl;
    // while(cin >> tmp >> a >> b >> c >> d){
    //     cerr << dp[tmp][a][b][c][d] << endl;
    // }
    return 0;
}