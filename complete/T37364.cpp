#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
bool book[110][110][110] = {}, ans[200];
int va, vb, vc;
void dfs(int a, int b, int c) {
    if (book[a][b][c]) return;
    if (a == 0) ans[c] = true;
    book[a][b][c] = true;
    if (a > 0) {
        if (a + c > vc)
            dfs(a + c - vc, b, vc);
        else
            dfs(0, b, a + c);
        if (a + b > vb)
            dfs(a + b - vb, vb, c);
        else
            dfs(0, a + b, c);
    }
    if (b > 0) {
        if (b + a > va)
            dfs(va, a + b - va, c);
        else
            dfs(a + b, 0, c);
        if (b + c > vc)
            dfs(a, b + c - vc, vc);
        else
            dfs(a, 0, b + c);
    }
    if (c > 0) {
        if (c + a > va)
            dfs(va, b, a + c - va);
        else
            dfs(a + c, b, 0);
        if (c + b > vb)
            dfs(a, vb, b + c - vb);
        else
            dfs(a, c + b, 0);
    }
}
int main() {
    cin >> va >> vb >> vc;
    dfs(0, 0, vc);
    for (int i = 0; i <= 150; ++i)
        if (ans[i]) cout << i << ' ';
    return 0;
}