#include <cstdio>
#include <iostream>
#include <algorithm>
struct node{
    int u, v, w;
}edge[200001];
int fa[5001], n, m;
bool cmp(node a, node b){
    return a.w < b.w;
}
void init(){
    using namespace std;
    scanf("%d%d", &n, &m);
    for (int i=0;i<=n;++i){
        fa[i] = i;
    }
    for (int i=0; i<m; ++i){
        scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
    }
    sort(edge, edge+m, cmp);
}
int find(int x){
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
void unite(int a, int b){
    fa[find(a)] = find(b);
}
int cnt = 0, sum = 0;
void kruskal(){
    for (int i=0; i<m; ++i){
        if (find(edge[i].u) != find(edge[i].v)){
            unite(edge[i].u, edge[i].v);
            sum += edge[i].w;
            ++cnt;
        }
    }
}
int main(){
    init();
    kruskal();
    if (cnt+1 < n) std::cout << "orz";
    else std::cout << sum;
    return 0;
}
