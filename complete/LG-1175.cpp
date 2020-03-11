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
char c[200];

struct Node {
    int num = -1;
    char opt;
} ret[200];

std::stack<char> s;

std::map<char, int> op;

int pw(int a, int n) {
    int ret = 1;
    rep(i, 1, n) ret *= a;
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    op['('] = 0, op['+'] = op['-'] = 1, op['*'] = op['/'] = 2, op['^'] = 3;
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> c + 1;
    int n = strlen(c + 1);
    c[n + 1] = '+';
    n++;
    int num = -1, cnt = 0;
    rep(i, 1, n + 1) {
        if (isdigit(c[i])) {
            if (num = -1) num = 0;
            num = num * 10 + c[i] - '0';
        } else {
            if (num != -1) ret[cnt++].num = num;
            num = -1;
            if (c[i] == '(') {
                s.push(c[i]);
            } else if (c[i] == ')') {
                while (s.top() != '(') {
                    ret[cnt++].opt = s.top();
                    s.pop();
                }
                s.pop();
            } else if (c[i] == '*' || c[i] == '/' || c[i] == '+' ||
                       c[i] == '-' || c[i] == '^') {
                while (s.size() && op[s.top()] >= op[c[i]]) {
                    ret[cnt++].opt = s.top();
                    s.pop();
                }
                s.push(c[i]);
            }
        }
    }
    int nxt = 1, t1, t2;
    while (nxt) {
        nxt = 0;
        for (int i = 0; i < cnt; i++) {
            if (ret[i].opt == 0 && ret[i].num == -1)
                continue;
            else if (ret[i].opt)
                cout << ret[i].opt << ' ';
            else
                cout << ret[i].num << ' ';
        }
        for (int i = 0; i < cnt; i++) {
            if (ret[i].opt == 0 && ret[i].num == -1)
                continue;
            else if (ret[i].opt) {
                switch (ret[i].opt) {
                    case '+':
                        ret[t1].num += ret[t2].num;
                        break;
                    case '-':
                        ret[t1].num -= ret[t2].num;
                        break;
                    case '*':
                        ret[t1].num *= ret[t2].num;
                        break;
                    case '/':
                        ret[t1].num /= ret[t2].num;
                        break;
                    case '^':
                        ret[t1].num = pw(ret[t1].num, ret[t2].num);
                        break;
                }
                nxt = 1;
                ret[t2].num = -1, ret[i].opt = 0;
                break;
            } else
                t1 = t2, t2 = i;
        }
        cout << endl;
    }
    return 0;
}