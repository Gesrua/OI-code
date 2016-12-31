#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
int n,m,a[20][20],max_sum,max_ans[20],stack[20];
using namespace std;
void dfs(int cur,int num,int sum)
{
    if (cur == n) {
        int temp = sum+a[cur][m - num];
        if (temp > max_sum)
        {
            max_sum = temp;
            stack[cur] = m - num;
            memcpy(max_ans,stack,sizeof(max_ans));
        }
        return;
    }
    //num--;
    for (int i = 0;i <= m - num;i++)
    {
        stack[cur] = i;
        dfs(cur+1,num+i,sum+a[cur][i]);
    }
}
int main()
{
    memset(a,0,sizeof(a));
    ios::sync_with_stdio(false);
		cin>>n>>m;
		int i,j;
		for (i=1;i<=n;i++)
			  for (j=1;j<=m;j++)
			    	cin>>a[i][j];
		dfs(1,0,0);
    cout<<max_sum<<endl;
    for (i=1;i<=n;i++)
        cout<<i<<' '<<max_ans[i]<<endl;
    return 0;
}
