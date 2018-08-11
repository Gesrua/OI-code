#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>
char s[50000001]; int stl = 0;
using std::min; using std::cin; using std::cerr; using std::cout; using std::endl; using std::isdigit; using std::pair; using std::make_pair;
extern inline void rd(int &x){
    x = 0;
    for (; !isdigit(s[stl]); ++stl);
    int f = 1;
    if (s[stl-1] == '-') f = -1;
    for (; isdigit(s[stl]); ++stl) x = (x << 3) + (x << 1) + s[stl] - '0';
    x *= f;
}
int cnt = 1;
typedef pair < int, int > pii;
struct node{
    int l, r, w;
    node *lson, *rson;
}t[15000000];
node* his[1000010];
int v, opt, loc, val;
void build(node* cur){
    if (cur->l == cur->r){
        // cur->w = a[cur->l];
        rd(cur->w);
        return;
    }
    int mid = (cur->l + cur->r)>>1;
    t[cnt].l = cur->l,
    t[cnt].r = mid,
    cur->lson = &t[cnt],
    ++cnt;
    t[cnt].l = mid+1,
    t[cnt].r = cur->r,
    cur->rson = &t[cnt],
    ++cnt;
    build(cur->lson);
    build(cur->rson);
}
node* modify(node* old){
    node* newroot = &t[cnt];
    node* cur = &t[cnt++];
    while (old->l != old->r){
        cur->l = old->l, cur->r = old->r,
        cur->lson = old->lson, cur->rson = old->rson;
        if (loc <= old->lson->r)
            cur->lson = &t[cnt],
            old = old->lson,
            cur = &t[cnt++];
        else
            cur->rson = &t[cnt],
            old = old->rson,
            cur = &t[cnt++];
    }
    cur->l = loc, cur->r = loc, cur->w = val;
    return newroot;
}
void query(node* cur){
    if (cur->l == cur->r){
        printf("%d\n", cur->w);
        return;
    }
    if (loc <= cur->lson->r)
        query(cur->lson);
    else
        query(cur->rson);
}
int main(){
    int n, m;
    fread(s, 50000000, 1, stdin);
    rd(n); rd(m);
    // for (int i = 1; i <= n; ++i)
    //     rd(a[i]);
    his[0] = &t[0];
    t[0].l = 1, t[0].r = n;
    build(&t[0]);
    // cerr << "Build Over\n";
    for (int i = 1; i <= m; ++i){
        rd(v); rd(opt); rd(loc);
        if (opt == 1){
            rd(val);
            // cerr << "opt " << i << " begin\n";
            his[i] = modify(his[v]);
        }else{
            // cerr << "opt " << i << " begin\n";
            his[i] = his[v];
            query(his[v]);
        }
        // cerr << "opt " << i << " over\n";
    }
    return 0;
}