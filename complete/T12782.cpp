#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
//const int N = 2001;
const int N = 2000001;
struct node
{
    int left, right, idx;
}tree[N];
int size[N], root, ans = 0, n;
std::stack<int> s;
void insert(int x){
    int t = -1;
    while (tree[s.top()].idx < tree[x].idx){
        t = s.top();
        s.pop();
    }
    tree[s.top()].right = x;
    s.push(x);
    tree[x].left = t;
}
inline int trans(int x){
    if (x < 0) return 0;
    return x;
}
int dfs(int x){
    if (x == -1) return 0;
    size[x] = dfs(tree[x].left) + dfs(tree[x].right) + 1;

    if (size[trans(tree[x].right)]%3 == 0 &&
        size[trans(tree[x].left)]%3 == 0 && 
        (n-size[trans(tree[x].right)]-size[trans(tree[x].left)]-1)%3 == 0) ++ans;
    return size[x];
    // return size[x] = dfs(tree[x].left) + dfs(tree[x].right) + 1;
}
int main(){
    std::ios::sync_with_stdio(false);
    int t, i;
    cin >> n;
    tree[0].idx = 2100000000;
    size[0] = 0;
    s.push(0);
    for (i=1;i<=n;++i){
        cin >> tree[i].idx;
        tree[i].left = tree[i].right = -1;
        insert(i);
    }
    root = tree[0].right;
    dfs(root);
    cout << ans;
    return 0;
}