#include <cmath>
#include <iostream>
#include <map>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
int gcd(int a, int b) {
    while (b != 0) {
        int k = a;
        a = b;
        b = k % a;
    }
    return a;
}
int a[300009];
// int prime[1000009];
int map[15000009], divi[15000009];
// bool not_prime[15000009];
// std::map< int, int > map;
int main() {
    int n, great, tot = 0, maxn;
    divi[1] = 1;
    std::ios::sync_with_stdio(false);
    cin >> n;
    maxn = 15000000;
    for (register int i = 2; i <= maxn; ++i)
        if (!divi[i])
            for (register int j = i; j <= maxn; j += i) divi[j] = i;
    //	not_prime[1] = 1;
    //	for (int i = 2; i <= maxn; ++i){
    //		if (!not_prime[i]) prime[++tot] = i, divi[i] = i;
    //		for (int j = 1; j <= tot && i * prime[j] <= maxn; ++j){
    //			not_prime[i*prime[j]] = 1;
    //			divi[i*prime[j]] = prime[j];
    //			if (i%prime[j] == 0) break;
    //		}
    //	}
    //	for (int i = 1; i <= 100; ++i) cout << divi[i] << ' ';
    //	cout << tot << endl;
    cin >> a[1];
    great = a[1];
    for (register int i = 2; i <= n; ++i) {
        cin >> a[i];
        great = gcd(a[i], great);
    }
    for (register int i = 1; i <= n; ++i) {
        a[i] /= great;
        while (divi[a[i]] != 1) {
            map[divi[a[i]]]++;
            int ori = divi[a[i]];
            while (a[i] % ori == 0) a[i] /= ori;
        }
    }
    int ans = 0;
    for (auto i : map) {
        ans = std::max(ans, i);
    }
    if (ans == n || ans == 0) {
        cout << -1;
    } else {
        cout << n - ans;
    }
    return 0;
}
