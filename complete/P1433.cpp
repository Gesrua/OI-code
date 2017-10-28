#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
struct node {
    double x, y;
}P[20];
int n;
bool vis[20]={};
double G[16][16]={}, ANS=2100000000;
void solve(int k, double dis){
    int i;
    if (dis >= ANS) return;
    bool flag=true;
    for (i=1;i<=n;++i){
        if (!vis[i]){
            flag = false;
            vis[i] = true;
            solve(i, dis+G[k][i]);
            vis[i] = false;
        }
    }
    if (flag) ANS = std::min(ANS, dis);
    return;
}
int main(){
    int i, j, k;
    std::scanf("%d", &n);
    for (i=1;i<=n;++i)
        //cin >> P[i].x >> P[i].y;
        std::scanf("%lf%lf", &P[i].x, &P[i].y);
    for (i=1;i<=n;++i){
        for (j=1;j<=n;++j){
            if (i != j)
                G[i][j] = G[j][i] = std::sqrt(std::pow((P[i].x-P[j].x),2)+std::pow((P[i].y-P[j].y),2));
            //cout << G[i][j] << ' ';
        }
        //cout << endl;
    }

    for (i=1;i<=n;++i){
        vis[i] = true;
        solve(i, std::sqrt(std::pow(P[i].x,2)+std::pow(P[i].y,2)));
        vis[i] = false;
    }
    //cout << ANS;
    std::printf("%0.2f", ANS);
    return 0;
}
