#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
int n;
std::string ans;
int stack[30]={}, top=0;
std::string a[30];
bool book[30]={};
void dfs(int k){
    if (k == n){
        std::string s;
        for (int i=1;i<=top;++i)
            s = s + a[stack[i]];
        if (s > ans) ans = s;
        return;
    }
    int max=0;
    int i;
    for (i=1;i<=n;++i){
        if (book[i]) continue;
        if (a[max] < a[i] || max==0) max = i;
    }
    for (i=1;i<=n;++i){
        if (book[i]) continue;
        if (a[max].substr(0, std::min(a[i].size(), a[max].size())) == a[i].substr(0, std::min(a[i].size(), a[max].size()))){
            book[i] = true;
            stack[++top]  = i;
            dfs(k+1);
            top--;
            book[i] = false;
        }
    }
}
int main(){
    cin >> n;
    int i;
    std::string s;
    for (i=1;i<=n;++i){
        cin >> a[i];
    }
    dfs(0);
    cout << ans;
    return 0;
}
