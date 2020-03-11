#include <bits/stdc++.h>
std::string I, P;
void solve(const int Il, const int Ir, const int Pl, const int Pr) {
    int pos = I.find(P[Pr]);
    std::cout << P[Pr];
    if (Il < pos) {
        solve(Il, pos - 1, Pl, pos - Il + Pl - 1);
    }
    if (pos < Ir) {
        solve(pos + 1, Ir, pos - Il + Pl, Pr - 1);
    }
}
int main() {
    using std::cin;
    cin >> I >> P;
    solve(0, I.size() - 1, 0, I.size() - 1);
    return 0;
}
