#include <iostream>
using std::cin; using std::cout; using std::cerr; using std::endl;
const int s_a[5][5] = {
    {0, 0, 1, 1, 0},
    {1, 0, 0, 1, 0},
    {0, 1, 0, 0, 1},
    {0, 0, 1, 0, 1},
    {1, 1, 0, 0, 0}
};
const int s_b[5][5] = {
    {0, 1, 0, 0, 1},
    {0, 0, 1, 0, 1},
    {1, 0, 0, 1, 0},
    {1, 1, 0, 0, 0},
    {0, 0, 1, 1, 0}
};
int main(){
    int n, ta, tb, a[210], b[210];
    std::ios::sync_with_stdio(false);
    cin >> n >> ta >> tb;
    for (int i = 1; i <= ta; ++i){
        cin >> a[i];
    }
    a[0] = a[ta];
    // for (int i = 1; i <= n; ++i){
    //     cerr << a[i] << ' ';
    // }
    // cerr << endl;
    for (int i = ta + 1; i <= n; ++i){
        a[i] = a[i%ta];
    }
    for (int i = 1; i <= tb; ++i){
        cin >> b[i];
    }
    b[0] = b[tb];
    for (int i = tb + 1; i <= n; ++i){
        b[i] = b[i%tb];
    }
    // for (int i = 1; i <= n; ++i){
    //     cerr << b[i] << ' ';
    // }
    // cerr << endl;
    int ansa = 0, ansb = 0;
    for (int i = 1; i <= n; ++i){
        ansa += s_a[a[i]][b[i]];
        ansb += s_b[a[i]][b[i]];
    }
    cout << ansa << ' ' << ansb;
    return 0;
}