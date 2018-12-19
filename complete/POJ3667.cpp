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

const int N = 50000;

int n;

int opt, x, d, L, R;

struct node{
	int llen, rlen, max, tag;
} T[N*4];

inline int dis(int x, int y) {
	return y-x+1;
}

void build(int idx, int l, int r){
	node& cur = T[idx];
	cur.llen = cur.rlen = cur.max = dis(l, r);
	if (l == r) return;
	int mid = l+r>>1, lson = idx*2, rson = idx*2+1;
	build(lson, l, mid);
	build(rson, mid+1, r);
}

void pushdown(int idx, int l, int r){
	// tag = -1 clear
	// tag = 0 no opt
	// tag = 1 add
	node& cur = T[idx];
	if (l == r || cur.tag == 0) return;
	int mid = l+r>>1;
	node &lson = T[idx*2], &rson = T[idx*2+1];
	if (cur.tag == -1){
		lson.llen = lson.rlen = lson.max = dis(l, mid);
		rson.llen = rson.rlen = rson.max = dis(mid+1, r);
		lson.tag = rson.tag = -1;
		cur.tag = 0;
	}else{
		lson.llen = lson.rlen = lson.max = 0;
		rson.llen = rson.rlen = rson.max = 0;
		lson.tag = rson.tag = 1;
		cur.tag = 0;
	}
}

void pushup(int idx, int l, int r){
	// tag = -1 clear
	// tag = 0 no opt
	// tag = 1 add
	if (l == r){
//		if (l >= L && l <= R){
//			cur.tag = 
//		}
		return;
	}
	node& cur = T[idx];
	node &lson = T[idx*2], &rson = T[idx*2+1];
	int mid = l+r>>1;
	cur.llen = lson.llen, cur.rlen = rson.rlen, cur.max = std::max(std::max(lson.max, rson.max), lson.rlen + rson.llen);
	if (lson.llen == dis(l, mid)) cur.llen = lson.llen + rson.llen;
	if (rson.rlen == dis(mid+1, r)) cur.rlen = rson.rlen + lson.rlen;
}

int query(int idx, int l, int r){
	if (l == r){
		return l;
	}
	pushdown(idx, l, r);
	node &lson = T[idx*2], &rson = T[idx*2+1];
	int mid = l+r>>1;
	if (lson.max >= d) return query(idx*2, l, mid);
	if (lson.rlen + rson.llen >= d){
		return mid - lson.rlen + 1;
	}
	return query(idx*2+1, mid+1, r);
}

void add(int idx, int l, int r){
	node& cur = T[idx];
	if (L <= l && r <= R){
		cur.tag = 1, cur.llen = cur.rlen = cur.max = 0;
		return;
	}
	if (r < L || R < l) return;
	pushdown(idx, l, r);
	int mid = l+r>>1;
	add(idx*2, l, mid); add(idx*2+1, mid+1, r);
	pushup(idx, l, r);
}

void clear(int idx, int l, int r){
	node& cur = T[idx];
	if (L <= l && r <= R){
		cur.tag = -1, cur.llen = cur.rlen = cur.max = dis(l, r);
		return;
	}
	if (r < L || R < l) return;
	pushdown(idx, l, r);
	int mid = l+r>>1;
	clear(idx*2, l, mid); clear(idx*2+1, mid+1, r);
	pushup(idx, l, r);
}

void out(int x){cerr << x << ' ';}

void print(int idx, int l, int r){
    out(l), out(r), out(T[idx].max);
    // out(idx), out(l), out(r), out(T[idx].llen), out(T[idx].rlen), out(T[idx].max), out(T[idx].tag);
    cerr << endl;
    if (l == r) return;
	int mid = l+r>>1;
    print(idx*2, l, mid), print(idx*2+1, mid+1, r);
}

int main(){
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    
	int m;
    cin >> n >> m;
	
	build(1, 1, n);
	
    while(m--){
    	cin >> opt;
    	if (opt == 1){
    		cin >> d;
    		if (T[1].max < d) cout << 0 << endl;
    		else{
    			x = query(1, 1, n);
    			cout << x << endl;
    			L = x, R = x + d - 1;
    			add(1, 1, n);
			}
		}else{
			cin >> x >> d;
			L = x, R = x + d - 1;
			clear(1, 1, n);
		}
        // print(1, 1, n);
	}
    return 0;
}