#include <bits/stdc++.h>
int main() {
    std::string c, s, t, a, b, rule[6][2];
    std::map<std::string, int> book;
    std::cin >> a >> b;
    int i = 0, n, pos;
    while (std::cin >> rule[i][0] >> rule[i][1]) i++;
    n = i;
    std::queue<std::string> q;
    std::queue<int> ans;
    q.push(a);
    book[a] = 1;
    ans.push(0);
    while ((!q.empty()) && (ans.front() < 11)) {
        if (q.front() == b) {
            std::cout << ans.front();
            return 0;
        }
        for (i = 0; i < n; i++) {
            t = q.front();
            pos = t.find(rule[i][0], 0);
            while ((pos >= 0) && (pos <= t.size())) {
                t.replace(pos, rule[i][0].size(), rule[i][1]);
                if (book[t] != 1) {
                    q.push(t);
                    ans.push(ans.front() + 1);
                    book[t] = 1;
                }
                t = q.front();
                pos = t.find(rule[i][0], pos + 1);
            }
        }
        q.pop();
        ans.pop();
    }
    std::cout << "NO ANSWER!";
    return 0;
}
