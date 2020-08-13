#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cerr; using std::cin; using std::cout; using std::endl; using std::make_pair; using std::pair;
typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull; typedef pair<int, int> pii; 

namespace AC {

int tr[int(2e4)][26], cnt[int(2e4)], res[160], fail[int(2e4)], tot = 1;
std::vector<int> idx[int(2e4)];

void insert(char* s, int id){
    int u = 0;
    for(int i = 0; s[i]; ++i){
        if (tr[u][s[i]-'a'] == 0) tr[u][s[i]-'a'] = tot++;
        u = tr[u][s[i]-'a'];
    }
    idx[u].push_back(id);
}

void build(){
    std::queue<int> q;
    rep(i, 0, 25) if (tr[0][i]) q.push(tr[0][i]);
    while(q.size()){
        int u = q.front(); q.pop();
        rep(i, 0, 25){
            if (tr[u][i]){
                fail[tr[u][i]] = tr[fail[u]][i];
                q.push(tr[u][i]);
            } else {
                tr[u][i] = tr[fail[u]][i];
            }
        }
    }
}

void query(char* s){
    int u = 0;
    for(int i = 0; s[i]; ++i){
        u = tr[u][s[i]-'a'];
        for(int j = u; j; j = fail[j])
            cnt[j]++;
    }
    for(int i = 0; i < tot; ++i){
        if (cnt[i] && idx[i].size())
            for(int id : idx[i])
                res[id] += cnt[i];
    }
}

void clear(){
    std::memset(tr, 0, sizeof(tr));
    std::memset(cnt, 0, sizeof(cnt));
    std::memset(fail, 0, sizeof(fail));
    std::memset(res, 0, sizeof(res));
    tot = 1;
    for(auto& i : idx) i.clear();
}

}

char s[int(1e6+10)], p[152][75];

int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int N;
    while(cin >> N){
        AC::clear();
        if (N == 0) return 0;
        rep(i, 1, N){
            cin >> p[i];
            AC::insert(p[i], i);
        }
        AC::build();
        cin >> s;
        AC::query(s);
        int mx = 0;
        rep(i, 1, N) mx = std::max(mx, AC::res[i]);
        cout << mx << endl;
        rep(i, 1, N)
            if (AC::res[i] == mx)
                cout << p[i] << endl;
    }
    return 0;
}