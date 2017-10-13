#include <bits/stdc++.h>
int heap[100000], tot = 0;
void siftup(){
    for (int i=tot,j=i>>1;j;i=j, j=i>>1)
        if (heap[j] > heap[i]) std::swap(heap[j], heap[i]);
}
void siftdown(){
    for (int i=1, j=i<<1;j<=tot;i=j, j=i<<1){
        if ((j+1 <= tot) && (heap[j+1] < heap[j])) j++;
        if (heap[j] > heap[i]) break;
        std::swap(heap[j], heap[i]);
    }
}
int main(){
	int i, n, m;
    std::ios::sync_with_stdio(0);
	std::cin >> n;
	for (i=1; i<=n; i++) {
		std::cin >> m;
		if (m == 1) {
			std::cin >> heap[++tot];
			siftup();
		}
		else if (m == 2) {
			std::cout << heap[1] << std::endl;
		}
		else if (m == 3) {
			heap[1] = heap[tot--];
			siftdown();
		}
	}
	return 0;
}
