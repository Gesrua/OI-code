#include <cstdio>
using std::scanf;
int main(){
    int n, m, opt, obj, s[1001] = {}, a[1001];
    bool vis[1001] = {};
    scanf("%d%d", &n, &m);
    for (int i=1;i<=n;++i){
        scanf("%d", &a[i]);
        ++s[a[i]];
    }
    for (int i=0;i<m;++i){
        scanf("%d%d", &opt, &obj);
        if (opt == 1){
            --s[obj];
        }
        if (opt == 2){
            printf("%d\n", s[obj]);
        }
    }
    return 0;
}
