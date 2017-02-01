#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int x,t=0,ans=1,i,j,n,last;
	cin>>n;
	cin>>last;
	for (i=1;i<n;i++) {
		cin>>x;
		if (x-1==last) t++;
		else {
			if (ans<t) ans = t;
			t = 1;
		}
		if (ans<t) ans = t;
		last = x;
	}
	cout<<ans;
	return 0;
}
