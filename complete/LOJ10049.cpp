#include <cstring>
#include <iostream>
#include <string>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define clear(x) std::memset(x, 0, sizeof(x))
const int N = 100100;
int ch[N][10], rt = 1, cnt, tag[N];

void solve() {
    clear(tag);
    clear(ch);
    cnt = 1;
    int n;
    cin >> n;
    string s;
    bool ret = 0;
    rep(i, 1, n) {
        cin >> s;
        if (ret) continue;
        int cur = 0;
        rep(j, 0, s.size() - 1) {
            if (ch[cur][s[j] - '0'] == 0) {
                cur = ch[cur][s[j] - '0'] = cnt++;
                // cerr << cur << ' ';
                if (j == s.size() - 1) tag[cur] = 1;
            } else {
                cur = ch[cur][s[j] - '0'];
                if (j != s.size() - 1 && tag[cur]) {
                    ret = 1;
                    break;
                }
                if (j == s.size() - 1 && !tag[cur]) ret = tag[cur] = 1;
            }
        }
    }
    cout << (ret ? "NO" : "YES") << endl;
}

int main() {
    std::ios::sync_with_stdio(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}