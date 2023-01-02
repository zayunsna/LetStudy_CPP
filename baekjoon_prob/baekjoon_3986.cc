#include "/home/icegpu/HK/HKTool.h"
#include <ios>
using namespace std;

int n;
int ret = 0;
string str;


void baekjoon_3986(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> str;
		for(int j = 0; j < str.size(); ){
			char c = str[j];
			char c_n = str[j+1];
			//cout << j << "  " << j+1 << " will peak : " << c << " " << c_n << endl;
			if(c == c_n) {
				//cout << j << "  " << j+ 1 << " will removed : " << str.substr(j, 2) << endl;
				str.erase(j,2);
				j = 0;
			}
			else {
				j++;
				continue;
			}
			//cout << str << endl;
		}

		if( str.size() == 0) ret++;
	}

	cout << ret << "\n";

}
// Version 2 with using 'stack'
/*
void baekjoon_3986(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> str;

		stack<char> stk;
		for(char c : str){
			if(stk.size() && stk.top() == c) stk.pop();
			else stk.push(c);
		}
		if(stk.size() == 0) ret ++;
	}

	cout << ret << "\n";

}
*/
