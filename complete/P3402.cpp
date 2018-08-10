// luogu-judger-enable-o2
#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>
char s[30000001]; int stl = 0;
using std::cin; using std::cerr;using std::cout; using std::endl; using std::isdigit;
extern inline void rd(int &x){
    x = 0;
    for (; !isdigit(s[stl]); ++stl);
    int f = 1;
    if (s[stl-1] == '-') f = -1;
    for (; isdigit(s[stl]); ++stl) x = (x << 3) + (x << 1) + s[stl] - '0';
    x *= f;
}
extern inline int rd(){
    int x = 0;
    for (; !isdigit(s[stl]); ++stl);
    int f = 1;
    if (s[stl-1] == '-') f = -1;
    for (; isdigit(s[stl]); ++stl) x = (x << 3) + (x << 1) + s[stl] - '0';
    return x * f;
}
int cnt = 1, n;
struct node{
    int dep, l, r, fa;
    node *lson, *rson;
}t[4000100], goal;
node* his[200100];
void build(node* cur){
    if (cur->l == cur->r){
        cur->fa = cur->l,
        cur->dep = 0;
        return;
    }
    int mid = (cur->l + cur->r)>>1;
    t[cnt].l =  cur->l,
    t[cnt].r = mid,
    cur->lson = &t[cnt];
    ++cnt;
    t[cnt].l = mid+1,
    t[cnt].r = cur->r,
    cur->rson = &t[cnt];
    ++cnt;
    build(cur->lson);
    build(cur->rson);
}
extern inline node* query(node* cur, int s){
    int mid;
    while (cur->l != cur->r)
        mid = (cur->l + cur->r) >> 1,
        cur = (s<=mid) ? (cur->lson) : (cur->rson);
    return cur;
}
node* modify(node *cur){
    node* rtn = &t[cnt++];
    rtn->l = cur->l,
    rtn->r = cur->r,
    rtn->fa = cur->fa;
    if (cur->l == cur->r && cur->l == goal.l){
        rtn->fa = goal.fa;
        rtn->dep = goal.dep;
        return rtn;
    }
    int mid = (cur->l + cur->r) >> 1;
    if (goal.l <= mid)
        rtn->lson = modify(cur->lson),
        rtn->rson = cur->rson;
    else
        rtn->lson = cur->lson,
        rtn->rson = modify(cur->rson);
    return rtn;
}
inline node* find(node* root, node *x){
    while (x->l != x->fa) x = query(root , x->fa);
    return x;
}
node* merge(node* root, node* x, node* y){
    x = find(root, x), y = find(root, y);
    if (x == y) return root;
    if (x->dep == y->dep){
        goal.l = goal.r = y->l, // 修改 y
        goal.fa = x->l,
        root = modify(root);
        // return modify(root);
        goal.l = goal.r = x->l, // 修改 x
        goal.fa = x->l;
        goal.dep = x->dep+1;
        return modify(root);
    }
    if (x->dep < y->dep) std::swap(x, y);
    goal.l = goal.r = y->l, // 修改 y
    goal.fa = x->l;
    return modify(root);
}
int main(){
    int m;
    fread(s, 30000000, 1, stdin);
    rd(n); rd(m);
    t[0].l = 1, t[0].r = n;
    build(&t[0]);
    his[0] = &t[0];
    int x, y;
    for (int i = 1; i <= m; ++i){
        int opt;
        rd(opt);
        if (opt == 1)
            his[i] = merge(his[i-1], query(his[i-1], rd()), query(his[i-1], rd()));
        else if (opt == 2) his[i] = his[rd()];
        else{
            his[i] = his[i-1];
            if (find(his[i], query(his[i], rd())) == find(his[i], query(his[i], rd()))) puts("1");
            else puts("0");
        }
    }
    return 0;
}