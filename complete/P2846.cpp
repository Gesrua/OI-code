#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;
int N, M, T[400000], L, R, lazy[400000] = {};
int query(int idx, int l, int r) {
    if (r < L || R < l) return 0;
    if (l == r) return T[idx];
    if (L <= l && r <= R) {
        return T[idx];
    }

    // lazy 下放
    int lson = idx << 1, rson = lson | 1, mid = (l + r) >> 1;
    if (lazy[idx]) {
        lazy[idx] = 0;
        lazy[lson] ^= 1;
        lazy[rson] ^= 1;
        T[lson] = mid - l + 1 - T[lson];
        T[rson] = r - mid - T[rson];
    }

    return query(idx << 1, l, mid) + query((idx << 1) | 1, mid + 1, r);
}
void reverse(int idx, int l, int r) {
    if (r < L || R < l) return;
    if (l == r) {
        T[idx] ^= 1;
        return;
    }
    if (L <= l && r <= R) {
        T[idx] = (r - l + 1 - T[idx]);
        lazy[idx] ^= 1;
        return;
    }

    int lson = idx << 1, rson = lson | 1, mid = (l + r) >> 1;
    if (lazy[idx]) {
        lazy[idx] = 0;
        lazy[lson] ^= 1;
        lazy[rson] ^= 1;
        T[lson] = mid - l + 1 - T[lson];
        T[rson] = r - mid - T[rson];
    }

    reverse(lson, l, mid);
    reverse(rson, mid + 1, r);
    T[idx] = T[lson] + T[rson];
}

void print_cell(int idx, int l, int r) {
    cerr << l << ' ' << r << ' ' << T[idx] << ' ' << lazy[idx] << endl;
    if (l == r) return;
    int mid = (l + r) >> 1;
    print_cell(idx << 1, l, mid);
    print_cell((idx << 1) | 1, mid + 1, r);
}
void print() {
    cerr << "------\n";
    print_cell(1, 1, N);
    cerr << "------\n";
}

int main() {
    int opt;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        cin >> opt >> L >> R;
        if (opt) {
            cout << query(1, 1, N) << endl;
        } else {
            reverse(1, 1, N);
        }
        print();
    }
    return 0;
}
