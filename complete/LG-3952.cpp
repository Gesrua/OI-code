#include <cctype>
#include <iostream>
#include <stack>
#include <string>
std::string prog[100];
int pipei[300] = {};
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;
int getNum(const std::string &s, int pos) {
    int ans = 0;
    while (std::isdigit(s[pos]) & pos < s.size()) {
        ans *= 10;
        ans += s[pos] - '0';
        ++pos;
    }
    return ans;
}
bool is_legal(int l, int r) {
    std::stack<char> s;
    int loop = 0;
    int flag[256] = {};
    for (int i = l; i < r; ++i) {
        if (prog[i][0] == 'F') {
            ++loop;
            if (flag[prog[i][2]] != 0) return false;
            ++flag[prog[i][2]];
            s.push(prog[i][2]);
        } else {
            --loop;
            if (loop < 0) return false;
            --flag[s.top()];
            s.pop();
        }
    }
    if (loop != 0 || !s.empty()) return false;
    return true;
}
int calc(int l) {
    if (l > pipei[l]) return 0;
    int k = 0, ans = 0;
    if (prog[l].find('n') == std::string::npos) {
        // 起始和结束都是数字，判断是否可以进入循环
        int le = 0;
        int i = 4, r = 0;
        while (std::isdigit(prog[l][i])) {
            // cerr << prog[l][i] << prog[l][i+1] << endl;
            // cerr << i+1 << std::isdigit(prog[l][i+1]) << endl;
            le *= 10;
            le += prog[l][i] - '0';
            ++i;
            // cerr << i << std::isdigit(prog[l][i]) << endl;
        }
        ++i;
        // cerr << i << endl;
        while (std::isdigit(prog[l][i]) && i < prog[l].size()) {
            r *= 10;
            r += prog[l][i] - '0';
            ++i;
        }
        // cerr << le << ' ' << r;
        if (le > r) {
            return 0;
        }
        k = 0;
    } else {
        if (prog[l][4] == 'n') {
            if (prog[l][6] == 'n') {
                // 两个都是 n 可以进入
                k = 0;
            } else
                return 0;  // n > 100 不可以进入
        } else {
            k = 1;  // 可以进入，复杂度 O(n)
        }
    }
    if (l + 1 == pipei[l]) return k;
    for (int i = l + 1; i < pipei[l]; i = pipei[i] + 1) {
        // cerr << i << ' ';
        ans = max(calc(i), ans);
    }
    return k + ans;
}
int main() {
    int n, in, k, l, t;
    char c;
    std::string s;
    cin >> n;
    while (n--) {
        cin >> l >> s;

        // 读入预估时间复杂度 t
        if (s[2] == '1') {
            t = 0;
        } else {
            if (s[2] == 'n') {
                if (s[3] == ')') {
                    t = 1;
                } else {
                    t = getNum(s, 4);
                }
            }
        }
        //
        cin.get();
        for (int i = 0; i < l; ++i) std::getline(cin, prog[i]);

        if (is_legal(0, l)) {
            // 循环匹配
            std::stack<int> s;
            for (int i = 0; i < l; ++i) {
                if (prog[i][0] == 'F') {
                    s.push(i);
                }
                if (prog[i][0] == 'E') {
                    pipei[s.top()] = i;
                    pipei[i] = 0;
                    s.pop();
                }
            }

            k = 0;

            for (int i = 0; i < l; i = pipei[i] + 1) {
                // cerr << i << ' ';
                k = max(calc(i), k);
            }

            if (k == t) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
            // cerr << "Right\n";
        } else {
            cout << "ERR\n";
        }
    }
    return 0;
}
