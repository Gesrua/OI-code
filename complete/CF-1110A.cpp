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
int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int b, k;
    cin >> b >> k;
    int odd = 0, even = 0;
    for (int i = k - 1; i >= 0; --i) {
        int a;
        cin >> a;
        if (i == 0) {
            if (a % 2 == 0)
                ++even;
            else
                ++odd;
        } else {
            if (b % 2 == 0 || a % 2 == 0)
                ++even;
            else
                ++odd;
        }
    }
    if (odd % 2 == 0) {
        cout << "even";
    } else
        cout << "odd";
    return 0;
}
