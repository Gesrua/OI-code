#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    if (n>30)
    {
        cout<<'0';
        return 0;
    }
    int ans[100000][10],cur;
    cur=0;
    for (int i1=1; i1<=3; i1++)
        for (int i2=1; i2<=3; i2++)
            for (int i3=1; i3<=3; i3++)
                for (int i4=1; i4<=3; i4++)
                    for (int i5=1; i5<=3; i5++)
                        for (int i6=1; i6<=3; i6++)
                            for (int i7=1; i7<=3; i7++)
                                for (int i8=1; i8<=3; i8++)
                                    for (int i9=1; i9<=3; i9++)
                                        for (int i10=1; i10<=3; i10++)
                                            if (i1+i2+i3+i4+i5+i6+i7+i8+i9+i10 == n)
                                            {
                                                ans[cur][0]=i1;
                                                ans[cur][1]=i2;
                                                ans[cur][2]=i3;
                                                ans[cur][3]=i4;
                                                ans[cur][4]=i5;
                                                ans[cur][5]=i6;
                                                ans[cur][6]=i7;
                                                ans[cur][7]=i8;
                                                ans[cur][8]=i9;
                                                ans[cur][9]=i10;
                                                cur++;
                                                //if (cur==10) goto yes;
                                            }
    cout<<cur<<endl;
    int i,j;
    for (i=0; i<cur; i++)
    {
        for (j=0; j<10; j++)
            cout<<ans[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
