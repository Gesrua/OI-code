#include <iostream>
#include <algorithm>
#include <iomanip>
struct cell {
    int num, t;
} a[1001];
bool cmp(struct cell a, struct cell b){
    if (a.t != b.t) return a.t < b.t;
    else return a.num < b.num;
}
int main(){
    using namespace std;
    int n, i;
    cin >> n;
    for (i=1; i<=n; i++)
        cin >> a[a[i].num = i].t;
    sort(a+1,a+1+n,cmp);
    double ans = 0;
    for (i=1; i<=n; i++) {
        cout << a[i].num << ' ';
        ans += a[i].t * (n-i);
    }
    cout << endl << fixed << setprecision(2) << (ans / n);
    return 0;
}
