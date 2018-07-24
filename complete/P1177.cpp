#include <iostream>
void qsort(int l,int r);
int a[100001];
int main(){
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
	qsort(0,n - 1);
	for (int i = 0; i < n; i++)
		std::cout << a[i] << ' ';
}
void qsort(int l,int r){
	if (l >= r) return;
	//std::cout<<l<<' '<<r<<std::endl;
	int i = l,j = r,t,flag = a[(l + r) / 2];
	while (i <= j){
		while (a[i] < flag) i++;
		while (a[j] > flag) j--;
		if (i <= j){
			t = a[i];
			a[i] = a[j];
			a[j] = t;
			i++; j--;
		}
	}
	qsort(l,j);
	qsort(i,r);
	return;
}