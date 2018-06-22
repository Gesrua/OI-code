#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::scanf;
int N, M, book[40002];
struct node
{
	int u, v, c;
} A[100001];
inline bool cmp(node a, node b){
	return a.c > b.c;
}
int f(int x){
	if (book[x] != x) book[x] = f(book[x]);
	return book[x];
}
int main(){
	scanf("%d%d", &N, &M);
	int i;
	for (i = 0; i < M; ++i)
		scanf("%d%d%d", &A[i].u, &A[i].v, &A[i].c);
	std::sort(A,A + M,cmp);
	for (i = 1; i <= N * 2; ++i)
		book[i] = i;
	for (i = 0; i < M; ++i){
		int u = A[i].u, v = A[i].v;
		if (f(u) == f(v)){
			cout << A[i].c;
			return 0;
		}
		book[f(u + N)] = f(v);
		book[f(v + N)] = f(u);
		//for (int j=1;j<=N*2;++j)
		//	cout << book[j] << ' ';
		//cout << endl;
	}
	cout << 0;
	return 0;
}
