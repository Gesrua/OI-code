#include <bits/stdc++.h>
std::map<char, char> map;
std::map<char, bool> book;
int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    std::string s;
    std::ios::sync_with_stdio(false);
    cin >> s;
    unsigned int i, tot = 0;
    char c;
    for (i = 0; i < s.size(); ++i) {
        cin >> c;
        if (map.count(s[i]) == 0) {
            map.insert(std::make_pair(s[i], c));
            ++tot;
        } else if (map[s[i]] != c) {
            cout << "Failed";
            return 0;
        }
    }
    for (i = 0; i < 26; ++i) {
        if (book.count(map[char(i + 'A')]) != 0) {
            cout << "Failed";
            return 0;
        }
        book[map[char(i + 'A')]] = true;
    }
    if (tot < 26) {
        cout << "Failed";
        return 0;
    }
    cin >> s;
    for (i = 0; i < s.size(); ++i) cout << map[s[i]];
    return 0;
}