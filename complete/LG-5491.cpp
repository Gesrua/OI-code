#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl; using std::make_pair; using std::pair;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull; typedef pair<int, int> pii;

ll n, p, a, w;

struct Num{
	ll x, y;
	Num operator*(const Num& rhs){
		Num ret;
		ret.x = (x * rhs.x % p + y * rhs.y % p * w % p) % p;
		ret.y = (x * rhs.y % p + y * rhs.x % p) % p;
		return ret;
	}
};

ll ksm(ll a, ll n){
	ll ret = 1;
	while(n){
		if (n&1) ret = ret*a%p;
		a = a*a%p;
		n >>= 1;
	}
	return (ret+p)%p;
}

Num ksm(Num a, ll n){
	Num ret = {1, 0};
		while(n){
		if (n&1) ret = ret*a;
		a = a*a;
		n >>= 1;
	}
	ret.x = (ret.x+p)%p;
	ret.y = (ret.y+p)%p;
	return ret;
}

ll euler_judge(ll a){
	return ksm(a, (p-1)/2);
}

std::pair<ll, ll> solve(){
	if (n%p == 0) return {0, 0};
	if (euler_judge(n) == p-1) return {-1, -1};
	while(1){
		a = rand() % p;
		w = (a*a-n)%p;
		if (euler_judge(w) == p-1) break;
	}
	Num x = {a, 1};
	ll ans1 = ksm(x, (p+1)/2).x;
	ll ans2 = p-ans1;
	return {std::min(ans1, ans2), std::max(ans1, ans2)};
}

int main() {
	std::ios::sync_with_stdio(false);
	cout.tie(0);
	int T; cin >> T;
	while(T--){
		cin >> n >> p;
		auto ret = solve();
		if (ret.first == -1) cout << "Hola!\n";
		else if (ret.first == ret.second) cout << ret.first << '\n';
		else cout << ret.first << ' ' << ret.second << '\n';
	}
	return 0;
}