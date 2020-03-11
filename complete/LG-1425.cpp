#include <iostream>
struct time {
    int h, m;
};
int main() {
    struct time start, end;
    std::cin >> start.h >> start.m >> end.h >> end.m;
    if (start.m > end.m) {
        end.h--;
        end.m += 60;
    }
    std::cout << end.h - start.h << ' ' << end.m - start.m;
    return 0;
}
