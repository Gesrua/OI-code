#include <iostream>
using std::cin;
using std::cout;
struct node {
    long long x, y, hp;
} a[3];
int type, obj;
long long n, k, x, y;
inline bool check(int x) {
    if (x < 1 || x > n) return false;
    return true;
}
int main() {
    cin >> n >> k;
    cin >> a[1].x >> a[1].y >> a[2].x >> a[2].y;
    a[1].hp = a[2].hp = 10;
    k = 1;
    while (cin >> type) {
        cin >> obj;
        if (!(check(a[obj].x) && check(a[obj].y)) || a[obj].hp < 0) {
            cout << k;
            return 0;
        }
        if (type == 1) {
            cin >> a[obj].x >> a[obj].y;
        }
        if (type == 2) {
            cin >> x;
            if (obj == 1)
                obj = 2;
            else
                obj = 1;
            a[obj].hp -= x;
        }
        if (a[1].x == a[2].x && a[1].y == a[2].y) {
            cout << k;
            return 0;
        }
        // std::cerr << a[1].x << ' ' << a[1].y << '/' << a[2].x << ' ' <<
        // a[2].y;
        ++k;
    }
    cout << a[1].hp << ' ' << a[2].hp;
    return 0;
}