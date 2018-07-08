#include <iostream>
#include <random>
#include <algorithm>
#include <ctime>
using std::sort; using std::cin; using std::cout; using std::cerr; using std::endl; using std::min; using std::max;
bool hang[10][10] = {};
const int score[10][10] =
{
	{6,6,6,6,6,6,6,6,6},
	{6,7,7,7,7,7,7,7,6},
	{6,7,8,8,8,8,8,7,6},
	{6,7,8,9,9,9,8,7,6},
	{6,7,8,9,10,9,8,7,6},
	{6,7,8,9,9,9,8,7,6},
	{6,7,8,8,8,8,8,7,6},
	{6,7,7,7,7,7,7,7,6},
	{6,6,6,6,6,6,6,6,6}};
int a[10][10] = {}, ans;
bool lie[10][10] = {};
bool block[10][10] = {};
struct node {
	int num, hang;
	bool operator< (const node x){
		return this->num < x.num;
	}
} first[10];
inline bool canFill(int i, int j, int k){
	if (hang[i][k] || lie[j][k] || block[j / 3 + 1 + ((i / 3) * 3)][k]){
		return false;
	}
	return true;
}
inline void unFill(int i, int j, int k){
	a[i][j] = 0;
	hang[i][k] = false;
	lie[j][k] = false;
	block[j / 3 + 1 + ((i / 3) * 3)][k] = false;
}
inline void Fill(int i, int j, int k){
	a[i][j] = k;
	hang[i][k] = true;
	lie[j][k] = true;
	block[j / 3 + 1 + ((i / 3) * 3)][k] = true;
}
void print(){
	cout << endl;
	for (int i = 0; i < 9; ++i){
		for (int j = 0; j < 9; ++j)
			cout << a[i][j] << ' ';
		// cout << endl;
	}
	cout << endl;
}
int calc(){
	int x = 0;
	for (int i = 0; i < 9; ++i){
		for (int j = 0; j < 9; ++j){
			x += a[i][j] * score[i][j];
		}
	}
	return x;
}
void solve(int s){
	int i, j, k, l;
	for (l = s; l < 9; ++l){
		i = first[l].hang;
		for (j = 0; j < 9; ++j){
			if (a[i][j] == 0){
				for (k = 1; k <= 9; ++k){
					if (canFill(i, j, k)){
						Fill(i, j, k);
						solve(l);
						unFill(i, j, k);
					}
				}
				return;
			}
		}
	}
	ans = max(ans, calc());
	// print();
}
int main(){
	std::ios::sync_with_stdio(false);
	for (int i = 0; i < 9; ++i){
		first[i].hang = i;
		for (int j = 0; j < 9; ++j){
			cin >> a[i][j];
			if (a[i][j] == 0) ++first[i].num;
			Fill(i, j, a[i][j]);
		}
	}
	// std::srand(std::clock());
	sort(first, first + 9);
	// for (int i = 0; i < 5; ++i){
	// std::swap(first[std::rand()%9], first[std::rand()%9]);
	// }
	ans = -1;
	solve(0);
	cout << ans;
	return 0;
}