// Segment tree is my nightmare
#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;
const int NMAX = 100000;
const int MMAX = 100000;
int a[NMAX + 10];
long long T[NMAX * 4] = {}, lazy[NMAX * 4] = {};
int L, R, ADD;
void build(int idx, int l, int r) {
    // cerr << idx << ' ' << l << ' ' << r << endl;
    if (l == r) {
        T[idx] = a[l];
        // cerr << l << ' ' << r << ' ' << T[idx] << endl;
        return;
    }
    int mid = (l + r) >> 1;
    build((idx << 1), l, mid);
    build((idx << 1) | 1, mid + 1, r);
    T[idx] = T[idx << 1] + T[(idx << 1) | 1];
    // cerr << l << ' ' << r << ' ' << T[idx] << endl;
}
void print(int idx, int l, int r) {
    if (l == r) {
        cerr << l << ' ' << r << ' ' << T[idx] << ' ' << lazy[idx] << endl;
        return;
    }
    int mid = (l + r) >> 1;
    print(idx << 1, l, mid);
    print((idx << 1) | 1, mid + 1, r);
    cerr << l << ' ' << r << ' ' << T[idx] << ' ' << lazy[idx] << endl;
}
void add(int idx, int l, int r) {
    if (R < l || r < L) {
        return;
    }
    if (l == r) {
        T[idx] += ADD;
        return;
    }
    if (L <= l && r <= R) {
        lazy[idx] += ADD;
        T[idx] += (r - l + 1) * ADD;
        return;
    }

    int mid = (l + r) >> 1;
    int lson = (idx << 1), rson = (idx << 1) | 1;

    // lazy 下放

    lazy[lson] += lazy[idx];
    T[lson] += (mid - l + 1) * lazy[idx];
    lazy[rson] += lazy[idx];
    T[rson] += (r - mid) * lazy[idx];
    lazy[idx] = 0;

    add(lson, l, mid);
    add(rson, mid + 1, r);
    T[idx] = T[lson] + T[rson];
    return;
}
long long query(int idx, int l, int r) {
    if (R < l || r < L) {
        return 0;
    }
    if (L <= l && r <= R) {
        return T[idx];
    }
    int mid = (l + r) >> 1;
    int lson = (idx << 1), rson = (idx << 1) | 1;

    // lazy 下放

    lazy[lson] += lazy[idx];
    T[lson] += (mid - l + 1) * lazy[idx];
    lazy[rson] += lazy[idx];
    T[rson] += (r - mid) * lazy[idx];
    lazy[idx] = 0;

    return query(lson, l, mid) + query(rson, mid + 1, r);
}
int main() {
    int N, M;
    std::ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) cin >> a[i];
    build(1, 1, N);
    int opt;
    for (int i = 1; i <= M; ++i) {
        cin >> opt;
        if (opt == 1) {
            cin >> L >> R >> ADD;
            add(1, 1, N);
        } else {
            cin >> L >> R;
            cout << query(1, 1, N) << endl;
        }
    }
    return 0;
}
