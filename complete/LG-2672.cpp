#include <bits/stdc++.h>
int tot = 0, n, heap[100001] = {};
int now = 0, before = 0, pos = 0;
struct cell {
    bool flag;
    int s, a;
} a[100001];
void init() {
    using namespace std;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].s;
    for (int i = 0; i < n; i++) cin >> a[i].a;
}
void del();
void siftup(int x);
void siftdown(int x);
void push(int x);
int main() {
    std::ios::sync_with_stdio(false);
    int t, c, ans = 0, j, i;
    init();
    for (j = 0; j < n; j++) {
        t = 0;
        for (i = pos; i < n; i++)
            if ((t < a[i].a + (a[i].s - now) * 2) && !a[i].flag) {
                t = a[i].a + (a[i].s - now) * 2;
                c = i;
            }
        if (heap[1] >= t) {
            ans += heap[1];
            del();
        } else {
            a[c].flag = true;
            ans += t;
            for (i = pos; (a[i].s <= a[c].s) && (i < n); i++) {
                if (!a[i].flag) push(a[i].a);
            }
            pos = i;
            now = a[c].s;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
void del() {
    heap[1] = heap[tot];
    tot--;
    siftdown(1);
}
void push(int x) {
    tot++;
    heap[tot] = x;
    siftup(tot);
}
void siftdown(int x) {
    for (int i = x, j = i << 1; j <= tot; i = j, j = i << 1) {
        if ((j + 1 <= tot) && (heap[j + 1] > heap[j])) j++;
        if (heap[i] > heap[j]) break;
        std::swap(heap[i], heap[j]);
    }
}
void siftup(int x) {
    for (int i = x, j = i >> 1; j; i = j, j = i >> 1)
        if (heap[j] < heap[i]) std::swap(heap[j], heap[i]);
}
