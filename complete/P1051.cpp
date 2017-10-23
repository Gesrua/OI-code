#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
struct cell{
    std::string n;
    int sum;
}s[101];
bool cmp(cell a,cell b){
    return a.sum > b.sum;
}
int main(){
    int n, a, b, e, ans=0;
    char c, d;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> s[i].n;
        cin >> a >> b >> c >> d >> e;
        s[i].sum = 0;
        if (a>80 && e>=1)   s[i].sum += 8000;
        if (a>85 && b>80)   s[i].sum += 4000;
        if (a>90)           s[i].sum += 2000;
        if (a>85 && d=='Y') s[i].sum += 1000;
        if (b>80 && c=='Y') s[i].sum += 850;
        ans += s[i].sum;
    }
    std::stable_sort(s,s+n,cmp);
    cout << s[0].n << endl << s[0].sum << endl << ans;
    return 0;
}
