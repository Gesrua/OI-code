#include <iostream>
#include <algorithm>
int main(){
    int i, w, n, ans = 0, a[30001] = {};
    using namespace std;
    cin >> w >> n;
    for (i=1; i<=n; i++) cin >> a[i];
    sort(a+1,a+1+n);
    int l = 1, r = n;
    while (l < r) {
        if (a[l] + a[r] > w) {
            r--;
        }
        else{
            ans++;
            l++;
            r--;
        }
    }
    cout << n-ans;
    return 0;
}
