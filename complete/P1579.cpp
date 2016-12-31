#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int n,j,i,temp,ans=0;//sum=0;
	bool book[20001];
	ios::sync_with_stdio(false);
	cin>>n;
	memset(book,1,sizeof(book));
	book[0] = book[1] = false;
	for (i=2;i<=10000;i++)
	{
		j = 2;
		while (true)
		{
			temp = j * i;
			j++;
			if (temp>20000) break;
			book[temp] = false;
		}
	}
	//for (i=1;i<=100;i++) if (book[i]) cout<<i<<' ';
	for (i=2;i<=n-3;i=i+2)
	{
		for (j=2;j<=n-3;j=j+2)
		{
			//if(book[i] && book[j] && book[n - i - j] && ans==1) {cout<<i<<' '<<j<<' '<<n-i-j; return 0;}
			if(book[i] && book[j] && book[n - i - j] && ans==0) {cout<<i<<' '<<j<<' '<<n-i-j<<endl; ans++;}
			if(j==2) j=1;
			//if(book[i] && book[j] && book[n - i - j] && ans==1) {cout<<i<<' '<<j<<' '<<n-i-j; return 0;}
		}
		if (ans==1) return 0;
		if(i==2) i=1; 
	}
	return 0;
}
