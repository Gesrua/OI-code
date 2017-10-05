#include <iostream>
#include <string>
using namespace std;
bool judge(string s)
{
    int length;
    length = s.length() - 1;
    for (int i=0; i<s.length(); i++)
    {
        if (s[i] != s[length - i])
        {
            return false;
        }
    }
    return true;
}
struct date
{
    int year,month,day;
};
bool run_year(int year)
{
    if ((year % 4 == 0 ) && (year % 100 != 0)) return true;
    if (year % 400 == 0) return true;
    return false;
}
int luck_year(int year)
{
    /*
       if ((year % 4 == 0 ) && (year % 100 != 0)) return true;
       if (year % 400 == 0) return true;
       return false;
     */
    while (true)
    {
        if (run_year(year)) return year;
        year++;
    }
}
int main()
{
    int a[13];
    a[1]=a[3]=a[5]=a[7]=a[8]=a[10]=a[12]=31;
    a[4]=a[6]=a[9]=a[11]=30;
    struct date start,end;
    int ans,last;
    string s1,s2;
    getline(cin,s1);
    start.year = (s1[0] - '0') * 1000 + (s1[1] - '0') * 100 + (s1[2] - '0') * 10+(s1[3] - '0');
    start.month = (s1[4] - '0') * 10 + (s1[5] - '0');
    start.day = (s1[6] - '0') * 10 + (s1[7] - '0');
    getline(cin,s2);
    end.year = (s2[0] - '0') * 1000 + (s2[1] - '0') * 100 + (s2[2] - '0') * 10+(s2[3] - '0');
    end.month = (s2[4] - '0') * 10 + (s2[5] - '0');
    end.day = (s2[6] - '0') * 10 + (s2[7] - '0');
    //cout<<start.year<<' '<<start.month<<' '<<start.day;
    //cout<<end.year<<' '<<end.month<<' '<<end.day;
    ans = judge(s2);
    last = luck_year(start.year);
    while (not ((start.year == end.year) && (start.month == end.month) && (start.day == end.day)))
    {
        //check当前start 跳到下一个
        //s1 = change(start);
        if (judge(s1)) ans++;
        a[2] = 28;
        if (last+4 == start.year)  {a[2] = 29; last = start.year; } //true 为闰年
        if (start.day != a[start.month])
        {
            start.day++;
            s1[7] = start.day % 10 + '0';
            if (start.day /10 != s1[6] - '0') s1[6] = start.day / 10 + '0';
        }
        else
        {
            start.day = 1;
            s1[6] = '0';
            s1[7] = '1';
            if (start.month != 12)
            {
                start.month++;
                if (start.month == 10)
                {
                    s1[4] = '1';
                    s1[5] = '0';
                }
                else
                {
                    s1[5] = start.month % 10 + '0';
                }
            }
            else
            {
                start.year++;
                /*
                   if (start.year % 1000)
                   {
                    s1[0] = start.year / 1000 + '0';
                    s1[1] = s1[2] = s1[3] = '0';
                   }
                   else if (start.year % 100)
                   {
                    s1[1] = start.year % 1000 / 100 + '0';
                    s1[2] = s1[3] = '0';
                   }
                   else if (start.year % 10)
                   {
                    s1[2] = start.year % 100 /10 + '0';
                    s1[3] = '0';
                   }
                   else s1[3] = start.year % 10 + '0';
                 */
                s1[0] = start.year / 1000 + '0';
                s1[1] = start.year % 1000 / 100 + '0';
                s1[2] = start.year % 100 /10 + '0';
                s1[3] = start.year % 10 + '0';
                start.month = 1;
                s1[4] = '0';
                s1[5] = '1';
            }
        }
    }
    // */
    //cout<<change(start)<<endl<<change(end);
    cout<<ans;
    return 0;
}
