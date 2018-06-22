#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	//bool flag = false;
	double now = 0,speed = 7;
	int time = 0;
	int s,x,start,end;
	cin >> s >> x;
	start = s - x;
	end = s + x;
	while (now < start)
	{
		time++;
		now = now + speed;
		speed = 0.98 * speed;
	}
	if (now + speed <= end) cout << 'y';
	else cout << 'n';
	return 0;
}
