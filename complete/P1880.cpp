#include <iostream>
#include <cstring>
using namespace std;
int a[202],n,sum[202][202],dpmax[202][202],dpmin[202][202];
int dp_min(int l,int r)
{
	//cout<<l<<' '<<r<<' ';
	if (dpmin[l][r] != -1) return dpmin[l][r];
	if (l == r) return dpmin[l][r] = 0;
	//if (dpmin[l][r]!=-1) return dpmin[l][r];
	int min = 2100000000;
	for (int i = l; i < r; i++)
		if (min > dp_min(l,i) + dp_min(i + 1,r)) min = dpmin[l][i] + dpmin[i + 1][r];
	return dpmin[l][r] = min + sum[l][r];
}
int dp_max(int l,int r)
{
	//cout<<l<<' '<<r<<' ';
	if (dpmax[l][r] != -1) return dpmax[l][r];
	if (l == r) return dpmax[l][r] = 0;
	//if (dpmax[l][r]!=-1) return dpmax[l][r];
	int max = 0;
	for (int i = l; i < r; i++)
		if (max < dp_max(l,i) + dp_max(i + 1,r)) max = dpmax[l][i] + dpmax[i + 1][r];
	return dpmax[l][r] = max + sum[l][r];
}
int main()
{
	memset(dpmax,-1,sizeof(dpmax));
	memset(dpmin,-1,sizeof(dpmin));
	int i,temp_max,temp_min,j,max = 0,min = 2100000000;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i + n] = a[i];
	}
	for (i = 1; i <= 2 * n; i++)
	{
		for (j = i; j <= 2 * n; j++)
		{
			sum[i][j] = sum[i][j - 1] + a[j];
			//cout<<i<<' '<<j<<' '<<sum[i][j]<<" / ";
		}
		//cout<<endl;
	}

	for (i = 1; i <= n; i++)
	{
		temp_max = dp_max(i,i + n - 1);
		temp_min = dp_min(i,i + n - 1);
		//cout<<endl;
		if (temp_max > max) max = temp_max;
		//cout<<temp_min<<' ';
		//cout<<endl<<i<<"end"<<endl;
		if (temp_min < min) min = temp_min;
	}
	cout << min << endl << max;
}
