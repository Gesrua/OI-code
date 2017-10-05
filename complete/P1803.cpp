#include <iostream>
#include <algorithm>
struct cell {
    int start, end;
} a[100001];
int n;
bool cmp(cell a,cell b){
    return a.end < b.end;
}
int main(){
    using namespace std;
    cin >> n;
    int i, ans = 1, t;
    for (i=1; i<=n; i++) cin >> a[i].start >>  a[i].end;
    sort(a+1,a+1+n,cmp);
    t = a[1].end;
    for (i=2; i<=n; i++) {
        if (a[i].start >= t) {
            ans++;
            t = a[i].end;
        }
    }
    cout << ans;
    return 0;
}
