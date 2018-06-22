#include <iostream>
#include <cstring>
using namespace std;
long long a[24][24];
int i,j,m,n,temp_x,temp_y,x,y;
void print(){
	int i,j;
	for (i = 0; i < 24; i++)
	{
		for (j = 0; j < 24; j++)
			cout << a[i][j] << ' ';
		cout << endl;
	}
	return;
}
void horse(int i,int j){
	if ((i > -1) && (i < 24) && (j > -1) && (j < 24)) a[i][j] = -1;
	return;
}
int main(){
	for (i = 0; i < 24; i++)
		for (j = 1; j < 24; j++)
			a[i][j] = 0;
	int temp;
	cin >> m >> n >> temp_x >> temp_y;
	for (i = 0; i < 2; i++)
		for (j = 0; j < 24; j++) a[i][j] = -1;
	for (j = 0; j < 2; j++)
		for (i = 0; i < 24; i++) a[i][j] = -1;
	a[2][2] = 1;
	temp_x = temp_x + 2;
	temp_y = temp_y + 2;
	horse(temp_x,temp_y);
	horse(temp_x + 1,temp_y - 2);
	horse(temp_x + 1,temp_y + 2);
	horse(temp_x + 2,temp_y - 1);
	horse(temp_x + 2,temp_y + 1);
	horse(temp_x - 1,temp_y - 2);
	horse(temp_x - 1,temp_y + 2);
	horse(temp_x - 2,temp_y - 1);
	horse(temp_x - 2,temp_y + 1);
	m = m + 2; n = n + 2;
	for (i = 2; i <= m; i++)
		for (j = 2; j <= n; j++)
		{
			temp = 0;
			if (a[i - 1][j] == -1) temp = 1;
			if (a[i][j - 1] == -1) temp = temp + 1;
			if ((a[i][j] != -1) && (a[i][j] == 0)) a[i][j] = a[i - 1][j] + a[i][j - 1] + temp;
		}
	//print();
	cout << a[m][n];
	return 0;
}
