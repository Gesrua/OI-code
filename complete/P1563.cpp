#include <iostream>
#include <string>
using std::cin; using std::cout; using std::cerr; using std::endl; using std::min; using std::max;
int main(){
	int n, m, pos = 0, front[100010];
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	std::string name[100010];
	for (register int i = 0; i < n; ++i){
		cin >> front[i] >> name[i];
	}
	int right, opt;
	// cerr << endl;
	for (register int i = 0; i < m; ++i){
		// cerr << name[pos] << " pos = "<< pos << endl;
		cin >> right >> opt;
		if (front[pos] && right || !front[pos] && !right){
			pos -= opt;
		}else {
			pos += opt;
		}
		// if (front[pos] && right){
		//     // 朝外 右手
		//     pos -= opt;
		//     cerr << "i = " << i << " pos = " << pos << '\n';
		// }else{
		//     if (front[pos] && !right){
		//         // 朝外 左手
		//         pos += opt;
		//         cerr << "i = " << i << " pos = " << pos << '\n';
		//     }else{
		//         if (!front[pos] && right){
		//             // 朝内 右手
		//             pos += opt;
		//             cerr << "i = " << i << " pos = " << pos << '\n';
		//         }else{
		//             if (!front[pos] && !right){
		//                 // 朝内 左手
		//                 pos -= opt;
		//                 cerr << "i = " << i << " pos = " << pos << '\n';
		//
		//             }
		//         }
		//     }
		// }
		pos = (pos + n) % (n);
	}
	cout << name[pos];
	return 0;
}
