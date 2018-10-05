#include <cstdio>
#include <iostream>
#include <utility>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#define rep(i, l, r) for (register int i = (l); i <= (r); ++i)
#define per(i, l, r) for (register int i = (l); i >= (r); --i)
using std::cin; using std::cout; using std::cerr; using std::endl;
using std::make_pair; using std::pair;
typedef pair< int, int > pii;
int add[50], sum[50];
int main(){
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int clr, cost, n, k, p;
    cin >> n >> k >> p;
    long long ans = 0;
    rep(i, 1, n){
        cin >> clr >> cost;
        if (cost <= p){
            ans += sum[clr];
            ++sum[clr];
            rep (j, 0, k-1) add[j] = sum[j];
        }else{
            ans += add[clr];
            ++sum[clr];
        }
    }
    cout << ans;
    return 0;
}