#include <iostream>
#include <cmath>
#include <ctime>
#include <set>
std::set<int> flag;
using std::cin; using std::cout; using std::cerr; using std::endl; using std::sqrt; using std::floor;
// bool flag[1000000001];
int main(){
    int st, n, pos = 1, lim, dir = 1 , s = std::clock();
    double t;
    cin >> n;
    lim = sqrt(n);
    st = 1;
    if (n >= 1000000000){
        st = 1000000000;
        pos = 1005;
        dir = -1;
    }
    else if (n >= 950000000){
        st = 950000000;
        pos = 4;
        dir = 1;
    }
    else if (n >= 900000000){
        st = 900000000;
        pos = 1005;
        dir = 1;
    }
    else if (n >= 850000000){
        st = 850000000;
        pos = 1005;
        dir = -1;
    }
    else if (n >= 800000000){
        st = 800000000;
        pos = 2;
        dir = 1;
    }
    else if (n >= 750000000){
        st = 750000000;
        pos = 1007;
        dir = -1;
    }
    else if (n >= 700000000){
        st = 700000000;
        pos = 1001;
        dir = -1;
    }
    else if (n >= 650000000){
        st = 650000000;
        pos = 1003;
        dir = -1;
    }
    else if (n >= 600000000){
        st = 600000000;
        pos = 4;
        dir = 1;
    }
    else if (n >= 550000000){
        st = 550000000;
        pos = 1005;
        dir = 1;
    }
    else if (n >= 500000000){
        st = 500000000;
        pos = 1005;
        dir = -1;
    }
    else if (n >= 450000000){
        st = 450000000;
        pos = 2;
        dir = -1;
    }
    else if (n >= 400000000){
        st = 400000000;
        pos = 1007;
        dir = -1;
    }
    else if (n >= 350000000){
       st = 350000000;
       pos = 1007;
       dir = -1;
   }
    else if (n >= 300000000){
        st = 300000000;
        pos = 1007;
        dir = 1;
    }
    else if (n >= 250000000){
        st = 250000000;
        pos = 4;
        dir = 1;
    }
    else if (n >= 200000000){
        st = 200000000;
        pos = 1005;
        dir = 1;
    }
    else if (n >= 150000000){
        st = 150000000;
        pos = 1005;
        dir = -1;
    }
    else if (n >= 100000000){
        st = 100000000;
        pos = 2;
        dir = -1;
    }
    else if (n >= 90000000){
        st = 90000000;
        pos = 1007;
        dir = -1;
    }
    else if (n >= 80000000){
        st = 80000000;
        pos = 1005;
        dir = 1;
    }
    else if (n >= 70000000){
        st = 70000000;
        pos = 6;
        dir = 1;
    }
    else if (n >= 60000000){
        st = 60000000;
        pos = 1007;
        dir = -1;
    }
    else if (n >= 50000000){
        st = 50000000;
        pos = 1003;
        dir = 1;
    }
    else if (n >= 30000000){
        st = 30000000;
        pos = 2;
        dir = -1;
    }
    else if (n >= 10000000){
        st = 10000000;
        pos = 1005;
        dir = 1;
    }
    // t = sqrt(st);
    // for (register int i = t; i <= lim; ++i){
    //     flag.insert(i*i);
    //     // flag[i*i] = true;
    // }
    // // lim = n / 7 + 1;
    // for (register int i = 0; i <= n; i+=7){
    //     flag[i] = true;
    // }
    // cerr << "over";
    for (register int i = st; i < n; ++i){
        // cerr << "i = " << i << " pos = " << pos << " dir = " << dir << endl;

        t = sqrt(i);
        if (t == floor(t) || i%7 == 0){
        // if (flag.count(i) || i%7 == 0){
            dir = -dir;
        }
        pos += dir;
        if (pos == 0) pos = 1007;
        else if (pos == 1008) pos = 1;
        // cout << pos << ' ';
        // if (pos == 1 && dir == 1){
        //     cout << "i = " << i+1 << endl;;
        // }
    }
    cout << pos;
    // cout << pos << ' ' << dir << endl;
    // cout << (std::clock()-double(s))/CLOCKS_PER_SEC;
    return 0;
}
