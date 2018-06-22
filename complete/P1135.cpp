#include <iostream>
#include <cstring>
using namespace std;
const int maxv = 1000000000;
int a[201][201],n,x,y;
bool book[201];
void print()
{
	int i,j;
	for (i = 1; i <= n; i++){
		for (j = 1; j <= n; j++)
			cout << a[i][j] << ' ';
		cout << endl;
	}
}
int main()
{
	int i,j,t,mini,k;
	memset(book,1,sizeof(book));
	cin >> n >> x >> y;
	for (i = 0; i <= n; i++)
		for (j = 0; j <= n; j++)
			a[i][j] = maxv;
	for (i = 1; i <= n; i++){
		cin >> t;
		a[i][i] = 0;
		if (i - t > 0) a[i][i - t] = 1;
		if (i + t <= n) a[i][i + t] = 1;
	}
	book[x] = false;
	for (i = 1; i <= n; i++){
		mini = 2100000000;
		for (j = 1; j <= n; j++)
			if (book[j] && mini > a[x][j]){
				mini = a[x][j];
				k = j;
			}
		book[k] = false;
		for (j = 1; j <= n; j++)
			if (book[j] && a[x][k] + a[k][j] < a[x][j])
				a[x][j] = a[x][k] + a[k][j];
	}
	//print();
	if (a[x][y] == maxv) cout << "-1";
	else cout << a[x][y];
	return 0;
}
