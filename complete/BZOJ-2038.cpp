#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
#define rep(i, l, r) for (int i = (l); i < (r); ++i)
#define repp(i, l, r) for (int i = (l); i <= (r); ++i)

const int N = 50009;
const int M = 50009;

int color[N];
int cnt[N];
int n, m, size;

long long gcd(const long long a, const long long b) { return !b ? a : gcd(b, a % b); }

struct n1 {
    int l, r, id;
    long long ans;
} ask[M], prev;

n1* a = ask;

inline bool cmp_block(const n1& a, const n1& b) {
    int k1 = a.l / size, k2 = b.l / size;
    return (k1 == k2) ? (a.r < b.r) : (k1 < k2);
}

inline bool cmp_id(const n1& a, const n1& b) { return a.id < b.id; }

void print_cnt() {
    repp(i, 1, n) { cout << cnt[i] << ' '; }
    cout << endl;
}

int main() {
    //	freopen("input.txt", "r", stdin);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    rep(i, 0, n) { cin >> color[i]; }
    rep(i, 0, m) {
        cin >> ask[i].l >> ask[i].r;
        --ask[i].l;
        --ask[i].r;
        ask[i].id = i;
    }

    size = std::sqrt(n);
    std::sort(ask, ask + m, cmp_block);

    //	rep (i, 0, m){
    //		cout << a[i].l << ' ' << a[i].r << endl;
    //	}

    // cut

    rep(i, 0, m) {
        int l = i, k = a[i].l / size, r;
        for (r = i; r < m - 1 && a[r + 1].l / size == k; ++r)
            ;
        // [l, r]
        std::memset(cnt, 0, sizeof(cnt));

        // first O(length)

        repp(j, a[l].l, a[l].r) {
            a[l].ans += 2 * cnt[color[j]];
            cnt[color[j]]++;
        }

        //		cout << "new block " << a[l].ans << endl;
        //		print_cnt();

        prev.l = a[l].l, prev.r = a[l].r;
        prev.ans = a[l].ans;

        repp(j, l + 1, r) {
            // l
            a[j].ans = prev.ans;
            if (a[j].l < prev.l) {
                rep(k, a[j].l, prev.l) {
                    a[j].ans += 2 * cnt[color[k]];
                    cnt[color[k]]++;
                }
            }
            if (a[j].l > prev.l) {
                rep(k, prev.l, a[j].l) {
                    cnt[color[k]]--;
                    a[j].ans -= 2 * cnt[color[k]];
                }
            }

            // r
            repp(k, prev.r + 1, a[j].r) {
                a[j].ans += 2 * cnt[color[k]];
                cnt[color[k]]++;
            }
            prev.l = a[j].l, prev.r = a[j].r;
            prev.ans = a[j].ans;

            //			cout << "next ask" << ' ' << prev.ans << endl;
            //			print_cnt();
        }
        i = r;
    }

    std::sort(ask, ask + m, cmp_id);

    //	rep (i, 0, m){
    //		cout << a[i].l << ' ' << a[i].r << ' ' << a[i].ans << endl;
    //	}
    rep(i, 0, m) {
        long long len = ask[i].r - ask[i].l + 1;
        long long all = (len - 1) * len, g = gcd(all, a[i].ans);
        //		cout << a[i].ans << '\\' << all << endl;
        cout << a[i].ans / g << '/' << all / g << endl;
    }
    return 0;
}
