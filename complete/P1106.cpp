#include <iostream>
#include <string>
using namespace std;
string s;
int n;
int main()
{
    getline(cin,s);
    int cur=0,i;
    cin>>n;
    while (cur!=n)
    {
        i = 0;
        for (i=0; i<s.length(); i++)
            if (s[i]>s[i+1])
            {
                s.erase(i,1);
                break;
            }
        cur++;
    }
    while (s[0]=='0') s.erase(0,1);
    for (i=0; i<s.length(); i++) cout<<s[i];
    return 0;
}
