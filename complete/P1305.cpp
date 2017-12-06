#include <iostream>
struct node{
    int left, right;
}tree[256];
using std::cin;
using std::cout;
void write(int pos){
    if (pos == '*' || pos == 0 || pos == -1) return;
    cout << char(pos);
    write(tree[pos].left);
    write(tree[pos].right);
}
int main(){
    std::ios::sync_with_stdio(false);
    bool root[256] = {}, vis[256]={};
    int n;
    char a, b, c;
    for (int i=0; i<n; ++i){
        cin >> a >> b >> c;
        vis[a] = true;
        root[b] = true;
        root[c] = true;
        tree[a].left = b;
        tree[a].right = c;
    }
    int pos;
    for (int i=0; i<256; ++i){
        if (!root[i] && vis[i]){
            pos = i;
            break;
        }
    }
    write(pos);
    return 0;
}