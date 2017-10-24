#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
unsigned int N, R, Q;
struct cell
{
	unsigned int n, s, w;
}A[200003], B[100001], C[100001];
bool cmp(cell a, cell b){
	if (a.s != b.s) return a.s > b.s;
	return a.n < b.n;
}
int main(){
	std::ios::sync_with_stdio(false);
	cin >> N >> R >> Q;
	unsigned int i, j, k ,l;
	unsigned n = N<<1;
	for (i=1;i<=n;++i){
		A[i].n = i;
		cin >> A[i].s;
	}
	for (i=1;i<=n;++i){
		cin >> A[i].w;
	}
	std::sort(A+1,A+1+n,cmp);
	for (i=0;i<R;i++){
		for (j=1,k=1;j<n;j+=2,++k){
			if (A[j].w > A[j+1].w){
				B[k] = A[j];
				++B[k].s;
				C[k] = A[j+1];
			}
			else{
				B[k] = A[j+1];
				++B[k].s;
				C[k] = A[j];
			}
		}
		//std::merge(B+1,B+1+N,C+1,C+1+N,A+1,cmp);

		for (j=1,k=1,l=1;l<=n && j<=N && k<=N;l+=1){
			if (cmp(B[j], C[k])){
				A[l] = B[j];
				++j;
			}
			else{
				A[l] = C[k];
				++k;
			}
		}
		while (j<=N){
			A[l] = B[j];
			++j;
			++l;
		}
		while (k<=N){
			A[l] = C[k];
			++l;
			++k;
		}

	}
	cout << A[Q].n;
	return 0;
}