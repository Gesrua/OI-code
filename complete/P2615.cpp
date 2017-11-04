#include <cstdio>
struct node {
    int x, y;
}p[1600];
int n, ans[50][50] = {};
int main(){
    std::scanf("%d", &n);
    p[1].x = 1;
    p[1].y = (n+1)/2;
    ans[p[1].x][p[1].y] = 1;
    int lim = n*n;
    for (int i=2; i<=lim; ++i){
        if (p[i-1].x == 1 && p[i-1].y < n){
            p[i].x = n;
            p[i].y = p[i-1].y+1;
            ans[p[i].x][p[i].y] = i;
            continue;
        }
        if (p[i-1].x != 1 && p[i-1].y == n){
            p[i].x = p[i-1].x - 1;
            p[i].y = 1;
            ans[p[i].x][p[i].y] = i;
            continue;
        }
        if (p[i-1].x == 1 && p[i-1].y == n){
            p[i].x = 2;
            p[i].y = n;
            ans[p[i].x][p[i].y] = i;
            continue;
        }
        if (ans[p[i-1].x-1][p[i-1].y+1] == 0){
            p[i].x = p[i-1].x - 1;
            p[i].y = p[i-1].y + 1;
            ans[p[i].x][p[i].y] = i;
            continue;
        }
        p[i].x = p[i-1].x + 1;
        p[i].y = p[i-1].y;
        ans[p[i].x][p[i].y] = i;
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j)
            std::printf("%d ", ans[i][j]);
        std::printf("\n");
    }
    return 0;
}
