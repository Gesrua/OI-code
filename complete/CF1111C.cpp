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
int cnt = 0;
struct node;
node* nn();
node* nn(ui _l, ui _r);

int L, R;

ll A, B;

struct node {
    ui l, r, cnt = 0;
    node *ls, *rs;
    void pushup() {
        cnt = (ls == nullptr ? 0 : ls->cnt) + (rs == nullptr ? 0 : rs->cnt);
    }
    void insert(int x) {
        if (l == r) {
            cnt++;
            return;
        }
        ui mid = (l + r) / 2;
        if (x <= mid) {
            if (ls == nullptr) ls = nn(l, mid);
            ls->insert(x);
        }
        if (x > mid) {
            if (rs == nullptr) rs = nn(mid + 1, r);
            rs->insert(x);
        }
        pushup();
    }
    ll solve(int dep) {
        ll sol = (ll)B * cnt * (1 << dep);
        if (dep)
            sol = std::min(sol, ((ls == nullptr) ? A : ls->solve(dep - 1)) +
                                    ((rs == nullptr) ? A : rs->solve(dep - 1)));
        return sol;
    }
} t[10000010];

node* nn() { return &t[cnt++]; }
node* nn(ui _l, ui _r) {
    t[cnt].l = _l, t[cnt].r = _r;
    return &t[cnt++];
}

node* rt;

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int n, k;
    cin >> n >> k >> A >> B;
    rt = nn(1, 1 << n);
    rep(i, 1, k) {
        int x;
        cin >> x;
        rt->insert(x);
    }
    cout << rt->solve(n);
    return 0;
}
