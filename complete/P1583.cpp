#include <iostream>
#include <algorithm>
struct cell {
    int w, d, n;
};
bool cmp1(struct cell a, struct cell b){
    return a.w > b.w;
}
bool cmp(struct cell a, struct cell b){
    if (a.w != b.w) {
        return a.w > b.w;
    }
    else return a.n < b.n;
}
int main(){
    using namespace std;
    struct cell a[20001];
    int n, k, i;
    int e[11];
    cin >> n >>k;
    for (i=1; i<=10; i++) cin >> e[i];
    for (i=1; i<=n; i++) {
        cin >> a[i].w;
        a[i].n = i;
    }
    sort(a+1,a+1+n,cmp);
    for (i=1; i<=n; i++) {
        a[i].w += e[(i - 1) % 10 + 1];
    }
    sort(a+1,a+1+n,cmp);
    for (i=1; i<=k; i++)
        cout << a[i].n << ' ';
    return 0;
}
