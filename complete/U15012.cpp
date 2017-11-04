#include <bits/stdc++.h>
using std::scanf;
int n, m, k, a[100000], book[100000] = {};
std::map<int, int> map;
int main(){
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
        a[i] %= m;
        if (map.find(a[i]) == map.end()) map[a[i]] = 1;
        else ++map[a[i]];
    }
    for(auto i=map.begin(); i!=map.end(); ++i){
        if (i->second >= k){
            std::cout << "Yes";
            return 0;
        }
    }
    std::cout << "No";
    return 0;
}
