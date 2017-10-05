#include <iostream>
#include <algorithm>
#include <cstring>
struct node {
    long long a,b,c;
} data[51];
bool cmp(node x, node y) {
    return x.c * y.b < y.c * x.b;
}
long long dp[51][200001];
long long caculate(struct node a,long long t) {
    return a.a - (t + a.c) * a.b;
}
long long T,n;
long long max(long long a,long long b) {
    if (a>b) return a;
    else return b;
}
void solve(long long s,long long t) {
    if (dp[s][t] != -1) return;
    if (t > T) {dp[s][t] = 0; return;}
    /*
       if (s == n && t+data[s].c <= T) {dp[s][t] = max(caculate(data[s],t),0); return;}
       if (s == n) {dp[s][t] = 0;return;}
     */
    if (s==n) {
        if (t+data[s].c <= T) {dp[s][t] = max(caculate(data[s],t),0); return;}
        else {dp[s][t] = 0; return;}
    }
    solve(s+1,t+data[s].c);
    solve(s+1,t);
    if (t + data[s].c <= T)
        dp[s][t] = max(dp[s+1][t],dp[s+1][t+data[s].c]+caculate(data[s],t));
    else dp[s][t] = max(dp[s+1][t],dp[s+1][t+data[s].c]);
}
int main() {
    long long i;
    std::memset(dp,-1,sizeof(dp));
    std::cin>>T>>n;
    for (i=0; i<n; i++) std::cin>>data[i].a;
    for (i=0; i<n; i++) std::cin>>data[i].b;
    for (i=0; i<n; i++) std::cin>>data[i].c;
    std::sort(data,data+n,cmp);
    solve(0,0);
    std::cout<<dp[0][0];
    return 0;
}
