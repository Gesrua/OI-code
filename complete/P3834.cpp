#include <cstdio>
#include <iostream>
#include <utility>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#define rep(i, l, r) for (int i = (l); i < (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cin; using std::cout; using std::cerr; using std::endl;
using std::make_pair; using std::pair;
typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned int ui;

const int N = 200100;

int n, m, a[N], c[N];

template <size_t SIZE>
struct MemoryPool{
    char buf[SIZE], *cur;
    MemoryPool() { cur = buf; }
    void *alloc(const int size){
        if (cur == buf + SIZE) return malloc(size);
        else{
            char *p = cur;
            cur += size;
            return p;
        }
    }
};

MemoryPool<(4 + 4 + 8 + 8 + 4) * N * 32> pool;

struct ChairmanTree{
    struct Node{
        Node* ls;
        Node* rs;
        int cnt, l, r;
        Node(int _l, int _r, Node* _ls = NULL, Node* _rs = NULL){
            l = _l, r = _r, ls = _ls, rs = _rs,
            cnt = (_ls?_ls->cnt:0) + (_rs?_rs->cnt:0);
        }
        Node(int _l, int _r, int _cnt){
            l = _l, r = _r, cnt = _cnt, ls = NULL, rs = NULL;
        }
        void pushdown(){
            int mid = (l + r)/2;
            if (!ls) ls = new (pool.alloc(sizeof(Node))) Node(l, mid);
            if (!rs) rs = new (pool.alloc(sizeof(Node))) Node(mid+1 , r);
        }
        Node* insert(int x){
            if (x < l || r < x) return this;
            else if (l == r && x == l) return new (pool.alloc(sizeof(Node))) Node(l, r, this->cnt+1);
            else{
                // const int mid = (l+r)/2;
                pushdown();
                return new (pool.alloc(sizeof(Node))) Node(l, r, ls->insert(x), rs->insert(x));
                // if (x <= mid) return new (pool.alloc(sizeof(Node))) Node(l, r, ls->insert(x), rs);
                // else return new (pool.alloc(sizeof(Node))) Node(l, r, ls, rs->insert(x));
            }
        }
        int rank(){
            return ls?ls->cnt:0;
        }
        void print(){
            cerr << l << ' ' << r << ' ' << cnt << endl;
            if (ls) ls->print();
            if (rs) rs->print();
        }
    } *root[N];
    int n;

    void build(const int a[], int n, int val){
        this->n  = val;
        root[0] = new (pool.alloc(sizeof(Node))) Node(0, val-1, 0);
        for(int i = 1; i <= n; ++i){
            root[i] = root[i-1]->insert(a[i-1]);
            // root[i]->print();
            // cerr << "------" << endl;
        }
    }
    int query(int _l, int _r, int k){
        Node *l = root[_l-1], *r = root[_r];
        int min = 0, max = n-1;
        while(min != max){
            l->pushdown(), r->pushdown();
            int rk = r->rank() - l->rank(), mid = (l->l + l->r)/2;
            // cerr << min << ' ' << max << ' ' << rk << endl;
            if (k <= rk) l = l->ls, r = r->ls, max = mid;
            else l = l->rs, r = r->rs, k -= rk, min = mid+1;
        }
        // cerr << "******" << endl;
        return min;
    }
}t;

int main(){
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n >> m;
    rep(i, 0, n){
        cin >> a[i];
        c[i] = a[i];
    }

    std::sort(c, c+n);
    int* end = std::unique(c, c+n);
    rep(i, 0, n) a[i] = std::lower_bound(c, end, a[i])-c;
    t.build(a, n, end - c);
    // cerr << "build over" << endl;
    rep(i, 0, m){
        int l, r, k;
        cin >> l >> r >> k;
        cout << c[t.query(l, r, k)] << endl;
    }
    return 0;
}