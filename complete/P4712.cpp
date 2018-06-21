#include <iostream>
#include <iomanip>
#include <cmath>
using std::cin;using std::cout;using std::cerr;using std::endl;using std::abs;
int n, a, r;
long double e[100010];
inline bool isequal(double a, double b){
    if (abs(a-b) <= 1e-5) return true;
    return false;
}
int main(){
    int n, s = 0;
    std::ios::sync_with_stdio(false);
    cin >> n >> e[0];
    register int i, j;
    for (i = 1; i <= n; ++i){
        cin >> a >> r;
        for (j = s; j <= r; ++j){
            if (isequal(e[j], 0)) ++s;
            if (e[i]+e[j]/5.0 >= a){
                e[j] -= (a-e[i])*5;
                if (e[j] < 1e-6) e[j] = 0;
                e[i] = a;
                break;
            }else{
                e[i] += e[j]/5.0;
                e[j] = 0;
            }
        }
        if (!isequal(a,e[i])){
            cout << "-1";
            return 0;
        }

    }
    double ans = 0;
    for (i = s; i <= n; ++i){
        ans += e[i]/5.0;
    }

    if (ans < 1e-5){
        cout << "-1";
        return 0;
    }

    cout.setf(std::ios::fixed);

    cout << ans;
    
    return 0;
}