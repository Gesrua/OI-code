#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n,s,a,b,sum,x[5010] = {0},cur = 0;
void init()
{
	//memset(x,0,sizeof(x));
	int temp;
	cin >> n >> s;
	cin >> a >> b;
	cur = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		if (temp > a + b) cin >> temp;
		else cin >> x[cur++];
	}
	//for (int i=0;i<n;i++) cout<<x[i]<<' ';
}
void solve()
{
	n = cur - 1;
	cur = 0;
	sum = 0;
	sort(x,x + n + 1);
	while (cur <= n)
	{
		s = s - x[cur];
		if (s >= 0) sum++;
		if (s < 0) break;
		cur++;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	init();
	solve();
	cout << sum;
	return 0;
}
