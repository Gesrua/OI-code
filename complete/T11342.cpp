#include <cstdio>
#include <iostream>
#include <queue>
using std::scanf;
int a, b, c, m;
std::priority_queue<int, std::vector<int>, std::greater<int> > su, hun;
int main(){
    scanf("%d%d%d", &a, &b, &c);
    scanf("%d", &m);
    int t;
    long long ans=0, cost=0;
    char t2;
    for(int i=0;i<m;++i){
        std::cin >> t >> t2;
        if (t2 == 'A'){
            su.push(t);
        }
        if (t2 == 'B'){
            hun.push(t);
        }
    }
    while (true){
        //std::cerr << a << ' ' << b << ' ' << c << std::endl;
        if (su.empty() && hun.empty()) break;
        if (a<=0 && b<=0 && c<=0) break;
        if (su.empty()) a = 0;
        if (hun.empty()) b = 0;
        if (a>0 && !su.empty()){
            --a;++ans;cost+=su.top();su.pop();
            continue;
        }
        if (b>0 && !hun.empty()){
            --b;++ans;cost+=hun.top();hun.pop();
            continue;
        }
        if (c>0){
            if (!su.empty() && !hun.empty()){
                if (su.top()<hun.top()){
                    --c;++ans;cost+=su.top();su.pop();
                    continue;
                }else{
                    --c;++ans;cost+=hun.top();hun.pop();
                    continue;
                }
            }
            if (hun.empty()){
                --c;++ans;cost+=su.top();su.pop();
                continue;
            }
            if (su.empty()){
                --c;++ans;cost+=hun.top();hun.pop();
                continue;
            }
        }
    }
    //std::printf("%d %d", ans, cost);
    std::cout << ans << ' ' << cost;
    return 0;
}
