#include <iostream>
#include <cstring>
int n,m,maxLine;
bool a[101][101];
void init() {
    using namespace std;
    int t,i,j,maxNumI=0,maxNumJ=0,lineNumI[101],lineNumJ[101];
    memset(lineNumI,0,sizeof(lineNumI));
    memset(lineNumJ,0,sizeof(lineNumJ));
    memset(a,0,sizeof(a));
    cin>>n>>m;
    for (i=0;i<n;i++) {
        for (j=0;j<m;j++) {
            cin>>t;
            if (t==1) {
                a[i][j] = true;
                lineNumI[i]++;
                lineNumJ[j]++;
            }
        }
        if (maxNumI < lineNumI[i]) maxNumI = lineNumI[i];
    }
    for (j=0;j<m;j++)
        if (maxNumJ < lineNumJ[j]) maxNumJ = lineNumJ[j];
    maxLine = maxNumI;
    if (maxLine > maxNumJ) maxLine = maxNumJ;
}
bool judge(int i,int j,int k) {
    int k1 = i + k - 1;
    int k2 = j + k - 1;
    int x,y;
    for (x=i;x<=k1;x++)
        for (y=j;y<=k2;y++)
            if (!a[x][y]) return false;
    return true;
}
int main() {
    init();
    int i,j,k;
    for (k=maxLine;k>=1;k--) {
        for (i=0;i<n;i++) {
            for (j=0;j<m;j++) {
                if (judge(i,j,k)) {
                    std::cout<<k;
                    return 0;
                }
            }
        }
    }
    return 0;
}
