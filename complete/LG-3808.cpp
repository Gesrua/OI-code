#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
#define R(i, n) for (int i = 0; i < n; ++i)
using std::cerr; using std::cin; using std::cout; using std::endl; using std::make_pair; using std::pair;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull; typedef pair<int, int> pii; 

int tr[int(2e6)][26], fail[int(2e6)], end[int(2e6)], rt = 0, tot = 1;
char s[int(1e6+10)];

void insert(char* s, int n){
    int u = rt;
    R(i, n){
        if (tr[u][s[i]] == 0) tr[u][s[i]] = tot++;
        u = tr[u][s[i]];
    }
    end[u]++;
}

void build(){
    std::queue<int> q;
    R(i, 26) if (tr[rt][i]) q.push(tr[rt][i]);
    while(q.size()){
        int u = q.front(); q.pop();
        R(i, 26){
            if (tr[u][i]){
                fail[tr[u][i]] = tr[fail[u]][i];
                q.push(tr[u][i]);
            } else {
                tr[u][i] = tr[fail[u]][i];
            }
        }
    }
}

int query(char s[], int n){
    int res = 0;
    int u = 0;
    R(i, n){
        u = tr[u][s[i]];
        for(int j = u; j && end[j] != -1; j = fail[j]){
            res += end[j];
            end[j] = -1;
        }
    }
    return res;
}

int read_str(char* s){
    cin >> s;
    int n = strlen(s);
    std::for_each(s, s+n, [](char& x){ x -= 'a'; });
    return n;
}

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int T; cin >> T;
    rep(i, 1, T){
        int n = read_str(s);
        insert(s, n);
    }
    build();
    int n = read_str(s);
    cout << query(s, n) << endl;
    return 0;
}