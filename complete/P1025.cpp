#include <iostream>
using namespace std;
int n,k,ans=0;
void solve(int now,int sum,int last)
{
	if (now == 1) {
		if (sum == n) ans++;
	}
	else
	{
		now--;
		int i=last;
		if (i==0) i=1;
		for (i=i;i<=n-sum;i++)
			solve(now,sum+i,i);
	}
}
int main()
{
	cin>>n>>k;
	k++;
	solve(k,0,0);
	cout<<ans;
	return 0;
}
