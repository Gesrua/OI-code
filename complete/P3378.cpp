#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
int tree[1000001], tot = 0;
void siftup(){
    for (int i=tot, j=i>>1; j>=1; i=j, j=i>>1){
        if (tree[j] > tree[i]) std::swap(tree[j], tree[i]);
    }
}
void siftdown(){
    for (int i=1, j=i<<1; j<=tot; i=j, j=i<<1){
        if (j+1 <= tot && tree[j] > tree[j+1]) ++j;
        if (tree[i] > tree[j]) std::swap(tree[i], tree[j]);
        else break;
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    int n, x;
    cin >> n;
    for (int i=0; i<n; ++i){
        cin >> x;
        if (x == 1){
            cin >> x;
            tree[++tot] = x;
            siftup();
            continue;
        }
        if (x == 2){
            cout << tree[1] << endl;
            continue;
        }
        if (x == 3){
            tree[1] = tree[tot--];
            siftdown();
        }
    }
    return 0;
}
