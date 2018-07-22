#include <bits/stdc++.h>
#define INF 2100000000
int n, a[50000], ans = 0;
void merge(int l, int mid, int r){
	int i, j, k, ll = mid - l + 1, lr = r - mid, ar[20001], al[20001];
	for (i = 1; i <= ll; i++) al[i] = a[l + i - 1];
	al[i] = INF;
	for (i = 1; i <= lr; i++) ar[i] = a[mid + i];
	ar[i] = INF;
	for (i = 1,j = 1,k = l; k <= r; k++){
		if (al[i] <= ar[j]){
			a[k] = al[i];
			i++;
		}
		else{
			ans += ll - i + 1;
			a[k] = ar[j];
			j++;
		}
	}
}
void mergeSort(int l, int r){
	if (l < r){
		int mid = (l + r) / 2;
		mergeSort(l,mid);
		mergeSort(mid + 1, r);
		merge(l, mid, r);
	}
}
int main(){
	std::cin >> n;
	for (int i = 1; i <= n; i++)
		std::cin >> a[i];
	mergeSort(1, n);
	std::cout << ans;
	return 0;
}
