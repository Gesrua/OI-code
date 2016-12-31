#include <iostream>
using namespace std;
int a[10],n,cost[1000]={6,2,5,5,4,5,6,3,7,6};
void init()
{
	cin>>n;
	int i;
	//a[1] = 2; a[2] = 5; a[3] = 5; a[4] = 4; a[5] = 5; a[6] = 6; a[7] = 3; a[8] = 7; a[9] = 6;
	for (i=10;i<=1000;i++)
	{
		cost[i] = cost[i % 10] + cost[i / 10];
		//cout<<i<<' '<<cost[i]<<endl;
	}
}
int main()
{
	init();
	n = n - 4;
	int i,j,sum;
	sum = 0;
	
	for (i=0;i<=1000;i++)
		for (j=0;j<=1000;j++)
			if ((cost[i] + cost[j] + cost[i+j] == n) && (i+j<=1000))
			{
				//cout<<i<<'+'<<j<<'='<<i+j<<endl;
				sum++;
			}
	// */
	cout<<sum;
	return 0;
}
