#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
int t[101], dp[101][231][2], n, ans=200;
int solve(int x, int max,bool dir){
    if (x == n){
        return 0;
    }
    if (dp[x][max][dir]!=-1) return dp[x][max][dir];
    int& ans = dp[x][max][dir];
    if (dir){
        if (t[x+1] < max) return ans = std::min(solve(x+1,max,true)+1,solve(x+1,t[x+1],false));
        if (t[x+1] > max) return ans = std::min(std::min(solve(x+1,t[x+1],true),solve(x+1,max,true)+1), solve(x+1,t[x+1],false));
        return ans = solve(x+1,max,true)+1; // t[x+1] == max
    }else{
        if (t[x+1] < max) return ans = std::min(solve(x+1,t[x+1],false),solve(x+1,max,false)+1);
        if (t[x+1] >= max) return ans = solve(x+1,max,false)+1;
    }
}
int main(){
    std::memset(dp, -1, sizeof(dp));
    int i;
    cin >> n;
    for (i=1;i<=n;++i)
        cin >> t[i];
    cout << solve(0,0,true);
    return 0;
}
