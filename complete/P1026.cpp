#include <iostream>
#include <string>
#include <cstring>
std::string a, tmp, key[6];
using std::cin;using std::cout;using std::cerr;using std::endl;
int p, s, k;
int value[202];
bool find(int pos, int n){
    if (pos+key[n].size() > a.size()) return false;
    for (register int i = 0; i < key[n].size(); ++i){
        if (a[i+pos] != key[n][i]) return false;
    }
    return true;
}
int main(){
    cin >> p >> k;
    --k;
    for (register int i = 1; i <= p; ++i){
        cin >> tmp;
        a += tmp;
    }
    cin >> s;
    for (register int i = 0; i < s; ++i){
        cin >> key[i];
    }


    // 计算若分割会损失的数量
    // 计算不分割时单词数量
    int flag, ans = 0;
    for (register int i = 0; i < a.size(); ++i){
        flag = -1;
        for (register int j = 0; j < s; ++j){
            if (find(i, j)){
                if (flag == -1){
                    flag = j;
                }else{
                    if (key[j].size() < key[flag].size()) flag = j;
                }
            }
        }
        if (flag != -1){
            ++ans;
            for (register int j = 1; j < key[flag].size(); ++j){
                ++value[i+j];
            }
        }
    }
    // cout << ans << endl;
    // for (int j = 0; j < a.size(); ++j){
    //     cout << value[j] << ' ';
    // }
    // cout << endl;

    if (k <= 0) {
        cout << ans;
        return 0;
    }
    register int i = -1;
    while(true){
        ++i;
        for (register int j = 1; j < a.size(); ++j){
            if (value[j] == i) {
                --k;
                ans-=i;
                // 若一个单词长度大于1 需除去 否则会重复计算
                for (int l = 0; l < s; ++l){
                    if (find(j, l)){
                        for (int r = 0; r < key[l].size(); ++r)
                            --value[j+r];
                    }
                }
            }
            if (k <= 0) {
                cout << ans;
                return 0;
            }
        }
    }
    return 0;
}