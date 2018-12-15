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
#include <stack>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cin; using std::cout; using std::cerr; using std::endl;
using std::make_pair; using std::pair;
typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned int ui;
using std::sort;
const int N = 100090, K = 200090;

int cnt[N];

struct Point{
    int id, x, y, z, w;
    int ans;
    bool operator ==(Point& b){
        return x==b.x&&y==b.y&&z==b.z;
    }
}p[N], cut;
bool cmp_x(Point& a, Point& b){
    if (a.x != b.x) return a.x < b.x;
    if (a.y != b.y) return a.y < b.y;
    return a.z < b.z;
}

// bool cmp_x(Point& a, Point& b){ return a.x==b.x?(a.y==b.y?a.z<b.z:a.y<b.y):(a.x < b.x); }

bool cmp_y(Point& a, Point& b){ return a.y < b.y; }

bool cmp_id(Point& a, Point& b){ return a.id < b.id; }

int n;

struct BIT{
    int c[K], n;
    int lowbit(int x){return x&-x;}
    void add(int pos, int x){
        for (int i = pos; i <= n; i += lowbit(i))
            c[i] += x;
    }
    int sum(int n){
        ui ret = 0;
        for (int i = n; i > 0; i -= lowbit(i))
            ret += c[i];
        return ret;
    }
}bit;

void solve(int l, int r){
    if (l == r) return;
    int mid = l+r>>1;
    solve(l, mid); solve(mid+1, r);
    sort(p+l, p+mid+1, cmp_y); // [l, mid+1) [l, mid]
    sort(p+mid+1, p+r+1, cmp_y); // [mid+1, r+1) [mid+1, r]
    int i = l;
    rep(j, mid+1, r){
        while(i <= mid && p[i].y <= p[j].y){
            bit.add(p[i].z, p[i].w);
            ++i;
        }
        p[j].ans += bit.sum(p[j].z);
    }
    rep(k, l, i-1){
        bit.add(p[k].z, -p[k].w);
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin >> n >> bit.n;
    rep(i, 1, n){
        p[i].id = i, p[i].w = 1;
        cin >> p[i].x >> p[i].y >> p[i].z;
    }
    sort(p+1, p+1+n, cmp_x);
    int i = 0, out;
    rep(j, 1, n){
        if(p[i] == p[j]) p[i].w++;
        else p[++i] = p[j];
    }
    out = n;
    n = i;
    // cerr << "solving " << n << endl;
    solve(1, n);
    rep(i, 1, n){
        cnt[p[i].ans+p[i].w-1] += p[i].w;
    }
    rep(i, 0, out-1) cout << cnt[i] << endl;
    return 0;
}